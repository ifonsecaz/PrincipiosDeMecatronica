#include <LiquidCrystal.h>  // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// initialize the interface pins
int i=16;
void setup() {
  lcd.begin(16, 2);// set up the LCD's number of columns and rows:
}

void loop(){
  lcd.setCursor(i, 0);
  lcd.print("Israel ");// Print a message to the LCD.
  lcd.setCursor(i, 1);
  lcd.print("Fonseca Zarate ");
  delay(1000);

  if(i>0){
    i--;
  }
  
}
