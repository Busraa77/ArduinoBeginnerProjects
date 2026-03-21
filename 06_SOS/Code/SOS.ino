int ledPins = 10;

void setup() {
  pinMode(ledPins, OUTPUT);
}

void S() {
    for (int x = 0; x < 3; x++) {
      digitalWrite(ledPins, HIGH);
      delay(150);
      digitalWrite(ledPins, LOW);
      delay(100);
    }}
void loop() {
  S();
delay(300);
  for (int x = 0; x < 3; x++) {
    digitalWrite(ledPins, HIGH);
    delay(400);
    digitalWrite(ledPins, LOW);
    delay(100);
  }
delay(300);
  S();
  

  delay(5000); // Diğer SOS sinyalinden önce 5 saniye bekle.
}