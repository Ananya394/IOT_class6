#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int lm35_pin = A0;  
LiquidCrystal_I2C lcd(0x27, 16, 2);  

String scrollingMessage = "Sumaia, Ummatun, Nishat Tasnim Mon, Tawhid, Mredul, Ismail Hossain! ";
int scrollIndex = 0;  

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  int temp_adc_val = analogRead(lm35_pin);
  Serial.println(temp_adc_val);
  float temp_val = (temp_adc_val * 4.88) / 10;  

  lcd.setCursor(0, 0);
  lcd.print("Temp = ");
  lcd.print(temp_val);
  lcd.print(" C   ");  

  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    lcd.print(scrollingMessage[(scrollIndex + i) % scrollingMessage.length()]);
  }

  scrollIndex = (scrollIndex + 1) % scrollingMessage.length();
  delay(500);
}
