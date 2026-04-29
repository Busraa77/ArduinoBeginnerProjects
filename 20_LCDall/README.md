# LCD ile Farklı Yazımlar Oluşturma

Bu projede:  
- LCD ekran temizleme  
- Yazı yazdırma  
- Cursor kullanımı  
- Özel karakter oluşturma  
- Animasyon mantığı (soldan sağa-sağdan sola kayan yazı)
öğrenmek amaçlanmıştır.


### Bağlantı Şeması
<img width="748" height="710" alt="Ekran görüntüsü 2026-04-29 082619" src="https://github.com/user-attachments/assets/05d469ab-7091-4ffb-8fe3-e4d918a71e3b" />

https://github.com/user-attachments/assets/6f061f97-6dcb-43ce-ac8b-aa2bd06fda7e

### Kod
```
#include <LiquidCrystal.h>
  //4-bit LCD bağlantısı
  LiquidCrystal lcd(3,4,7,8,9,10);
void setup() {


  lcd.begin(16,2);

}
void basicPrintDemo() {
  lcd.clear();
  lcd.print("Basic Print");
  delay(2000);
}
void displayOnOffDemo() {
  lcd.clear();
  lcd.print("Display On/Off");

  for(int x = 0; x < 3; x++) {
    lcd.noDisplay();
    delay(1000);

    lcd.display();
    delay(1000);
  }
}

void setCursorDemo() {
  lcd.clear();
  lcd.print("SetCursor Demo");
  delay(1000);

  lcd.clear();

  lcd.setCursor(5, 0);
  lcd.print("5,0");
  delay(2000);

  lcd.setCursor(10, 1);
  lcd.print("10,1");
  delay(2000);

  lcd.setCursor(3, 1);
  lcd.print("3,1");
  delay(2000);
}

void scrollLeftDemo() {
  lcd.clear();
  lcd.print("Scroll Left Demo");
  delay(1000);

  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("Beginning");

  lcd.setCursor(9, 1);
  lcd.print("Arduino");

  delay(1000);

  for(int x = 0; x < 16; x++) {
    lcd.scrollDisplayLeft();
    delay(250);
  }
}

void scrollRightDemo() {
  lcd.clear();
  lcd.print("Scroll Right");
  lcd.setCursor(0, 1);
  lcd.print("Demo");
  delay(1000);

  lcd.clear();
  lcd.print("Beginning");
  lcd.setCursor(0, 1);
  lcd.print("Arduino");
  delay(1000);

  for(int x = 0; x < 16; x++) {
    lcd.scrollDisplayRight();
    delay(250);
  }
}

void cursorDemo() {
  lcd.clear();

  lcd.cursor();
  lcd.print("Cursor On");
  delay(3000);

  lcd.clear();

  lcd.noCursor();
  lcd.print("Cursor Off");
  delay(3000);

  lcd.clear();

  lcd.cursor();
  lcd.blink();
  lcd.print("Cursor Blink On");
  delay(3000);

  lcd.noCursor();
  lcd.noBlink();
}

void createGlyphDemo() {
  lcd.clear();

  byte happy[8] = {
    B00000,
    B00000,
    B10001,
    B00000,
    B10001,
    B01110,
    B00000,
    B00000
  };

  byte sad[8] = {
    B00000,
    B00000,
    B10001,
    B00000,
    B01110,
    B10001,
    B00000,
    B00000
  };

  lcd.createChar(0, happy);
  lcd.createChar(1, sad);

  for(int x = 0; x < 5; x++) {
    lcd.setCursor(8, 0);
    lcd.write(byte(0));
    delay(1000);

    lcd.setCursor(8, 0);
    lcd.write(1);
    delay(1000);
  }
}

void loop() {
  basicPrintDemo();
  displayOnOffDemo();
  setCursorDemo();
  scrollLeftDemo();
  scrollRightDemo();
  cursorDemo();
  createGlyphDemo();
}
```
