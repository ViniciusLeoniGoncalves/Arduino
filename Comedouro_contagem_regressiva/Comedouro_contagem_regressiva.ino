#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

unsigned long lastmillis = 0; 
int seconds = 59;
int minutes = 59;
int hours = 23;

int resetPin = 7;

LiquidCrystal_I2C lcd(0x27,16,2);
Servo gate;

void setup() {

  Serial.begin(9600);
  lcd.init(); 
  lcd.backlight();
  gate.attach(11);
  gate.write(0);
  pinMode(7,INPUT_PULLUP);
  pinMode(7,OUTPUT);
  
}

void loop() {
  
  if (millis() - lastmillis >= 1000) { 
    // 1 segundo passou
    lastmillis = millis();

    if (seconds == 0) {
      seconds = 59;

      if (minutes == 0) {
        minutes = 59;

        if (hours == 0) {
          Serial.println("abrindo portão");
          open_gate();
          // Reiniciar o Arduino
          digitalWrite(resetPin,LOW);

          //caso isso seja executado, o reset falhou
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Reset falhou");
          delay(100000);
          hours = 23;

        } else {
          hours -= 1;
          
        }
      } else {
        minutes -= 1;
      }
    } else {
      
      seconds -= 1;
      
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Proxima refeicao");
    lcd.setCursor(4,1);
    lcd.print(hours);
    lcd.print(":");
    lcd.print(minutes);
    lcd.print(":");
    lcd.print(seconds);
  }
}

void open_gate() {
      lcd.clear();
      lcd.noBacklight();
      gate.write(90);
      delay(1200);
      gate.write(0);
      delay(1200);
      lcd.backlight();
}
