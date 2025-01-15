#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
                                  //porta A4 para o SDA e porta A5 para o SCL
void setup(){
  lcd.init(); 
  lcd.backlight();
}


void loop(){
  lcd.setCursor(3,0);             //Escolhe a posição do caractere que começará a ser escrita a frase, display tem 2 linhas com 16 slots de caractere cada
  lcd.print("Blink Display");
  delay(1000);
  lcd.clear();
  delay(1000);
}
