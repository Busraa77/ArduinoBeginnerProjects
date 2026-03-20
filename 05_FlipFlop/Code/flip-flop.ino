
int kirmizi=9;
int yesil=10;
int mavi = 11;

void setup() {
  pinMode(mavi,OUTPUT);
  pinMode(kirmizi,OUTPUT);
  pinMode(yesil,OUTPUT);
}

void loop() {
  renkSec(255,255,0);
  delay(1000);

  renkSec(0,255,255);
  delay(1000);
}

void renkSec(int r, int g, int b)
{
analogWrite(kirmizi,r);
analogWrite(yesil,g);
analogWrite(mavi,b);
}