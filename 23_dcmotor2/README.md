# DC Motor Hız Kontrolü (Potansiyometre + Transistör + PWM)

Bu proje, bir DC motorun hızını bir potansiyometre ile kontrol etmeyi amaçlayan basit bir Arduino uygulamasıdır. Motor, bir transistör üzerinden sürülür ve PWM sinyali ile hız ayarı yapılır.  


### Devre Elemanları
- Arduino (UNO / benzeri)  
- 1x DC Motor  
- 1x NPN Güç Transistörü (TIP120)
- 1x Potansiyometre   
- 1x 1N4001 Diyot (Motor kaynaklı ters voltajlara karşı diyot ile koruma sağlayacağız)  
- 12V Harici Güç Kaynağı


### Devre Çalışma Mantığı
Potansiyometre → Arduino A0 pininden analog değer okur  
Arduino → Bu değeri 0–255 arası PWM sinyaline çevirir  
PWM sinyali → Transistörün base pinini kontrol eder  
Transistör → Motoru harici 12V kaynaktan sürer  
Diyot (1N4001) → Motor kapanırken oluşan ters gerilimi engeller  


Motor doğrudan Arduino’dan beslenmez. Arduino sadece kontrol sinyali üretir. Güç yükü (motor) 12V kaynaktan alınır ve transistör ile anahtarlanır.

```KOD
int pot = A0;
int transistor = 9;
int value=0;

void setup() {
  pinMode(transistor,OUTPUT); 
  pinMode(pot,INPUT);

}

void loop() {
  value= analogRead(pot)/4; //0-1023 arası okuma
  analogWrite(transistor,value);  // Transistöre 0-255 arası olan hesaplananHiz değerini gönder

}

```



https://github.com/user-attachments/assets/1e826851-db41-44d0-9b49-132976799549

