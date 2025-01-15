# Sistema de Alimentação Automática de Animais com Arduino

Este projeto utiliza um Arduino para controlar um sistema de alimentação automática de animais. Um display LCD exibe o tempo restante até a próxima refeição, e um servo motor é usado para abrir o compartimento de ração quando o tempo termina. O sistema também possui uma funcionalidade de reinicialização para garantir o funcionamento contínuo.

Para me aprofundar nos recursos nativos do Arduino, neste projeto tomei como desafio pessoal fazer o relógio regressivo ser implementado sem o uso de bibliotecas externas para controle de tempo. Ele utiliza o contador de tempo de execução interno do Arduino (`millis()`) para realizar a contagem regressiva com precisão de alguns segundos. 

---

## Componentes Utilizados

- **Arduino Uno** (ou similar)
- **Display LCD com módulo I2C** (endereço padrão: 0x27)
- **Servo Motor** (para abrir o compartimento de ração)
- **Porta Reset do Arduino** (nesse projeto, forçamos o reset do Arduino ligando pela porta RESET)
- **Jumpers** para conexões

---

## Funcionalidades

1. **Contagem regressiva para alimentação**:
   - Inicializa o tempo em 23 horas, 59 minutos e 59 segundos.
   - Reduz o tempo em intervalos de 1 segundo.
   - Exibe o tempo restante no display LCD.

2. **Abertura do compartimento de ração**:
   - Quando o tempo chega a 00:00:00, o servo motor gira para liberar a ração.
   - O display LCD é desligado para indicar a ação e consumir menos energia.

3. **Reinicialização automática**:
   - Após liberar a ração, o sistema reinicia o Arduino para zerar o tempo de execução interno.
   - Caso o reset falhe, uma mensagem de erro é exibida no display LCD.

---

## Configuração do Hardware

1. **Conexão do LCD**:
   - SDA -> A4 (Arduino Uno)
   - SCL -> A5 (Arduino Uno)
   - VCC -> 5V
   - GND -> GND

2. **Conexão do Servo Motor**:
   - Sinal -> Pino 11
   - VCC -> 5V
   - GND -> GND

---

## Como Usar

1. Faça o upload do código para o Arduino utilizando a IDE Arduino.
2. Conecte todos os componentes conforme o diagrama descrito acima.
3. Ligue o Arduino e observe o display LCD. O tempo restante até a próxima refeição será exibido.
4. Ao final da contagem regressiva, o servo motor abrirá o compartimento de ração para alimentar os animais.

---

## Personalizações

- **Tempo Inicial**: Altere os valores das variáveis `hours`, `minutes` e `seconds` no início do código para ajustar o intervalo entre as refeições.
- **Movimento do Servo Motor**: Ajuste os delays e os ângulos na função `open_gate` para adaptar o sistema ao seu compartimento de ração.
- **Endereço do LCD**: Caso seu display use outro endereço, altere `0x27` na linha `LiquidCrystal_I2C lcd(0x27,16,2);`.

---

## Licença

Este projeto está licenciado sob a [MIT License](https://opensource.org/licenses/MIT). Você é livre para modificar e compartilhar este código.


