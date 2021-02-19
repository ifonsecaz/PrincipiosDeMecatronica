//4.3-4.5 Blink
//Low Frecuencia de 1HZ
//High Frecuencia de .5Hz
int EstadoBoton = 0; //0 no está presionado
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, INPUT); //Asociado al botón
  pinMode(13, OUTPUT); //Pin asociado al 13 y a un led
}

// the loop function runs over and over again forever
void loop() {
  EstadoBoton=digitalRead(12); //Leo el botón
  
  if(EstadoBoton==HIGH){ //Si está presionado el botón
    digitalWrite(13, HIGH);   // Prende el LED
    delay(1000);                       // Espera un segundo, es decir f=.5Hz, completa medio ciclo por segundo
    digitalWrite(13, LOW);    // Apaga el LED
    delay(1000);                       // Espera un segundo para repetir el ciclo
  }else{                      //
    digitalWrite(13, HIGH);   // Prende el LED
    delay(500);                       // Espera 1/2 segundo
    digitalWrite(13, LOW);    // Apaga el LED
    delay(500);                       // Espera 1/2 segundo
  }
}
