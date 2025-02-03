# 📌 Controle de Matriz de LEDs WS2812 com Interrupções e Debouncing

## 📖 Descrição do Projeto
Este projeto tem como objetivo consolidar o uso de temporizações one shot por meio do acionamento de LEDs a partir do clique em um botão (pushbutton). 
O software foi projetado para ser compatível com o simulador **Wokwi** e com a placa BitDogLab.
### 🎯 Objetivos do Projeto:
- Implementar um sistema de temporização de um disparo utilizando add_alarm_in_ms().

- Acionar três LEDs (azul, vermelho e verde) com diferentes estados após pressionamento do botão.

- Implementar um sistema de debouncing via software para garantir leituras precisas do botão (opcional).

- Criar um sistema eficiente combinando hardware e software.

---

## 🛠 Componentes Utilizados
- **Placa BitDogLab (RP2040)**
- **LED RGB** conectado às **GPIOs 11, 12 e 13**
- **Botão A** (GPIO 5)
---

## 🔧 Funcionalidades Implementadas
1. Pressionamento do botão aciona todos os LEDs simultaneamente.

2. Após 3 segundos, um dos LEDs é desligado.

3. Após mais 3 segundos, outro LED é desligado.

4. Após mais 3 segundos, o último LED é desligado.

5. O botão só pode ser pressionado novamente quando todos os LEDs estiverem apagados.

6. Implementação eficiente com temporizadores evitando polling contínuo.

7. Implementação de software debounce para evitar múltiplos acionamentos indesejados.



---

## 🚀 Como Executar o Projeto
1. Clone este repositório:
   
```bash
   git clone https://github.com/lucaasifx/one-shot-task.git
```


2. Abra o projeto no VS Code.

3. Certifique-se de que a extensão **Raspberry Pi Pico** e  **Wokwi** estão instaladas e configuradas corretamente.
4. Clique no ícone da extensão da Pico<br>
  ![image](https://github.com/user-attachments/assets/28cdb91b-16e2-4687-a6a1-950f219ddf34)
5. Selecione importar projeto para que a pasta build seja gerada automaticamente:<br>
![image](https://github.com/user-attachments/assets/b0dc78cd-f619-4648-9b5b-d509c65800d7)
  - Selecione o caminho do projeto e clique em Import: <br>
![image](https://github.com/user-attachments/assets/9abe1447-0f62-4b30-a70c-5b342020d3a6)


6. Navegue até a opção Compilar Projeto:<br>
![image](https://github.com/user-attachments/assets/366a506d-171c-4c30-9577-e61d1575da33)

7. Se desejar testar no simulador, abra o arquivo diagram.json e inicie a simulação. <br>
![image](https://github.com/user-attachments/assets/d1fad713-31b0-4fc0-9ac7-51100ca640f1)


---

## 📹 Demonstração em Vídeo
📺 **Veja o projeto em ação**:

🔗 [Vídeo de demonstração no hardware](https://www.youtube.com/)

---

