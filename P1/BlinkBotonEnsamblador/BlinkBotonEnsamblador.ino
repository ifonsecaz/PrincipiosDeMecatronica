
void setup()
{
DDRB = DDRB | B10111111; //Elige el séptimo bit del puerto B como salida y el sexto de entrada, el resto se ponen en 1 para actuar como salidas y evitar errores
}
void loop()
{
asm (
"inicio: \n\t"
"sbrc 0x05,0x06 \n\t" //Salto si el sexto bit es 0, del registro B
"call f1 \n\t" //Fue 1, está pulsado el botón, llamo a la subrutina con frecuencia de 1Hz
"sbrs 0x05,0x06 \n\t" //Salto si el sexto bit es 1
"call f5 \n\t" //Es 0, llama a la subrutina con frecuencia .5Hz
"jmp main \n\t" //Regreso al inicio

"f1: \n\t" //Subrutina 1
"sbi 0x05,0x07 \n\t"  //Prendo el LED
"LDI r22, 45 \n\t" //Tarda 1 segundo
"call tiempo \n\t" //Llamo al contador
"cbi 0x05,0x07 \n\t" //Apago el LED
"LDI r22, 45 \n\t"
"call tiempo \n\t" //Llamo al contador
"ret \n\t"

"f5: \n\t" //Subrutina 2
"sbi 0x05,0x07 \n\t"  //Prendo el LED
"LDI r22, 22 \n\t" //Cargo el contador para tardar medio segundo
"call tiempo \n\t" //Llamo al contador
"cbi 0x05,0x07 \n\t" //Apago el LED
"LDI r22, 23 \n\t"
"call tiempo \n\t" //Llamo al contador
"ret \n\t"

"tiempo: \n\t"
"LOOP_3: \n\t"
"LDI r21, 255 \n\t"
"LOOP_2: \n\t"
"LDI r20, 255 \n\t"
"LOOP_1: \n\t"
"DEC r20 \n\t"
"BRNE LOOP_1 \n\t"
"DEC r21 \n\t"
"BRNE LOOP_2 \n\t"
"DEC r22 \n\t"
"BRNE LOOP_3 \n\t"
"ret \n\t"
);
}
