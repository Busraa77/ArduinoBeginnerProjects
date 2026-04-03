# Binary Sayaç

Başlatma ve durdurma için 2 adet buton olacak. Başlatma butonuna basınca sıfırdan itibaren binary olarak artmaya başlayan ve durdurma butonuna basınca duran 0-256 arası 8-bitlik bir binary sayıcı uygulamasını, 8 tane led ve 2 tane buton ile gerçekleştirdim.


### Devre Elemanları
- 8 adet LED
- 8 adet 220 Ohm'luk koruyucu direnç
- 2 adet buton 
- Buton bağlantısı için 2 adet 10 kOhm'luk direnç 

### KOD
```

int leds[] = { 5, 6, 7, 8, 9, 10, 11, 12 };
int acButton = 2;
int kapatButton = 3;
byte sayac = 0;

void BinaryGoster() {

  for (sayac; sayac < 256; sayac++) {

    for (int j = 0; j < 8; j++) digitalWrite(leds[j], LOW);

    for (int j = 0; j < 8; j++) {

      if ((sayac & (1 << j)) > 0)  //<< : sola kaydır : çarp(2 ile)
      {
        digitalWrite(leds[j], HIGH);
      } else digitalWrite(leds[j], LOW);
    }
    if (digitalRead(kapatButton) == HIGH) {
      LedKapat();
      return;  // fonksiyondan çık
    }
    delay(500);
  }
}
void LedKapat() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }

  pinMode(acButton, INPUT);
  pinMode(kapatButton, INPUT);
  digitalWrite(acButton, LOW);
  digitalWrite(kapatButton, LOW);

}

void loop() {
  if (digitalRead(acButton) == HIGH) {
    sayac = 0;
    BinaryGoster();
  }
}


```



https://github.com/user-attachments/assets/3699df31-47d0-4921-b504-9c4700984b31



https://github.com/user-attachments/assets/2cfd83da-3768-4e26-9e38-c95ea468324c


