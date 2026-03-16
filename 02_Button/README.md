# Buton Uygulaması

Projenin amacı butona basıldığında LED'i yakacak bir pull-down devre oluşturmaktır.

### *Devre Elemanları*
* LED
* Buton
* 10k Ohm'luk direnç


### Devrenin Kurulumu
Pull-down devrede butona basılmadığında pin 0'a yani GND'ye çekilir. Basıldığında ise 1'e çekilir. Bu devreyi oluşturmak için direncin bir ucu GND'ye bağlanır, diğer ucu butondadır. Butonun çapraz ucu 5V'a gider.
İşlemcinin IO10 numaralı pini, buton ile direncin birleştiği düğüm noktasına bağlanır.. LED'in katotu GND'ye çekilir, diğer ucu ise I11'e bağlanır. 

Böylece butona basılmadığında IO10 pini, direnç üzerinden toprağa (GND) bağlı olduğu için 0 sinyali okur.
Butona basıldığında 5V hattı buton üzerinden pini besler; bu hat direnç hattına göre daha az zorluk (direnç) gösterdiği için pin 1 (HIGH) seviyesine yükselir. Böylece mikrodenetleyici butonun basıldığını algılar ve IO11 pinindeki LED'i yakar.




https://github.com/user-attachments/assets/a771849c-1c2c-41dc-afb0-5bbe1ca18b6d

