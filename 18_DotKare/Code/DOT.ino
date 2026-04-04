
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