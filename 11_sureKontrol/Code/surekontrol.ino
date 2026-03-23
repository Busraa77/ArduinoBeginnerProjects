int led = 8;
int ayar = A0;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);

}

void loop() {
  int deger=analogRead(ayar);
  int sonDeger = constrain(deger,0,1023);
  int ledSure = map(sonDeger,0,1023,0,2046); // 0-2 saniye arasında bir bekleme süresi
  digitalWrite(led,HIGH);
  delay(ledSure);
  digitalWrite(led,LOW);
  delay(ledSure);
}
