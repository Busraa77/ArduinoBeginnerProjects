int pot = A0;
int transistor = 9;
int value=0;

void setup() {
  pinMode(transistor,OUTPUT); 
  pinMode(pot,INPUT);

}

void loop() {
  value= analogRead(pot)/4; //0-1023 arası okuma
  analogWrite(transistor,value);  // Transistöre 0-255 arası olan hesaplananHiz değerini gönder

}
