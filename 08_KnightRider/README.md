# Yürüyen Led / Knight Rider(Kara Şimşek) Uygulaması

Projenin amacı baştan sona ve sondan başa olacak şekilde LED'lerin yakılmasını kontrol etmektir. 


### Devre Elemanları
- 6 adet kırmızı  LED
- 6 adet 220 Ohm'luk direnç


### Devre Kurulumu
Klasik LED bağlantısı yapılır. Pin -> LED -> Direnç -> GND

### KOD

```cqq

int leds[] = { 7, 8, 9, 10, 11, 12 };

const int sure = 50;

void setup() {

  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void loop() {

  for (int x = 0; x < 6; x++) {
    digitalWrite(leds[x], HIGH);
    delay(sure);
    digitalWrite(leds[x], LOW);
  }

  for (int x = 4; x > 0; x--) {
    digitalWrite(leds[x], HIGH);
    delay(sure);
    digitalWrite(leds[x], LOW);
  }
}

```





https://github.com/user-attachments/assets/b5f02138-1e59-457f-a793-3dbf8484e136


https://github.com/user-attachments/assets/f7da473e-e359-44ea-b6ae-a69950728a5f




