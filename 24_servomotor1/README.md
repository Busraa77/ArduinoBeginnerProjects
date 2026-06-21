# Arduino ile Servo Motor Projesi

Bu proje, bir adet servo motorun ($0^\circ - 180^\circ$) Arduino Uno kullanılarak `Servo.h` kütüphanesi yardımıyla sağa ve sola döndürülmesini içerir. 

Projede motor, iki ardışık for döngüsü kullanılarak kontrollü bir hızda ileri ve geri hareket ettirilmektedir.

## Proje Çalışma Mantığı

`void loop()` fonksiyonu içerisinde motorun hareketi iki aşamada gerçekleşir:
1. **İleri Doğru ($0^\circ \rightarrow 180^\circ$):** İlk `for` döngüsü, servo açısını her 15 milisaniyede bir 1 derece artırarak motoru maksimum sınıra ulaştırır.
2. **Geriye Doğru ($180^\circ \rightarrow 0^\circ$):** İkinci `for` döngüsü, açıyı her adımda 1 derece azaltarak motoru başlangıç konumuna geri getirir.

> **Not:** Adım aralarındaki `delay(15);` beklemeleri, motorun mekanik olarak zorlanmasını engeller ve hareketin pürüzsüz (smooth) olmasını sağlar.

## Donanım Bağlantıları

Servo motorlar standart olarak 3 adet kabloya sahiptir. Bağlantı şeması şu şekildedir:

| Servo Kablo Rengi | Arduino Pini | İşlevi |
| :--- | :--- | :--- |
| **Turuncu / Sarı** | Dijital Pin 9 (PWM) | Sinyal Hattı |
| **Kırmızı** | 5V | Güç Hattı (VCC) |
| **Kahverengi / Siyah** | GND | Toprak Hattı |


```cpp 
#include <Servo.h>

Servo myservo;  // Servo motoru kontrol etmek için nesne oluşturulması
int pos = 0;    // Servo konumunu tutacak değişken

void setup() {
  myservo.attach(9);  // Servonun 9 numaralı pine bağlı olduğunu belirtir
}

void loop() {
  // 0 dereceden 180 dereceye 1'er derece artışla gider
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              // Servoya gitmesi gereken açıyı bildirir
    delay(15);                       // Motorun konuma ulaşması için 15ms bekler
  }
  
  // 180 dereceden 0 dereceye 1'er derece azalışla geri döner
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              // Servoya gitmesi gereken açıyı bildirir
    delay(15);                       // Motorun konuma ulaşması için 15ms bekler
  }
}
```





https://github.com/user-attachments/assets/de81ebee-6503-4b50-b16d-d4093ed49180



https://github.com/user-attachments/assets/f8c9b967-fa81-4712-91c6-80af2d5462b8









