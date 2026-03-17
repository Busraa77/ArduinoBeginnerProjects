void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  // A2 pininden 0 ile 1023 arasında bir değer oku
  int hamDeger = analogRead(A2);
  
  // Okunan ham değeri voltaj cinsine çevir (5V / 1023 = 0.0048)
  float voltaj = hamDeger * (5.0 / 1023.0);
  
  // Değerleri ekrana yazdır
  Serial.print("Ham Deger: ");
  Serial.print(hamDeger);
  Serial.print(" | Voltaj: ");
  Serial.print(voltaj);
  Serial.println(" V");
  
  delay(100); // Okumayı kolaylaştırmak için kısa bir bekleme

}
