#include <LiquidCrystal.h>
  //4-bit LCD bağlantısı
  LiquidCrystal lcd(3,4,7,8,9,10);
void setup() {


  lcd.begin(16,2);

  lcd.setCursor(0, 0);
  lcd.print("SELAM");

  lcd.setCursor(0, 1);
  lcd.print("Merhaba");

  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

}
