# Start Stop Kontrol Ünitesi Uygulaması
Projenin amacı startt ve stop komutlarını yöneten iki farklı buton ile LED'in yanışını kontrol etmektir. Buton girişlerinde kararlı mantıksal seviyeler elde etmek için harici pull-down dirençleri kullanılmıştır.
### Devre Elemanları
- 1 kırmızı LED
- LED için koruyucu 220 Ohm'luk direnç
- 2 adet Buton
- 2 adet 10 kOhm'luk direnç

### Kod
```cqq
int led=7;
int butonAc=8;
int butonKapat =9;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(butonAc,INPUT);
  pinMode(butonKapat,INPUT);

}

void loop() {
 bool ac = digitalRead(butonAc);
 bool kapat = digitalRead(butonKapat);

 if(kapat==HIGH)
 digitalWrite(led,HIGH);
 else if(ac==HIGH)
 digitalWrite(led,LOW);

}

```


https://github.com/user-attachments/assets/857e7df3-f89b-4274-b0f6-f4115036c2da




https://github.com/user-attachments/assets/fcdb6477-65e9-40b1-9333-4e0992e3a265





