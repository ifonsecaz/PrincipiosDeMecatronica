//4.3-4.5 Blink
//Low Frecuencia de 1HZ
//High Frecuencia de .5Hz
int EstadoBoton = 0; //0 no está presionado
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT); //Pin asociado al 13 y a un led: Rojo
  pinMode(12, OUTPUT); //Pin asociado al 12 y a un led: Amarillo
  pinMode(11, OUTPUT); //Pin asociado al 11 y a un led: Verde
  pinMode(7, OUTPUT); //Pin asociado al 7 y a un led: Rojo2
  pinMode(6, OUTPUT); //Pin asociado al 6 y a un led: Amarillo2
  pinMode(5, OUTPUT); //Pin asociado al 5 y a un led: Verde2
}

// the loop function runs over and over again forever
void loop() {               
    digitalWrite(12, LOW); //Apago el amarillo
    digitalWrite(13, HIGH);   // Prende el Rojo
    digitalWrite(7, LOW); // Apago el rojo2
    digitalWrite(5, HIGH); //Prende el verde2
    delay(5000);                       // Espera 5 segundos
    digitalWrite(5, LOW);    // Apaga el verde2
    digitalWrite(6, HIGH); //Prendo el amarillo2
    delay(1000);                       //Espero 1 segundo
    digitalWrite(13, LOW); //Apago el rojo
    digitalWrite(11, HIGH); //Prendo el verde
    digitalWrite(6, LOW); //Apago el amarillo2
    digitalWrite(7, HIGH); //Prendo el rojo2
    delay(5000);    //Espero 5 segundos
    digitalWrite(11, LOW); //Apago el verde
    digitalWrite(12, HIGH); //Prendo el amarillo
    delay(1000);                       // Espera 1 segundo
}
