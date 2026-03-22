int led=7;
int butonAc=8;
int butonKapat =9;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(butonAc,INPUT);
  pinMode(butonKapat,INPUT);

}

void loop() {
 bool ac = digitalRead(butonAc);
 bool kapat = digitalRead(butonKapat);

 if(kapat==HIGH)
 digitalWrite(led,HIGH);
 else if(ac==HIGH)
 digitalWrite(led,LOW);

}
