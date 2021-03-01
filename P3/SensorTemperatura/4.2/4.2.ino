#include <LiquidCrystal.h>  // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// initialize the interface pins
int analogPin0 = A3;
int lect=0;
float volt=0;
float C=0;

void setup() {
   lcd.begin(16, 2);
}

void loop() {
  lect=analogRead(analogPin0);

  C=((float(lect)*205)/1023)-55; //Usando las especificaciones

  volt=((float(lect)*16)/1023)+4;

  //C=((float(lect)*50)/1023?); //Usando las 50°C como 500mv

  //volt=((float(lect)*5)/1023?);
    
  lcd.setCursor(1, 0);
  lcd.print("Temperatura: ");
  lcd.print(C);

  lcd.setCursor(1, 1);
  lcd.print("Voltaje: ");
  lcd.print(volt);
}
