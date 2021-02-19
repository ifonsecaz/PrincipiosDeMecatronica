#include <Servo.h>
Servo myservo;// create servo object to control a servo
int val = 0;// variable to read the value from the analog pin
int analogPin = A0;
float volt = 0; //Voltaje a mostrar
int posServo=0;

void setup() {
  myservo.attach(9);// attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(analogPin);// leemos el valor del potenciómetro

  posServo=map(val,0,1023,0,180);

  myservo.write(posServo);
  delay(500); //Espero medio segundo
}
