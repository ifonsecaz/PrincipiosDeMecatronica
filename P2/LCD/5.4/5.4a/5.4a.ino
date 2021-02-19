#include <LiquidCrystal.h>  // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// initialize the interface pins
int i=16;
void setup() {
  lcd.begin(16, 2);// set up the LCD's number of columns and rows:
}

void loop(){
  lcd.setCursor(i, 0);
  lcd.print("Israel Fonseca");// Print a message to the LCD.
  lcd.setCursor(i, 1);
  lcd.print("Zárate");

  for(i=0; i>=16; i++){
    lcd.scrollDisplayLeft();
    delay(1000);
  }
  
}
