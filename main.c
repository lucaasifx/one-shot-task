#include <stdio.h>
#include "pico/stdlib.h" 
#include "pico/time.h"

const uint BLUE = 12;    
const uint RED = 13;    
const uint GREEN = 11;    
const uint BUTTON_PIN = 5;
bool is_running = false;

// Função de callback para desligar o LED verde após o tempo programado.
int64_t desligar_verde(alarm_id_t id, void *user_data) {
    gpio_put(GREEN, false);
    return 0;
}

// Função de callback para desligar o LED azul após o tempo programado.
int64_t desligar_azul(alarm_id_t id, void *user_data) {
    gpio_put(BLUE, false);
    return 0;
}

// Função de callback para desligar o LED vermelho após o tempo programado.
int64_t desligar_vermelho(alarm_id_t id, void *user_data) {
    gpio_put(RED, false);
    is_running = false; // A execução está finalizada.
    return 0;
}

void init_led(uint8_t ledGPIO) {
    gpio_init(ledGPIO);
    gpio_set_dir(ledGPIO, GPIO_OUT);
}

void init_button(uint8_t buttonGPIO) {
    gpio_init(buttonGPIO);
    gpio_set_dir(buttonGPIO, GPIO_IN);
    gpio_pull_up(buttonGPIO);
}

void desligar_leds(){
    // Agenda o desligamento dos LEDs após o tempo especificado.
        // segundo ciclo
    add_alarm_in_ms(3000, desligar_verde, NULL, false);
        // terceiro ciclo
    add_alarm_in_ms(6000, desligar_azul, NULL, false);
        // quarto ciclo
    add_alarm_in_ms(9000, desligar_vermelho, NULL, false);
}

int main() {
    stdio_init_all();

    // Configura os pinos dos LEDs como saída.
    init_led(BLUE);
    init_led(RED);
    init_led(GREEN);

    init_button(BUTTON_PIN);

    while (true) {
        // Verifica se o botão foi pressionado.
        if (gpio_get(BUTTON_PIN) == 0 && !is_running) {
            sleep_ms(50); // Debounce

            // Verifica novamente o estado do botão após o debounce.
            if (gpio_get(BUTTON_PIN) == 0 && !is_running) {
                is_running = true;
                // Acende os LEDs.
                gpio_put(RED, true);
                gpio_put(GREEN, true);
                gpio_put(BLUE, true);

                desligar_leds();
            }
        }

        sleep_ms(10); // Reduz o uso da CPU.
    }

    return 0; // Este código nunca será alcançado.
}