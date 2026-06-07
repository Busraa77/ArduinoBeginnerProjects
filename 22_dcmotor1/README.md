# DC Motor Hız ve Yön Kontrolü (Arduino + L293D)
Bu proje, bir DC motorun Arduino kullanılarak yön ve hız kontrolünü gerçekleştirmektedir. Motor sürücü olarak L293D entegresi kullanılmıştır. Arduino, motor sürücüye düşük güçlü kontrol sinyalleri gönderirken, motor için gerekli yüksek akım harici güç kaynağından sağlanır.

### Kullanılan Bileşenler
- Arduino Uno  
- L293D  
- DC motor  
- Harici güç kaynağı (pil veya adaptör)  
- Jumper kablolar  
- Breadboard (opsiyonel)  


### Çalışma Prensibi
Arduino, L293D’ye IN1 ve IN2 pinleri üzerinden yön bilgisini gönderir.  
EN (Enable) pini üzerinden PWM sinyali gönderilerek motor hızı kontrol edilir.  
L293D, Arduino’dan gelen sinyali yükselterek motoru sürer.  
Motorun gücü Arduino’dan değil, harici güç kaynağından sağlanır.  

  
Arduino pinleri doğrudan motor süremez, sadece kontrol sinyali üretir.  
Motorun ihtiyaç duyduğu akım L293D ve harici güç kaynağı tarafından sağlanmalıdır.  
EN pini LOW olursa motor tamamen devre dışı kalır.  

### Pin Bağlantıları
- IN1 → Arduino dijital pin  
- IN2 → Arduino dijital pin  
- EN → Arduino PWM pin  
- VCC1 → 5V (lojik besleme)   
- VCC2 → Harici motor beslemesi  
- GND → Ortak toprak  

### Kod Mantığı
Motor yönü IN1 = HIGH, IN2 = LOW ile ileri yönde ayarlanır.  
PWM değeri 0’dan 255’e artırılarak motorun hızı kademeli olarak yükseltilir.  
Daha sonra motor durdurulur ve kısa bir bekleme yapılır.  


´´´ KOD


int in1=7;
int in2=8;
int en=9; 

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(en,OUTPUT);

}

void loop() {

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  for (int i = 80; i < 255; i++) {
    analogWrite(en, i);
    delay(10);
  }

  analogWrite(en, 0);   // motor stop
  delay(1000);
}
´´´

https://github.com/user-attachments/assets/fd79958e-4c7a-453e-ba45-74082df34cc7
