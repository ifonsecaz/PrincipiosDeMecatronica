int EstadoBoton1 = 0;
int EstadoBoton2 = 0;

void setup() {
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  EstadoBoton1=digitalRead(7);
  EstadoBoton2=digitalRead(6);

  digitalWrite(13,HIGH);
  
  if(EstadoBoton1==HIGH){ 
    digitalWrite(3, HIGH); 
    digitalWrite(11,HIGH);
  }else{                      
    digitalWrite(3, LOW);
    digitalWrite(11,LOW);
  }
  if(EstadoBoton2==HIGH){
    digitalWrite(2,HIGH);
    digitalWrite(12,HIGH);
  }else{
    digitalWrite(2,LOW);
    digitalWrite(12,LOW);
  }
}
