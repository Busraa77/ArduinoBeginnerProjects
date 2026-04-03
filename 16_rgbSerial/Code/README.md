# Seri Kontrollü RGB LED

Bu proje, Arduino’nun bilgisayardan seri port üzerinden gelen metin verisini okuyup bunu RGB LED renk kontrolüne çevirmesini sağlar; seri haberleşme, pointer ve string işlemleri gibi birkaç yeni kavramı tanıtır. Seri iletişim hattı Arduino'nun dış dünya ile haberleşme yoludur. 

### Devre Kurulumu 
Basit RGB LED bağlantısı yapılır.

### KOD
```
char buffer[18];  //seri porttan gelen metni tutmak için ayrılmış hafıza alanı
int red, green, blue;
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;


void splitString(char* data) { //string’in adresini alıyoruz, kopya değil
  Serial.print("Veri girildi: ");
  Serial.println(data); //girilen veri yaz

  char* parameter; //string parçalarını tutacak
  parameter = strtok(data, " ,");

  while (parameter != NULL) {
    setLED(parameter);
    parameter = strtok(NULL, " ,"); //" ," → boşluk VEYA virgül görünce böl
  }

// buffer temizle
  for (int x = 0; x < 16; x++) {
    buffer[x] = '\0';
  }

  Serial.flush();
}

void setLED(char* data) {

  if ((data[0] == 'r') || (data[0] == 'R')) {
    int Ans = strtol(data + 1, NULL, 10); //strtol: string → integer çevirir
    Ans = constrain(Ans, 0, 255); //LED için geçerli aralığa sınırlar
    analogWrite(RedPin, Ans);

    Serial.print("Red is set to: ");
    Serial.println(Ans);
  }

  if ((data[0] == 'g') || (data[0] == 'G')) {
    int Ans = strtol(data + 1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(GreenPin, Ans);

    Serial.print("Green is set to: ");
    Serial.println(Ans);
  }

  if ((data[0] == 'b') || (data[0] == 'B')) {
    int Ans = strtol(data + 1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(BluePin, Ans);

    Serial.print("Blue is set to: ");
    Serial.println(Ans);
  }
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  //seri iletişim başlar
  Serial.flush();      // seri hattı temizler
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    int index = 0;
    delay(100);  //buffer dolsun diye bekler, çünkü veri yavaş gelir, kod hızlı çalışır
    int numChar = Serial.available();


    if (numChar > 15) {  //taşmayı önle
      numChar = 15;
    }
    while (numChar--) {
      buffer[index++] = Serial.read();  //seri porttan gelen karakterleri tek tek okur , 1byte veri okur.
    }
    buffer[index] = '\0';  // string sonu
    splitString(buffer);
  }
}

```

https://github.com/user-attachments/assets/9aea1e1c-2590-47a5-844b-3541f9771cd4





https://github.com/user-attachments/assets/d670ef3b-9d41-494a-80a8-7ed16af38a6f

