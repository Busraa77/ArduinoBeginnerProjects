# Potansiyometre ile Hassas Servo Motor Kontrolü

Bu proje, harici bir potansiyometreden alınan analog verilerin (voltaj değişimlerinin) Arduino Uno tarafından işlenerek, servo motorun konumunu anlık ve hassas bir şekilde kontrol edilmesini sağlar.

Projede, potansiyometrenin analog dünyasındaki değer aralığı, `map()` fonksiyonu kullanılarak servo motorun anladığı şekilde ölçeklenmiştir.

## Proje Çalışma Mantığı

1. **Veri Okuma (`analogRead`):** Potansiyometre döndürüldükçe Arduino'nun `A0` pinine 0V ile 5V arasında bir voltaj gelir. İşlemci içerisindeki 10-bitlik ADC (Analog-Digital Converter) bu voltajı **0 ile 1023** arasında dijital bir sayıya dönüştürür.
2. **Değer Ölçekleme (`map`):** Servo motorlar yalnızca 0 ile 180 derece arasında komut kabul eder. Bu nedenle `map(deger, 0, 1023, 0, 180)` fonksiyonu kullanılarak potansiyometre oranları tam olarak servo açılarına dönüştürülür.
3. **Konumlandırma (`myservo.write`):** Elde edilen hassas açı değeri servoya gönderilir ve motor içindeki kapalı çevrim geri bildirim mekanizması sayesinde milimetre şaşmadan hedef açıda sabitlenir.

## Donanım Bağlantıları



### 1. Servo Motor Bağlantıları
* **Turuncu / Sarı (Sinyal):** Arduino Dijital Pin 9
* **Kırmızı (VCC):** Arduino 5V
* **Kahverengi / Siyah (GND):** Arduino GND

### 2. Potansiyometre Bağlantıları
* **Sol Bacak:** Arduino 5V
* **Orta Bacak (Sinyal):** Arduino Analog Pin A0
* **Sağ Bacak:** Arduino GND

```cpp

https://github.com/user-attachments/assets/178a1fa5-8a31-4440-9559-9cb28194a061


#include <Servo.h>

Servo myservo;        // Servo motor nesnesi
const int potPin = A0; // Potansiyometrenin bağlı olduğu analog pin
int potValue = 0;     // Potansiyometreden okunacak ham değer
int angle = 0;        // Servoya gönderilecek ölçeklenmiş açı değeri

void setup() {
  myservo.attach(9);  // Servonun 9 numaralı pine bağlı olduğunu belirtir
  // Not: Analog pinler varsayılan olarak INPUT olduğundan pinMode(A0, INPUT) şart değildir.
}

void loop() {
  potValue = analogRead(potPin);                  // 0-1023 arası değeri oku
  angle = map(potValue, 0, 1023, 0, 180);        // Değeri 0-180 dereceye oranla
  myservo.write(angle);                           // Servoyu hedef açıya götür
  delay(15);                                      // Kararlılık için küçük bir gecikme
}
```





https://github.com/user-attachments/assets/bdecc8be-0f1b-4819-ae4b-272432979e9b


https://github.com/user-attachments/assets/5c2950cf-76d7-46f7-835d-541aa547381d


