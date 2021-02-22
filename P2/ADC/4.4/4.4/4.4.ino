int analogPin = A0;// potentiometer wiper (middle terminal) connected to analog pin 3
// outside leads to ground and +5V
int val = 0;// variable to store the value read
float volt = 0; //Voltaje a mostrar

void setup() {
  Serial.begin(9600);//  setup serial
  pinMode(13, OUTPUT); //Asociado al LED
}
  
void loop() {
  val = analogRead(analogPin);// read the input pin
  volt=(float(val)*5)/1024;
  
  analogWrite(13,(float(val)*255)/1024);
  
  Serial.print ("El voltaje analógico es: ");
  Serial.println(volt);// debug value
  //delay(1000); //Espero un segundo
}
