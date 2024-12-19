#include <IRremote.hpp>
#include <Servo.h>

#define IR_RECEIVE_PIN 7

Servo servobase;
Servo servohorizontal;
Servo servovertical;
Servo servogarra;
int basePos = 0;
int horizontalPos=0;
int verticalPos=0;
int garraPos=10; 

uint64_t key_value = 0;
String firstDigit, secondDigit, thirdDigit, concat;
int steps;
int digitCount=1;
bool inversor = false;
uint64_t last_key_value = 0;


void setup(){
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN,ENABLE_LED_FEEDBACK);
  servobase.attach(9);
  servohorizontal.attach(10);
  servovertical.attach(11);
  servogarra.attach(12);
}

void loop(){

  if (IrReceiver.decode()){
    if(IrReceiver.decodedIRData.decodedRawData != 0xFFFFFFFF){
    	key_value = IrReceiver.decodedIRData.decodedRawData;
      last_key_value = key_value;
    }
  	
        switch(key_value){
          case 0xE31CFF00:
          
          if(garraPos==10){
            garraPos=180;
            Serial.println("OK (garra abre)");
            servogarra.write(garraPos);
            delay(200);
          }
          else{
            garraPos = 10;
            servogarra.write(garraPos);
            Serial.println("OK (garra fecha)");
            delay(200);
          }
          
          break ;
           
          case 0xA55AFF00:
          Serial.println("Teclou > (direita)");
          servobase.write(180);
          delay(200);
          
          break ;  
          case 0xF708FF00:
          Serial.println("Teclou < (esquerda)");
          servobase.write(0);
          delay(200);
          
          break ;
          case 0xE718FF00:
          Serial.println("Teclou ^ (frente)");
          servohorizontal.write(180);
          delay(200);
          break ;
          case 0xAD52FF00:
          Serial.println("Teclou v (trás)");
          servohorizontal.write(0);
          delay(200);
          break ;
          case 0xF20DFF00:
          Serial.println("Teclou # (baixo)");
          servovertical.write(0);
          delay(200);
          break ;
          case 0xE916FF00:
          Serial.println("Teclou * (cima)");
          servovertical.write(180);
          delay(200);
        }
        IrReceiver.resume(); 
  }
}