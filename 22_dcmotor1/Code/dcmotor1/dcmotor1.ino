
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