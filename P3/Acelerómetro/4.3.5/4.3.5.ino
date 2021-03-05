#include <LiquidCrystal.h>  // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// initialize the interface pins
int xpin=A0;
int ypin=A1;
int zpin=A2;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  float X_out=analogRead(xpin);

  float Y_out=analogRead(ypin);

  float Z_out=analogRead(zpin);

  float  Xg=((X_out*5)/1024-1.65)/0.330;
  float Yg=((Y_out*5)/1024-1.65)/0.330;
  float Zg=((Z_out*5)/1024-1.65)/0.330;
  Serial.print(Xg); //print x value on serial monitor
  Serial.print("\t");
  Serial.print(Yg); //print y value on serial monitor
  Serial.print("\t");
  Serial.print(Zg); //print z value on serial monitor
  Serial.print("\n");

  float  roll = ( ( (atan2(Yg,Zg) * 180) / 3.14 ) + 180 );
  float pitch = ( ( (atan2(Zg,Xg) * 180) / 3.14 ) + 180 );
  
  Serial.print("Roll = ");
  Serial.print(roll);
  Serial.print("\t");
  Serial.print("Pitch = ");
  Serial.print(pitch);

  float aux=sqrt(pow(Xg,2)+pow(Yg,2));
  
  float angulo = atan2(aux,Zg)*180/PI;
  
  lcd.setCursor(1, 0);
  lcd.print("Angulo ");
  lcd.print(angulo);

  Serial.print("\t");
  Serial.print("Angulo = ");
  Serial.print(angulo);
  Serial.print("\n\n");

  delay(500);
}
