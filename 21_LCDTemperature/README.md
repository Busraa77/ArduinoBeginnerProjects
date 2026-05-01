# Sıcaklık sensörü ile LCD ekrana veri yazma

Projenin amacı sıcaklık sensörü ile sıcaklık ölçmek ve bunu Celcius veya Fahrenheit olarak buton aracılığıyla gösterebilmektir.

<img width="632" height="477" alt="Ekran görüntüsü 2026-05-01 155611" src="https://github.com/user-attachments/assets/66e9701d-522e-4f8d-ae7c-f984832c21be" />



https://github.com/user-attachments/assets/c29d04ce-0f7e-422c-a039-a21632611c5a





```KOD
#include <LiquidCrystal.h>

LiquidCrystal lcd(3,4,7,8,9,10);
int maxC=0, minC=100, maxF=0, minF=212; //amaç: ilk ölçümde kesin güncellenmesini sağlamak.

int scale=1; // 1 = Celsius, -1 = Fahrenheit
int buttonPin=11;
int sensorPin=A0;

void setup() {
  lcd.begin(16,2);
  analogReference(INTERNAL); //Arduino analog ölçüm yaparken 5V yerine kendi içindeki daha küçük ve hassas 1.1V referansını kullansın.
  pinMode(buttonPin,INPUT);
  lcd.clear();
}

void loop() {
  int sensor=analogRead(sensorPin);
  int buttonState=digitalRead(buttonPin);

  if(buttonState)
  {
    scale=-scale;
    lcd.clear();
    delay(300);
  }

  if(scale==1)
  {
    celsius(sensor);
  }
  else
  {
    fahrenheit(sensor);
  }
  delay(250);

}

void celsius(int sensor)
{
  lcd.setCursor(0,0);

  int temp= sensor * 0.097;

  lcd.print(temp);
  lcd.write(B11011111); //derece sembolü
  lcd.print("C");

  if(temp>maxC)
  {
    maxC=temp;
  }
  if(temp<minC)
  {
    minC=temp;
  }

  lcd.setCursor(0,1);
  lcd.print("H=");
  lcd.print(maxC);
  lcd.write(B11011111);
  lcd.print("C L=");
  lcd.print(minC);
  lcd.write(B11011111);
  lcd.print("C ");
}

void fahrenheit(int sensor)
{
  lcd.setCursor(0,0); //sütun satır

  float temp=((sensor*0.097)*1.8)+32;

  lcd.print((int)temp);
  lcd.write(B11011111);
  lcd.print("F  ");

  if(temp>maxF)
  {
    maxF=temp;
  }
  if(temp<minF)
  {
    minF=temp;
  }
  lcd.setCursor(0, 1);
  lcd.print("H=");
  lcd.print(maxF);
  lcd.write(B11011111);
  lcd.print("F L=");
  lcd.print(minF);
  lcd.write(B11011111);
  lcd.print("F ");
}

```



https://github.com/user-attachments/assets/5cbeb7ed-6e1c-4f43-8c0f-0bdf78103192

