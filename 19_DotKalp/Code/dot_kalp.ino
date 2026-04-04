
#include <TimerOne.h>

int latchPin = 8;   
int clockPin = 12; 
int dataPin = 11;   

byte led[8];

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  led[0] = B10111011;
  led[1] = B00010001;
  led[2] = B00000001;
  led[3] = B00000001;
  led[4] = B00000001;
  led[5] = B10000011;
  led[6] = B11000111;
  led[7] = B11101111;

  Timer1.initialize(10000);
  Timer1.attachInterrupt(screenUpdate);
}

void loop() {
  delay(500);
}
void screenUpdate() {
  byte row = B10000000;

  for (byte k = 0; k < 8; k++) {
    digitalWrite(latchPin, LOW);
    shiftIt(led[k]);
    shiftIt(row);
    digitalWrite(latchPin, HIGH);
    row = row >> 1;
  }
}
void shiftIt(byte dataOut) {  
  boolean pinState;

  digitalWrite(dataPin, LOW);

  // 8 bit gönder
  for (int i = 0; i < 8; i++) {
    digitalWrite(clockPin, LOW);
    if (dataOut & (1 << i)) {
      pinState = HIGH;
    } else {
      pinState = LOW;
    }
    digitalWrite(dataPin, pinState);
    digitalWrite(clockPin, HIGH);
    digitalWrite(dataPin, LOW);
  }
  digitalWrite(clockPin, LOW);
}