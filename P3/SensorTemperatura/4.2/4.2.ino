#include <LiquidCrystal.h>  // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// initialize the interface pins
int analogPin0 = A0;
float volt=0;
float C=0;

void setup() {
   lcd.begin(16, 2);
}

void loop() {
  volt=analogRead(analogPin0);

  C=volt;//Cambiar
    
  lcd.setCursor(1, 0);
  lcd.print("Temperatura: ");
  lcd.print(volt);

  lcd.setCursor(2, 0);
  lcd.print("Voltaje: ");
  lcd.print(C);
}
