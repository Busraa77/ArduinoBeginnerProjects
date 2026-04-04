# Dot Matrix ile Kutu İçinde Kutu Animasyonu

Bu proje, iki adet 74HC595 Shift Register kullanarak bir 8x8 LED Dot Matrix ekran üzerinde basit animasyonlar oluşturmayı hedefler. Projede Multiplexing tekniği ve Arduino Timer Interrupt kütüphanesi kullanılmıştır.
LED matrisler, çok sayıda LED'in az sayıda pin ile kontrol edilmesini gerektirir. Bu projede, 64 adet LED'i sadece 3 Arduino pini kullanarak kontrol ediyoruz.

Multiplexing: Satırları çok hızlı (100Hz) tarayarak gözün tüm resmi aynı anda görmesini sağlar.
Daisy-Chaining: İki shift register'ı birbirine seri bağlayarak 16-bit veri gönderimi sağlar.

### Devre Elemanları
- 1 x Arduino (Uno/Nano/Mega)
- 2 x 74HC595 Shift Register IC
- 1 x 8x8 LED Dot Matrix (Common Anode - C+)
- 8 x 220 Ohm Direnç

### Shift Registerların Bağlanması:

Her ikisinde de:
- Pin 10 (MR) → 5V
- Pin 13 (OE) → GND

- Arduino D8 → 1. 74HC595 pin 12 → LATCH
- Arduino D12 → 1. 74HC595 pin 11 → CLOCK
- Arduino D11 → 1. 74HC595 pin 14 → DATA

İki shift register’ı birbirine bağlanacak, seri bağlı çalışacak. İki entegrede clock ve latch ortak olmalı,bağlantı yapılmalı.

Shift Register 1 → Row bağlantıları (dirençlerle)
- Pin 15 → Row 1
- Pin 1 → Row 2
- Pin 2 → Row 3
- Pin 3 → Row 4
- Pin 4 → Row 5
- Pin 5 → Row 6
- Pin 6 → Row 7
- Pin 7 → Row 8

Shift Register 2 → Column bağlantıları (direkt)
- Pin 15 → Column 1
- Pin 1 → Column 2
- Pin 2 → Column 3
- Pin 3 → Column 4
- Pin 4 → Column 5
- Pin 5 → Column 6
- Pin 6 → Column 7
- Pin 7 → Column 8


- 74HC595 pin 9 (Q7') → 2. 74HC595 pin 14 (DS)
  74HC595 içerisinde iki ana bölüm vardır: <br>
  Shift Register (Kaydırma Kaydı) : Her Clock (saat) sinyali verildiğinde, en baştaki hücreye bir bit girer ve içerideki diğer tüm bitleri bir adım sağa iter.<br>
  Storage Register (Depolama Kaydı/Latch) : İçeride hazırlanan 8 bitlik paketi tek bir hamlede dışarıdaki çıkış pinlerine (Q0 - Q7) aktarır.<br>

Standart Çıkışlar (Q0 - Q7): Bu çıkışlar bir "Latch" (kilit) arkasındadır. Sen Latch pinini tetiklemeden bu çıkışlardaki veri değişmez.<br>
Seri Çıkış (Q7'): Latch sinyalini beklemez. Veri içeri girdiği anda bu pinden akar. 8 bitten fazla veri gönderdiğinde verinin bir yerden dışarı çıkması gerekir. 9. biti gönderdiğimizde, 1. bit içeride yer kalmadığı için kapıdan dışarı itilir.Bu dışarı itilen veri Q_7' pininden çıkar.Eğer bu pini ikinci bir 74HC595'in girişine bağlarsak, veri birinden çıkıp diğerine girer.<br> 
Buna "Daisy Chaining" (Papatya Dizimi) denir. Yani verinin bir sonraki entegreye geçmesi için bir "seri çıkış kapısı" görevi görür.<br>



### KOD

```

#include <TimerOne.h>

// Arduino -> 74HC595 bağlantıları
int latchPin = 8;    // 74HC595 pin 12 (ST_CP / Latch)
int clockPin = 12;   // 74HC595 pin 11 (SH_CP / Clock)
int dataPin  = 11;   // 74HC595 pin 14 (DS / Data)

// 8 satırlık görüntüyü tutan dizi
byte led[8];

void setup() {
  // Arduino pinlerini çıkış yap
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // 8x8 görüntü verisi
  // Her satır için 8 bitlik desen tutuluyor
  led[0] = B11111111;
  led[1] = B10000001;
  led[2] = B10111101;
  led[3] = B10100101;
  led[4] = B10100101;
  led[5] = B10111101;
  led[6] = B10000001;
  led[7] = B11111111;

  // Timer1'i 10000 mikro saniyeye ayarla. Yani yaklaşık saniyede 100 kere ekran güncellenecek
  Timer1.initialize(10000);

  // Her timer süresinde screenUpdate fonksiyonu çalışsın
  Timer1.attachInterrupt(screenUpdate);
}

void loop() {
  // Ana döngüde resmi tersine çevir
  // 1 olanları 0, 0 olanları 1 yapar
  // Böylece basit animasyon efekti oluşur
  for (int i = 0; i < 8; i++) {
    led[i] = ~led[i];
  }

  // 500 ms bekle
  delay(500);
}

// Ekranı sürekli tarayan fonksiyon
// Bu fonksiyon interrupt ile çağrılır
void screenUpdate() {
  // İlk satır aktif: 10000000
  byte row = B10000000;

  // 8 satırı sırayla tara
  for (byte k = 0; k < 8; k++) {

    // Latch'i aç: veri register içine girsin
    digitalWrite(latchPin, LOW);

    // Önce kolon verisini gönder
    // Common anode yapıda mantık ters olabildiği için ~led[k] kullanılıyor
    shiftIt(~led[k]);

    // Sonra aktif olacak satırı gönder
    shiftIt(row);

    // Latch'i kapat: veri çıkışlara aktarılsın
    digitalWrite(latchPin, HIGH);

    // Bir sonraki satıra geç
    row = row >> 1;
  }
}

// 74HC595'e 8 bit veri gönderen fonksiyon
void shiftIt(byte dataOut) { //Sayıları 0-1 sinyallerine dönüştürüp kablodan gönderir.
  boolean pinState;

  // Başlangıçta data hattını LOW yap
  digitalWrite(dataPin, LOW);

  // 8 bit gönder
  for (int i = 0; i < 8; i++) {

    // Clock başlangıçta LOW
    digitalWrite(clockPin, LOW);

    // Eğer ilgili bit 1 ise HIGH, değilse LOW gönder
    if (dataOut & (1 << i)) {
      pinState = HIGH;
    } else {
      pinState = LOW;
    }

    // Data pinine biti yaz
    digitalWrite(dataPin, pinState);

    // Clock yükselince bit register'a kaydedilir
    digitalWrite(clockPin, HIGH);

    // Data hattını tekrar temizle
    digitalWrite(dataPin, LOW);
  }

  // İş bitince clock LOW
  digitalWrite(clockPin, LOW);
}

```

https://github.com/user-attachments/assets/4074cc74-816b-4997-a2e6-b88746ff6015

