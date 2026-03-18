int ledPin = 12;
int buzzerPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH); 
  digitalWrite(buzzerPin, HIGH);
  delay(500); // 0.5 saniye çalış
  
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(500); // 0.5 saniye sus
}