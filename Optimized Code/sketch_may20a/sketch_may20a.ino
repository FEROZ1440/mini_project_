#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(D0, D1, D2, D3, D4, D5);
SoftwareSerial mySerial(D7, D6); //(Rx,Tx)

String val = "No Data";
String oldval;
String newval = "No Data";
int length;
int l;
void setup()
{
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  mySerial.begin(9600);
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Wireless Notice");
  lcd.setCursor(0, 1);
  lcd.print("     Board     ");
  delay(3000);
  lcd.clear();
  lcd.print("Welcome!");
}

void loop()
{
  val = mySerial.readString();
  length=val.length();
  val.trim();
  Serial.println(val);
  if(length!=0)
  {
    l=length;
  }
  if (val != oldval)
  {
    newval = val;  
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(newval);
  delay(1000);
   if(l>16)
   {
    for (int i=0;i<l-16;i++)
    {
      lcd.scrollDisplayLeft();
      delay(250);
    }
    delay(1000);
    for (int i=0;i<l-16;i++)
    {
      lcd.scrollDisplayRight();
      delay(250);
      }
   }
  val = oldval;
}
