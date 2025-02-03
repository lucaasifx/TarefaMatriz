# 📌 Controle de Matriz de LEDs WS2812 com Interrupções e Debouncing

## 📖 Descrição do Projeto
Este projeto tem como objetivo consolidar o uso de **interrupções** e **debouncing via software** em microcontroladores **RP2040**, utilizando a placa **BitDogLab**. O sistema controla uma matriz de LEDs **WS2812 5x5**, um **LED RGB** e botões, proporcionando uma interface interativa para exibição de números.
### 🎯 Objetivos do Projeto:
- Utilizar **interrupções** para capturar eventos dos botões, evitando polling.
- Implementar **debouncing via software** para garantir leituras mais precisas.
- Controlar um **LED RGB** e uma **matriz WS2812** para exibir números de **0 a 9**.
- Criar um sistema eficiente combinando **hardware e software**.

---

## 🛠 Componentes Utilizados
- **Placa BitDogLab (RP2040)**
- **Matriz WS2812 (5x5)** conectada à **GPIO 7**
- **LED RGB** conectado às **GPIOs 11, 12 e 13**
- **Botão A** (GPIO 5)
- **Botão B** (GPIO 6)
- **Botão JOYSTICK_PUSH_BUTTON** (GPIO 22)
---

## 🔧 Funcionalidades Implementadas
1. **Piscar o LED vermelho** do LED RGB **5 vezes por segundo**.
2. **Botão A** incrementa o número exibido na matriz de LEDs.
3. **Botão B** decrementa o número exibido na matriz de LEDs.
4. **Matriz WS2812** exibe os números **de 0 a 9** com formatação fixa.
5. **Debouncing via software** para garantir leituras mais precisas dos botões.
6. **Interrupção (IRQ) nos botões**, evitando sobrecarga da CPU com polling.
7. **Botão JOYSTICK_PUSH_BUTTON** habilita o modo BOOTSELL via software.

---

## Estrutura do Projeto
O projeto foi desenvolvido em C e utiliza o simulador **Wokwi** para emular o circuito. A estrutura de diretórios é organizada para facilitar o desenvolvimento e a compilação com a extensão **Raspberry Pi Pico** no VS Code.

### Diretórios Principais
- src/: Contém o arquivo principal do código-fonte (main.c).
- src/lib/: Contém os arquivos de cabeçalho (.h) das bibliotecas implementadas e as suas respectivas implementações.
- wokwi/: Contém o arquivo de simulação do circuito Wokwi (diagram.json e wokwi.toml)

## 🚀 Como Executar o Projeto
1. Clone este repositório:
   
```bash
   git clone https://github.com/lucaasifx/TarefaMatriz.git
```


2. Abra o projeto no VS Code.

3. Certifique-se de que a extensão **Raspberry Pi Pico** e  **Wokwi** estão instaladas e configuradas corretamente.
4. Clique no ícone da extensão da Pico<br>
  ![image](https://github.com/user-attachments/assets/28cdb91b-16e2-4687-a6a1-950f219ddf34)
5. Selecione importar projeto para que a pasta build seja gerada automaticamente:<br>
![image](https://github.com/user-attachments/assets/b0dc78cd-f619-4648-9b5b-d509c65800d7)
  - Selecione o caminho do projeto e clique em Import<br>
![image](https://github.com/user-attachments/assets/9abe1447-0f62-4b30-a70c-5b342020d3a6)


6. Navegue até a opção Compilar Projeto:<br>
![image](https://github.com/user-attachments/assets/366a506d-171c-4c30-9577-e61d1575da33)

7. Se desejar testar no simulador, abra o arquivo diagram.json e inicie a simulação. <br>
![image](https://github.com/user-attachments/assets/74f93e0f-bda4-487b-b043-457b31539876)

---

## 📹 Demonstração em Vídeo
📺 **Veja o projeto em ação**:

🔗 [Vídeo da execução no hardware](https://www.youtube.com/)

---

