#include <IRremote.hpp>
#define IR_RECEIVE_PIN 7

void setup()
{

  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Inicia o receptor no pino definido do arduino e liga o led builtIn para feedback
}

void loop() {
  if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Imprime o hexadecimal da tecla apertada apenas
      //IrReceiver.printIRResultShort(&Serial); 					// Imprime todos os dados à respeito da comunicação
      //IrReceiver.printIRSendUsage(&Serial);   					
     
      IrReceiver.resume(); // Libera o receptor para receber o próximo valor
  }
}