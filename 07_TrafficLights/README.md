# Trafik Işıkları Uygulaması

Bu proje buton ve led kullanımını birleştirmeyi ve kod ile zamanlamayı sağlamayı amaçlamaktadır. Işıklar tablodaki şekilde değişecektir. Yayalar için kırmızı ve yeşil olmak üzere 2 led varken araçlar için sarı ile birlikte 3 led vardır. Araçlar hareket halindeyken yayaların geçiş için butona bastığı durumda yayalara yeşil yandığında ek süre verilmektedir.

### Devrenin Özellikleri
- Dinamik Zamanlama: Araç yeşili yanarken butona basıldığında, sistem yayalara geçiş için ek süre tanımlar.

- Güvenlik Odaklı: Araç ve yaya ışıkları arasında emniyet payı (gecikme) bırakılarak olası kazalar önlenmiştir.

- Kararlı Okuma: Donanımsal 10kΩ Pull-down direnci ile buton hatalı tetiklemeleri engellenmiştir.


### Devre Elemanları
- 1 sarı LED
- 2 kırmızı LED
- 2 yeşil LED
- 5 adet 220 Ohm'luk LED için koruyucu direnç
- 1 adet buton
- 1 adet buton için 10 kOhm'luk direnç


### Devrenin Kurulumu
Ledler bir ucu direnç bir ucu pin olmak üzere bağlanmıştır. Direncin diğer ucu GND'ye bağlanmıştır.
Buton için pull-down bağlantı yapılmıştır. çapraz bacaklardan birisi 5V'A bağlıdır. Diğer ucu pine ve pin bir dirence, direncin diğer ucu GND'ye bağlanmıştır.

### Pin bağlantıları

- IO8 -> Yaya için yeşil LED
- IO9 -> Yaya için kırmızı LED
- IO10 -> Araç için yeşil LED
- IO11 -> Araç için sarı LED
- IO12 -> Araç için kırmızı LED

- IO7 -> buton

### Işık Zamanlaması
<img width="869" height="121" alt="Ekran görüntüsü 2026-03-22 095928" src="https://github.com/user-attachments/assets/ea65fdfa-da3a-46cd-af78-78c109e562f6" />


### KOD

```cqq
int kirmiziArac = 12;
int sariArac = 11;
int yesilArac = 10;

int kirmiziYaya = 9;
int yesilYaya = 8;

int buton = 7;

int arac []= {kirmiziArac, sariArac, yesilArac};
int yaya [] = {kirmiziYaya, yesilYaya};

bool yayaTalebi = false;

int bekleme = 5000; //standart kırmızı süresi
int ekSure = 10000; //yaya varsa kırmızı süresi




void setup() {
  for(int i =0 ; i<3;i++)
  {
    pinMode(arac[i],OUTPUT);

  }
   for(int i =0 ; i<2;i++)
  {
    pinMode(yaya[i],OUTPUT);
    
  }

  pinMode(buton,INPUT);
}

void loop() {
  // ARAÇ DUR - YAYA GEÇ
  digitalWrite(kirmiziArac,HIGH);
  digitalWrite(sariArac,LOW);
  digitalWrite(yesilArac,LOW);
  digitalWrite(yesilYaya,HIGH);
  
   if(yayaTalebi)
  {
    delay(ekSure);
    yayaTalebi = false;

  }
  else
  {
    delay(bekleme);
  }


  // ARAÇ HAZIRLAN - YAYA DUR
  
  digitalWrite(yesilYaya,LOW);
  digitalWrite(kirmiziYaya,HIGH);
  delay(500); // Yayaların durması için kısa bir emniyet payı

  digitalWrite(sariArac,HIGH);
  delay(1500);


  // ARAÇ GEÇ - YAYA DUR
  digitalWrite(kirmiziArac,LOW);
  digitalWrite(sariArac,LOW);
  digitalWrite(yesilArac,HIGH);


  //YEŞİL YANARKEN BUTONU KONTROL ET
  // delay(5000) kullanırsak o sırada butona basılsa da Arduino algılamaz.
  // Bu yüzden 5 saniyeyi 500 adet 10ms'lik parçaya bölüyoruz.

  for (int i = 0; i < 500; i++) {
    if (digitalRead(buton) == HIGH) { 
      yayaTalebi = true; 
    }
    delay(10); 
  }

  //DİKKAT
  digitalWrite(sariArac,HIGH);
  digitalWrite(yesilArac,LOW);
  delay(2000);
  digitalWrite(sariArac, LOW); // Bir sonraki döngü için sarıyı söndür

}

```



https://github.com/user-attachments/assets/f33d0e26-7989-48fd-90ea-91df4363e18c



https://github.com/user-attachments/assets/be89a290-d22e-4f58-9f11-49512ebeefa5


