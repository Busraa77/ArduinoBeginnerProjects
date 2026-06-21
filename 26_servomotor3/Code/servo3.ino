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