int volt = 0;
int lect=0;

void setup() {
  pinMode(6, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  lect=analogRead(A3);
  
  volt=map(lect,0,1023,-255,255);

  analogWrite(6,abs(volt));
  
  digitalWrite(3,LOW); 
  digitalWrite(2,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  
  if(volt>=0){ 
    digitalWrite(3, HIGH); 
    digitalWrite(11,HIGH);
  }else{                      
  digitalWrite(3,LOW);
    digitalWrite(11,LOW);
  }
  
  if(volt<=0){ 
    digitalWrite(2, HIGH); 
    digitalWrite(12,HIGH);
  }else{                      
  digitalWrite(2,LOW);
    digitalWrite(12,LOW);
  }
}
