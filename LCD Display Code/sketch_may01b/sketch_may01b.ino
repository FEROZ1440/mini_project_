#include <LiquidCrystal.h>
LiquidCrystal lcd(D1, D2, D3, D4, D5, D6);
void setup() 
{
lcd.begin(16, 2);
lcd.print("Welcome To Arduino");
delay(2000);
}
void loop() 
{
 for (int i=0;i<13;i++) 
 {
 lcd.scrollDisplayLeft();
 delay(150);
 }
 for (int i=0;i<29;i++) 
 {
  lcd.scrollDisplayRight();
  delay(150);
 }
 for (int i=0;i<16;i++) 
 {
  lcd.scrollDisplayLeft();
  delay(150);
 }
 delay(1000);
}
