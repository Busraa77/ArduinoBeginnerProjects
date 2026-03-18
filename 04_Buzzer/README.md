# Buzzer ve LED Alarmı

Projenin amacı buzzer kullanımını öğrenmektir.LED ile senkron şekilde açılıp kapanan bir buzzer devresi kuracağız. 
Buzzer, elektrik enerjisini ses enerjisine dönüştüren küçük ama oldukça etkili bir ses cihazıdır. 
Elektronik projelerde genellikle kullanıcıya bir uyarı, onay veya hata sinyali vermek amacıyla kullanılır.
İki türü vardır:
1. Aktif Buzzer: Bu türün içinde kendi ses üretme devresi (osilatör) bulunur. Çalışma voltajı verdilince ötmeye başlar.
2. Pasif Buzzer: İçinde bir osilatör devresi yoktur.Sadece elektrik vermek yetmez;çok hızlı bir şekilde açılıp kapanan (kare dalga) sinyaller göndermen gerekir. Arduino'daki tone() komutu bunu yapar.
Farklı frekanslarda sinyal göndererek melodi çalabilirsin. Bir hoparlör gibi davranabilir.

## Devre Elemanları
* 220 Ohm'luk direnç (LED için akım sınırlama)
* LED
* Buzzer(Aktif)


## Devre Kurulumu
- LED'in artı bacağı koruyucu dirence bağlanır. Direncin diğer bacağı ise dijital pinimize (12) bağlanır.
- LED'in eksi bacağı GND'ye bağlanır.
- Buzzer'ın + kutbu pinimize (13) bağlanır.
- Buzzer'ın - kutbu GND'ye bağlanır.


https://github.com/user-attachments/assets/68e2d93f-058c-4f28-ba94-23a69044a4a9


https://github.com/user-attachments/assets/2d494db3-0e6a-41a6-b3c9-90efe62aa3e3

