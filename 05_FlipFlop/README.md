
# RGB LED Flip-Flop (Çakar) Uygulaması
Projenin amacı RGB LED kullanımını öğrenmektir. Bu proje, bir RGB LED kullanarak belirli zaman aralıklarıyla renkler arasında geçiş yapan (flip-flop/çakar) bir Arduino uygulamasıdır.

### RGB LED Nedir?
RGB LED, tek bir LED içerisinde kırmızı, yeşil ve mavi renklerde üç ayrı ışık yayan diyotun birleşimidir. 
Bu üç ana rengin farklı oranlarda karıştırılmasıyla (PWM tekniği kullanılarak) her renk tonu elde edilebilir.

4 bacaklı bir yapısı vardır. Üç bacak her bir ana renk (R, G, B) içindir, en uzun bacak ise devrenin geri dönüşünü sağlayan "Ortak" (Common) bacaktır.

İki farklı türü vardır:
* Ortak Katot (CC): Ortak bacak GND (-) hattına bağlanır. HIGH sinyali ile çalışır.
* Ortak Anot (CA): Ortak bacak VCC (+5V) hattına bağlanır. LOW sinyali ile çalışır.

Dijital pinlerle ana renkler, PWM (analogWrite) pinleriyle ise ara renkler oluşturulur.

Önemli Not: Dirençlerin her bir renk bacağına (R, G, B) ayrı ayrı bağlanması gerekir. Ortak bacağa tek bir direnç takılması, renklerin parlaklık dengesini bozar ve LED'e zarar verebilir.


### Devre Elemanları

* RGB LED (Ortak Katot veya Ortak Anot)
* 3x 220 Ohm Direnç (LED'leri korumak için)

### Devre Kurulumu

RGB bacakları için 3 ayrı pin seçiyoruz. Bu projede analog olarak renkleri oluşturmak istediğim için PWM pinlerinden üçünü seçtim. 9,10,11.
LED'im ortak anot olduğundan uzun bacağı +5V'a bağladım. diğer 3 bacağı da dirençlerle pinlerine bağladım. Ortak bacak 5V'a bağlandığı için LED'in üzerinden akım geçmesi ancak diğer bacakların GND (0V) seviyesine çekilmesiyle mümkündür.


### KOD
```cpp
int kirmizi=9;
int yesil=10;
int mavi = 11;

void setup() {
  pinMode(mavi,OUTPUT);
  pinMode(kirmizi,OUTPUT);
  pinMode(yesil,OUTPUT);
}

void loop() {
  renkSec(255,255,0);
  delay(1000);

  renkSec(0,255,255);
  delay(1000);
}

void renkSec(int r, int g, int b)
{
analogWrite(kirmizi,r);
analogWrite(yesil,g);
analogWrite(mavi,b);
}
```





https://github.com/user-attachments/assets/d5e8213d-c01e-4589-b294-fa622e9ab65e





https://github.com/user-attachments/assets/5da1233a-ed7d-4023-931a-b11ca49c5457
























