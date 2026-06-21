#include <Servo.h>

Servo servo1;
void setup() {
  servo1.attach(9);

}

void loop() {
  int angle=analogRead(0);
  angle = map(angle, 0, 1023, 0, 180);
/* Benim elimde angle adında bir değer var. 
   Bu değerin içindeki sayı potansiyometrenin konumuna göre en az 0, en fazla 1023 olabilir. 
   Sen bu sayıyı al; eğer 0'a yakınsa 0'a, 1023'e yakınsa 180'e oranla ve bana yeni bir sayı üret. */
  servo1.write(angle);
  delay(15);

}
