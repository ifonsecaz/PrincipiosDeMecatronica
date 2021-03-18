int volt = 0;
int lect=0;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  lect=analogRead(A3);

  volt=(float(lect)*510)/1023-255;

  digitalWrite(13,HIGH);
  
  if(volt<0){ 
    digitalWrite(3, HIGH); 
    digitalWrite(2,LOW);
    analogWrite(11,0);
    analogWrite(12,abs(volt));
  }else{                      
    if(volt>0){
      digitalWrite(3,LOW);
      digitalWrite(2,HIGH);
      analogWrite(12,0);
      analogWrite(11,volt);
    }else{
      digitalWrite(3,LOW);
      digitalWrite(2,LOW);
      analogWrite(12,0);
      analogWrite(11,0);
    }
  }
}
