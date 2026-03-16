void setup() {
  Serial.begin(9600);      // Bilgisayarla haberleşmeyi başlat
  pinMode(10, INPUT);      // Butonun bağlı olduğu pin
  pinMode(11, OUTPUT); 
}

void loop() {
  int butonDurumu = digitalRead(10); // Pin'deki voltajı oku
  
  if(butonDurumu){
  digitalWrite(11, HIGH);
  delay(50);}
  else      
    digitalWrite(11, LOW); 
}
 

