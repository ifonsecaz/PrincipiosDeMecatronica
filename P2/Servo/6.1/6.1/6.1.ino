#include <Servo.h>
Servo myservo;// create servo object to control a servo
int val = 0;// variable to read the value from the analog pin

void setup() {
  myservo.attach(9);// attaches the servo on pin 9 to the servo object
}

void loop() {
  for (int i = 0; i <= 180; i++){
    myservo.write(i);// sets the servo position according to the scaled value
    delay(20);// waits for the servo to get there
  }
  for (int i = 180; i >= 0; i--){
    myservo.write(i);// sets the servo position according to the scaled value
    delay(20);// waits for the servo to get there
  }
}
