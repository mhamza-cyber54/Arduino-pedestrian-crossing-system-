#include <Wire.h>
#include <U8g2lib.h>
 
// Task 3: Mini Pedestrian Crossing System
// Default state: STOP with red LED ON
// When button is pressed, OLED shows countdown
// Then buzzer sounds and OLED shows GO
// After crossing time, warning flashes/beeps, then system returns to STOP
 
// OLED display
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);
 
// Pins for Grove Beginner Kit
const int LED_PIN = 4;
const int BUZZER_PIN = 5;
const int BUTTON_PIN = 6;
 
// Timing settings
const int countdownStart = 3;      // Countdown from 3
const int crossingTime = 5000;     // GO time in milliseconds
 
void showStop() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.drawStr(30, 30, "STOP");
  u8g2.sendBuffer();
}
 
void showGo() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.drawStr(40, 30, "GO");
  u8g2.sendBuffer();
}
 
void showCountdown(int num) {
  char buffer[5];
  sprintf(buffer, "%d", num);
 
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(30, 20, "WAIT");
  u8g2.setFont(u8g2_font_logisoso24_tr);
  u8g2.drawStr(50, 60, buffer);
  u8g2.sendBuffer();
}
 
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
 
  u8g2.begin();
 
  // Default STOP state
  digitalWrite(LED_PIN, HIGH);
  showStop();
}
 
void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    delay(200);  // debounce delay
 
    if (digitalRead(BUTTON_PIN) == HIGH) {
 
      // Countdown before crossing
      for (int i = countdownStart; i > 0; i--) {
        showCountdown(i);
        delay(1000);
      }
 
      // Buzzer beep before GO
      tone(BUZZER_PIN, 1000);
      delay(200);
      noTone(BUZZER_PIN);
 
      // GO state
      digitalWrite(LED_PIN, LOW);
      showGo();
      delay(crossingTime);
 
      // Warning before returning to STOP (optional extension)
      for (int i = 0; i < 3; i++) {
        digitalWrite(LED_PIN, HIGH);
        tone(BUZZER_PIN, 1200);
        delay(150);
 
        digitalWrite(LED_PIN, LOW);
        noTone(BUZZER_PIN);
        delay(150);
      }
 
      // Return to STOP state
      digitalWrite(LED_PIN, HIGH);
      showStop();
 
      // Wait until button is released
      while (digitalRead(BUTTON_PIN) == HIGH) {
        delay(10);
      }
    }
  }
}
