#include <Servo.h>

// Servo Tanımlamaları
Servo leftServo;
Servo rightServo;

const int PIN_SERVO_LEFT = 9;
const int PIN_SERVO_RIGHT = 10;
const int PIN_TRIGGER = 2;
const int PIN_EYE_LED = 6;

// Açı Sınırları (Mekanik yapıya göre ayarlanabilir)
const int LEFT_CLOSED = 0;
const int LEFT_OPEN = 110;
const int RIGHT_CLOSED = 180;
const int RIGHT_OPEN = 70;

bool isHelmetOpen = false;
int lastButtonState = LOW;

void setup() {
  pinMode(PIN_TRIGGER, INPUT);
  pinMode(PIN_EYE_LED, OUTPUT);
  
  leftServo.attach(PIN_SERVO_LEFT);
  rightServo.attach(PIN_SERVO_RIGHT);
  
  // Başlangıç: Kapalı Konum
  leftServo.write(LEFT_CLOSED);
  rightServo.write(RIGHT_CLOSED);
  digitalWrite(PIN_EYE_LED, HIGH);
}

void loop() {
  int buttonState = digitalRead(PIN_TRIGGER);

  // Butona basıldığında durumu değiştir
  if (buttonState == HIGH && lastButtonState == LOW) {
    delay(50); // Debounce gecikmesi
    if (isHelmetOpen) {
      closeHelmet();
    } else {
      openHelmet();
    }
    isHelmetOpen = !isHelmetOpen;
  }
  lastButtonState = buttonState;
}

void openHelmet() {
  // Gözleri yavaşça söndür
  for (int b = 255; b >= 0; b -= 15) {
    analogWrite(PIN_EYE_LED, b);
    delay(15);
  }
  
  // Servoları pürüzsüz aç
  for (int i = 0; i <= 100; i += 5) {
    int leftAngle = map(i, 0, 100, LEFT_CLOSED, LEFT_OPEN);
    int rightAngle = map(i, 0, 100, RIGHT_CLOSED, RIGHT_OPEN);
    
    leftServo.write(leftAngle);
    rightServo.write(rightAngle);
    delay(20);
  }
}

void closeHelmet() {
  // Servoları pürüzsüz kapat
  for (int i = 0; i <= 100; i += 5) {
    int leftAngle = map(i, 0, 100, LEFT_OPEN, LEFT_CLOSED);
    int rightAngle = map(i, 0, 100, RIGHT_OPEN, RIGHT_CLOSED);
    
    leftServo.write(leftAngle);
    rightServo.write(rightAngle);
    delay(20);
  }
  
  // Gözleri yak ve efekt ver
  delay(100);
  digitalWrite(PIN_EYE_LED, HIGH);
  delay(80);
  digitalWrite(PIN_EYE_LED, LOW);
  delay(80);
  digitalWrite(PIN_EYE_LED, HIGH);
}
