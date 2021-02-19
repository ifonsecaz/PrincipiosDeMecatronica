int analogPin = A0;// potentiometer wiper (middle terminal) connected to analog pin 3
// outside leads to ground and +5V
int val = 0;// variable to store the value read
float volt = 0; //Voltaje a mostrar

void setup() {
  Serial.begin(9600);//  setup serial
}
  
void loop() {
  val = analogRead(analogPin);// read the input pin
  volt=(float(val)*5)/1024; //Mustro el voltaje
  Serial.print ("El voltaje analógico es: ");
  Serial.println(volt);// debug value}
  delay(1000); // Espera un segundo
}
