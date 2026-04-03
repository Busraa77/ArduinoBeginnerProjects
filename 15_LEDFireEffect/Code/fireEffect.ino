int ledPins[] = {9,10,11};


void setup() {
  for (int i =0;i<3;i++)
  {
    pinMode(ledPins[i],OUTPUT);
  }

}

void loop() {
  for (int i =0;i<3;i++)
  {
    analogWrite(ledPins[i],random(120)+135);
    //135–255 arası kullanılıyor: LED hiç sönmesin,hep parlak ama titreşen olsun
  }
  delay(100);
}
