
int analogPin0 = A2;
int analogPin1 = A3;
int valX;
int valY;
float posX=0;
float posY=0;
float posAntX=0;
float posAntY=0;
int boton=0;

void setup() {
  Serial.begin(9600);//  setup serial
  pinMode(3,INPUT);
}

void loop() {
  valX=analogRead(analogPin0); 
  valY=analogRead(analogPin1);

  posX=(((float(valX)*2)/1023)-1);
  posY=(((float(valY)*2)/1023)-1);


  Serial.println(String(posX) + "," + String(posY));

  //Serial.println(String(posX*posY));
  
  //boton=digitalRead(3);
  //Serial.print("       Botón: ");
  //Serial.println(boton);
  
  delay(100);
}
