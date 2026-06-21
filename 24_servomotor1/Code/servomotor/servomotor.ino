#include <Servo.h>
Servo myservo;

int pos=0; //position


void setup() {
 myservo.attach(9);
}

void loop() {
   for(pos=0;pos<=180;pos+=1)
  {
    myservo.write(pos); //Motora pos değerinin açısına git emri
    delay(15); 
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
  myservo.write(pos);              
  delay(15);                       
}
}
