//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//porta A4 para o SDA e porta A5 para o SCL
void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();

}


void loop()
{
    lcd.setCursor(3,0);
  lcd.print("Fuck GPS!");
  delay(1000);
  lcd.clear();
  delay(1000);
}
