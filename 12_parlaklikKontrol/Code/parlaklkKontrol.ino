int led = 9;
int ayar = A0;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);

}

void loop() {
  int deger=analogRead(ayar);
  Serial.print("deger :");
  Serial.println(deger);
  int sonDeger = constrain(deger,0,1023);
  int parlaklik = map(sonDeger,0,1023,0,255); // 0-2 saniye arasında bir bekleme süresi
  analogWrite(led,parlaklik);
}
