#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
int trigPin = 12;                  //Trig Pin
int echoPin = 11;                  //Echo Pin
int flag = 0;
long duration, cm, inches;
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

}

void loop() {
  testdrawstyles();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);             // 讀取 echo 的電位
  duration = pulseIn(echoPin, HIGH);   // 收到高電位時的時間
  cm = (duration/2) / 29.1;
  Serial.print(cm);
  delay(1000);
}



void testdrawstyles(void) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(F("Ultrasonic Value"));
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.println(cm);
  display.setTextSize(1);
  display.println(flag = !flag);
  display.display();
  delay(500);
}
