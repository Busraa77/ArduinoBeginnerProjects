# BASİT LCD KONTROLÜ

Bu proje Arduino ve 16x2 LCD kullanılarak yazı oluşturmayı göstermektedir. 

### Çalışma Mantığı
LCD normalde 8-bit çalışır. Bu şekilde çalışırken D0-D7 pinleri arası 8 veri pini kullanılır. 
Bir karakter tek seferde gönderilir. 
Ama biz projelerde fazla pin harcamamak ve kolay bağlantı için 4-bit mode ile kullanacağız. 
Bu kullanımda D4-D7 pinleri veri için kullanılır. Veri tek seferde değil ikiye bölünerek kullanılır.

### LCD Pin Açıklamaları
- VSS: GND bağlantısıdır.  
- VDD: +5V besleme pinidir.  
- V0 / VEE: Kontrast ayar pinidir. LCD üzerindeki yazının koyuluk/netlik ayarı yapılır. Genellikle potansiyometrenin orta bacağına bağlanır.  
  
- RS (Register Select): LCD’ye gönderilen bilginin komut mu yoksa veri mi olduğunu belirler.  
  * `0` → Komut  
  * `1` → Veri (karakter)  
- RW (Read/Write): LCD ile veri alışveriş yönünü belirler.  
  * `0` → Yazma modu  
  * `1` → Okuma modu  
- E (Enable): LCD’ye gönderilen verinin işlenmesini sağlayan tetikleme pinidir. Enable sinyali geldiğinde LCD veri yolundaki bilgiyi okur.  


### Bağlantı Şeması
<img width="748" height="710" alt="Ekran görüntüsü 2026-04-29 082619" src="https://github.com/user-attachments/assets/a26c6b21-95df-4a1f-bd51-0c3d4c80340e" />

### Kod
Önce kütüphane eklemeliyiz. Daha sonra lcd(rs,enable,d0....d7) şeklinde tanımlama yapıyoruz(biz 4-bit modda kullandığımız için d4...d7 şeklinde tanımladık.). Ve fonksiyonlarımızı yazıyoruz.
```
#include <LiquidCrystal.h>
  //4-bit LCD bağlantısı
  LiquidCrystal lcd(3,4,7,8,9,10);
void setup() {
  lcd.begin(16,2);

  lcd.setCursor(0, 0);
  lcd.print("SELAM");

  lcd.setCursor(0, 1);
  lcd.print("Merhaba");

  delay(1000);
}
void loop() {
}

```


https://github.com/user-attachments/assets/327d033c-7335-437c-ac25-b5a526ea0937
