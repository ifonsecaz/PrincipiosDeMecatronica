void setup()
{
DDRB = DDRB | B10000000; // elige el séptimo bit del puerto B
}
void loop()
{
asm (
"inicio: \n\t"
"sbi 0x05,0x07 \n\t"
"sbic 0x03,0x06 \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"cbi 0x05,0x07 \n\t"
"sbic 0x03,0x06 \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"jmp inicio \n\t"

"tiempo: \n\t"
"LDI r22, 45 \n\t"
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
