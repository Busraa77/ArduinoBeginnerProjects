# Arduino RGB LED Renk Döngüsü Projesi
Bu proje, bir potansiyometre (veya gerilim bölücü) aracılığıyla RGB LED üzerinde kesintisiz bir renk döngüsü oluşturur. map() ve constrain() fonksiyonları kullanılarak analog giriş değerleri, 3 ana renk arasında yumuşak geçişler yapacak şekilde oranlanmıştır.

### Özellikler
- Tam Renk Döngüsü: Kırmızı -> Yeşil -> Mavi arasında çift yönlü geçiş.
- Hata Payı Koruması: constrain() ile 0-1023 dışındaki parazit değerlerin engellenmesi.
- PWM Kontrolü: LED parlaklıklarının gerçek zamanlı ayarlanması.
- Seri Port Takibi: Okunan değerlerin ve RGB çıktı değerlerinin anlık izlenmesi.


### Devre Elemanları
- RGB LED
- Potansiyometre
- 3 adet 220 Ohm'luk direnç

### KOD

- map(deger, eskiMin, eskiMax, yeniMin, yeniMax)
  
Analog pinden gelen 0-1023 arasındaki veriyi, LED'in anlayacağı 0-255 (PWM) aralığına oranlamak için kullanıldı.

- constrain(deger, min, max)

Okuma sırasında oluşabilecek elektriksel gürültülerin, belirlenen sınırların (0-1023) dışına çıkmasını önlemek için kullanıldı.


```cqq
int pin = A0;

int red = 9;
int green = 10;
int blue = 11;


void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  Serial.begin(9600);

}

void loop() {
 int hamDeger= analogRead(pin);
 int temizDeger = constrain(hamDeger,0,1023); //değeri güvenli aralığa hapset (0-1023 dışına çıkmasın)

 int r = 0, g = 0, b = 0;

  if (temizDeger <= 341) {
    // --- 1. BÖLGE: KIRMIZI'DAN YEŞİL'E ---
    r = map(temizDeger, 0, 341, 255, 0);  // Kırmızı 255'ten 0'a iner
    g = map(temizDeger, 0, 341, 0, 255);  // Yeşil 0'dan 255'e çıkar
    b = 0;
  } 
  else if (temizDeger <= 682) {
    // --- 2. BÖLGE: YEŞİL'DEN MAVİ'YE ---
    g = map(temizDeger, 342, 682, 255, 0); // Yeşil azalır
    b = map(temizDeger, 342, 682, 0, 255); // Mavi artar
    r = 0;
  } 
  else {
    // --- 3. BÖLGE: MAVİ'DEN KIRMIZI'YA ---
    b = map(temizDeger, 683, 1023, 255, 0); // Mavi azalır
    r = map(temizDeger, 683, 1023, 0, 255); // Kırmızı artar
    g = 0;
  }

  // Renkleri LED'e gönder
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);

  // Seri porta akış
  Serial.print("Deger: "); Serial.print(temizDeger);
  Serial.print(" | R: "); Serial.print(r);
  Serial.print(" | G: "); Serial.print(g);
  Serial.print(" | B: "); Serial.println(b);

  delay(20);
  

}
```


https://github.com/user-attachments/assets/cdad98ac-6f35-4843-a95c-c07c0bd62059



https://github.com/user-attachments/assets/f794f1cc-1b10-47bb-b5d1-29d0a98278c4


