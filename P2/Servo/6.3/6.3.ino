#include <Servo.h>
#include <LiquidCrystal.h>  // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// initialize the interface pins
Servo myservo;// create servo object to control a servo
int val = 0;// variable to read the value from the analog pin
int analogPin = A0;
float volt = 0; //Voltaje a mostrar
int posServo=0;

void setup() {
  lcd.begin(16, 2);
  myservo.attach(9);// attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(analogPin);// leemos el valor del potenciómetro
  volt=(float(val)*5)/1024; //Lo convertimos a voltaje

  posServo=map(val,0,1023,0,180);

  myservo.write(posServo);

  lcd.setCursor(1, 0);
  lcd.print("Voltaje: ");
  lcd.print(volt);

  lcd.setCursor(2,0);
  lcd.print("Ángulo: ");
  lcd.print(posServo);
  
  delay(500); //Espero medio segundo
}
