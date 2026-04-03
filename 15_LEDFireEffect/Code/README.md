#LED ile Ateş Efekti
LED’leri rastgele titreştirerek (flicker) alev efekti oluşturulacak.

Kullanım alanı örnekleri: Maket ev içinde yangın efekti, şömine simülasyonu vb.

### Devre Elemanları
- 2 adet sarı LED
- 1 adet kırmızı LED
- 3 adet 220 Ohm'luk direnç

Devre klasik LED bağlantısı şeklinde kurulacak. Bu projedeki yenilik random komutu kullanılacak. random(120) 0 ile 120 arasında random bir sayı üretecek. Bu sayıya 135 ekleme sebebimiz LED'in hiç sönmesini istemiyoruz. LED parlaklığı azalıp artarak düzensiz titreşimler yapmalı ve alev efekti vermeli. 

```
int ledPins[] = {9,10,11};


void setup() {
  for (int i =0;i<3;i++)
  {
    pinMode(ledPins[i],OUTPUT);
  }

}

void loop() {
  for (int i =0;i<3;i++)
  {
    analogWrite(ledPins[i],random(120)+135);
    //135–255 arası kullanılıyor: LED hiç sönmesin,hep parlak ama titreşen olsun
  }
  delay(100);
}

```

https://github.com/user-attachments/assets/4bdbda86-5930-4e64-ac09-71617ad16a80


