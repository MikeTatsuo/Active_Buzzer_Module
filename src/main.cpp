#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define BUZZER 3

int counter = 60;
int interval = 10;
int buzzingTime = 50;

void setup() {
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Active Buzzer Module");

  lcd.setCursor(0, 2);
  lcd.print("Countdown: ");
}

void loop() {
  if (counter >= 0) {
    lcd.setCursor(11, 2);
    lcd.print(counter);
    lcd.print(' ');

    if (counter == 0) {
      buzzingTime = 1000;
    }

    if (!(counter % interval)){
      lcd.setCursor(0, 1);
      lcd.print("***** BUZZING ******");
      lcd.setCursor(0, 3);
      lcd.print("***** BUZZING ******");
      digitalWrite(BUZZER, HIGH);
      delay(buzzingTime);

      lcd.setCursor(0, 1);
      lcd.print("                    ");
      lcd.setCursor(0, 3);
      lcd.print("                    ");
      digitalWrite(BUZZER, LOW);
      delay(1000 - buzzingTime);
    } else {
      delay(1000);
    }

    if (counter == 30) {
      interval = 5;
    }

    if (counter == 10) {
      interval = 1;
    }
    
    counter--;
  }
}