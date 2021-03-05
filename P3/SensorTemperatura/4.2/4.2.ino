#include <LiquidCrystal.h>  // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// initialize the interface pins
int analogPin0 = A0;
int lect=0;
float volt=0;
float C=0;

void setup() {
   lcd.begin(16, 2);
}

void loop() {
  lect=analogRead(analogPin0);
  
  volt=((float(lect)*5)/1023);
  
  C=volt/.01;
    
  lcd.setCursor(0, 0);
  lcd.print("Temperatura ");
  lcd.print(C);
  

  lcd.setCursor(0, 1);
  lcd.print("Voltaje: ");
  lcd.print(volt);
}
