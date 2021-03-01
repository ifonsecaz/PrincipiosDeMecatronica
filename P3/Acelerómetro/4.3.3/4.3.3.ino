int xpin=A0;
int ypin=A1;
int zpin=A2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float X_out=analogRead(xpin);

  float Y_out=analogRead(ypin);

  float Z_out=analogRead(zpin);

 
  Serial.print(((X_out*5)/1024-1.65)/0.330); //print x value on serial monitor
  Serial.print("\t");
  Serial.print(((Y_out*5)/1024-1.65)/0.330); //print y value on serial monitor
  Serial.print("\t");
  Serial.print(((Z_out*5)/1024-1.65)/0.330); //print z value on serial monitor
  Serial.print("\n");
  
  delay(1000);
}
