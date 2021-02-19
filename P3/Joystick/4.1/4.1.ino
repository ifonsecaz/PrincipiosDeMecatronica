#include <LiquidCrystal.h>  // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// initialize the interface pins
int analogPin0 = A0;
int analogPin1 = A1;
float valX;
float valY;
float posX=0;
float posY=0;
float graph;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);//  setup serial
}

void loop() {
  valX=analogRead(analogPin0); //Checar si A0 es X o Y
  valY=analogRead(analogPin1);

  posX=valX; //Cambiar
  posY=valY;

  lcd.setCursor(1, 0);
  lcd.print("X: ");
  lcd.print(posX);

  lcd.setCursor(2, 0);
  lcd.print("Y: ");
  lcd.print(posY);

  graph=posY*posX;
  Serial.println(graph);

  //Para cada eje
  Serial.println(posY);

  Serial.println(posX);
}
