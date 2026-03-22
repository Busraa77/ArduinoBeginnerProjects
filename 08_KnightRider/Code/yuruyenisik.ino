
int leds[] = { 7, 8, 9, 10, 11, 12 };

const int sure = 50;

void setup() {

  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void loop() {

  for (int x = 0; x < 6; x++) {
    digitalWrite(leds[x], HIGH);
    delay(sure);
    digitalWrite(leds[x], LOW);
  }

  for (int x = 4; x > 0; x--) {
    digitalWrite(leds[x], HIGH);
    delay(sure);
    digitalWrite(leds[x], LOW);
  }
}
