# Seri Port Komutları ile Çift Servo Motor Kontrolü

Bu proje, bilgisayardan (Seri Monitör üzerinden) gönderilen metin tabanlı komutları anlık olarak ayrıştırarak iki adet servo motoru (Sol ve Sağ) bağımsız olarak kontrol etmeyi sağlar. Proje, gelişmiş C dili metin işleme fonksiyonları (`strtok`, `strtol`) ve dinamik bellek yönetimini anlamak için harika bir örnektir.

## Proje Çalışma Mantığı

Proje, Seri Port'tan gelen verileri üç aşamalı bir mimariyle işler:

1. **Veri Toplama (`while (numChar--)`):** Seri porttan gelen karakterler (`L45`, `R120` vb.) sırayla okunur ve 10 elemanlı bir `buffer` (arabellek) dizisine karakter karakter dizilerek anlamlı bir metne dönüştürülür.
2. **Metin Parçalama (`splitString`):** `strtok()` fonksiyonu devreye girerek gelen ham metni boşluk (`" "`) veya virgül (`","`) işaretlerinden keser. Örneğin tek seferde gönderilen `"L45 R120"` komutunu `"L45"` ve `"R120"` olarak iki bağımsız parçaya (token) ayırır.
3. **Komut Çözümleme ve Sürücü (`setServo`):** * Gelen parçanın ilk harfine bakılır (`data[0]`). `'L'` veya `'l'` ise Sol motor (Pin 5), `'R'` veya `'r'` ise Sağ motor (Pin 6) seçilir.
   * `strtol(data + 1, NULL, 10)` komutuyla harften sonra gelen metin kısmı (örneğin `"45"`) matematiksel bir tam sayıya dönüştürülür.
   * `constrain()` kontrolünden geçen güvenli açı değeri `servo.write()` ile motora iletilir.

## Donanım Bağlantıları

Projede iki adet standart servo motor kullanılır. Sinyal pinleri Arduino'nun donanımsal PWM pinlerine bağlanmalıdır.

| Bileşen / Motor | Arduino Pini |
| :--- | :--- | 
| **Servo 1 (Sol - Left)** | Dijital Pin 5 (PWM) |
| **Servo 2 (Sağ - Right)** | Dijital Pin 6 (PWM) |
| **Ortak Hatlar** | 5V ve GND | 

Daha detaylı bağlantı bilgisi için servomotor1 projesine bakabilirsiniz.

⚠️ **Not:** Servo motorların kararlı çalışabilmesi ve Arduino'nun reset atmasını engellemek için motorların harici bir 5V güç kaynağından beslenmesi ve harici kaynağın GND hattı ile Arduino GND hattının birleştirilmesi (Ortak GND) önerilir.

## Çalışma

Proje yüklendikten sonra Arduino IDE üzerinden **Seri Monitör (Serial Monitor)** ekranını açın ve baud rate değerini **9600** olarak ayarlayın. Aşağıdaki formatlarda komut gönderebilirsiniz:

* `L45` $\rightarrow$ Sol servoyu 45 dereceye getirir.
* `R180` $\rightarrow$ Sağ servoyu 180 dereceye getirir.
* `L90 R135` $\rightarrow$ Tek satırda hem sol servoyu 90'a, hem sağ servoyu 135'e getirir (Komutlar arası boşluk bırakılmalıdır).



<img width="500" height="350" alt="Ekran görüntüsü 2026-06-21 140208" src="https://github.com/user-attachments/assets/29d045ac-1513-43ad-ba6e-a582863bf5ca" />


<img width="500" height="350" alt="Ekran görüntüsü 2026-06-21 140124" src="https://github.com/user-attachments/assets/74090b4f-5951-43fe-9e74-cbc274a50f26" />

## KOD

```cpp
#include <Servo.h>

Servo servo1;
Servo servo2;

char buffer[10];

void setup() {
  Serial.begin(9600);

  servo1.attach(5);
  servo2.attach(6);

  servo1.write(90); //orta konum
  servo2.write(90);

  Serial.println("STARTING...");

}

void loop() {
  if(Serial.available()>0) //seri porttan veri geldi mi?
{
  int index=0;
  delay(100); //buffera dolması için

  int numchar = Serial.available();
  if(numchar>0)
  {numchar=10;} //sınır koruma buffer[10]

  while(numchar--)
  {
    buffer[index++]=Serial.read();//karakterleri buffer dizisine kaydet
  }
  splitString(buffer);
}
}

void splitString(char* data)
{
  Serial.print("Data girişi: ");
  Serial.println(data);

char*parameter;
parameter=strtok(data," ,"); // Boşluk veya virgüle göre metni parçala
  /*strtok (String Tokenizer), uzun bir metni verdiğin işaretlere (burada boşluk " " veya virgül ",") bakarak parçalara böler.*/
  
  while(parameter!=NULL)
  {
    setServo(parameter);
    parameter=strtok(NULL," ,");  
    }

    for(int i=0;i<10;i++)
    {
      buffer[i] = '\0'; //Null Terminator (Sonlandırıcı)
    }
}

void setServo(char* data)
{
  if(data[0]=='L' || data[0]=='l')
  {
    int firstVal=strtol(data+1,NULL,10);
    firstVal=constrain(firstVal,0,180); // 0-180 derece arasında sınırla
    servo1.write(firstVal);
    Serial.print("Servo1 şuna ayarlandı: ");
    Serial.println(firstVal);
  }
if(data[0]=='R' || data[0]=='r')
  {
    int secondVal=strtol(data+1,NULL,10); // Harften sonra gelen kısmı (data+1) sayıya dönüştür
    secondVal=constrain(secondVal,0,180);
    servo2.write(secondVal);
    Serial.print("Servo2 şuna ayarlandı: ");
    Serial.println(secondVal);
  }


}
```


Videoda sırasıyla l25 , r50,l180 komutları verildi.

https://github.com/user-attachments/assets/06f60a08-7c30-4aea-94c6-b958bc8d9525

