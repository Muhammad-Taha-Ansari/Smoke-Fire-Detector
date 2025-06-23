#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD at address 0x27 with 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int flameSensorPin = A1;    // Flame sensor analog input pin
const int mq2SensorPin = A0;      // MQ2 sensor analog input pin
const int fanRelayPin = A2;       // Relay to control exhaust fan
const int pumpRelayPin = A3;      // Relay to control water pump
const int buzzerPin = 8;          // Buzzer control pin

// Thresholds
const int smokeThreshold = 300;
const int smokeLowThreshold = 200;
const int flameThreshold = 400;

const int buzzerToneFreq = 1000; // 1kHz buzzer tone

void setup() {
  pinMode(flameSensorPin, INPUT);
  pinMode(mq2SensorPin, INPUT);
  pinMode(fanRelayPin, OUTPUT);
  pinMode(pumpRelayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(fanRelayPin, LOW);
  digitalWrite(pumpRelayPin, LOW);
  digitalWrite(buzzerPin, LOW);

  Serial.begin(9600);
  Serial.println("Smoke and Fire Detector");

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SMOKE & FIRE");
  lcd.setCursor(0, 1);
  lcd.print("DETECTOR READY");
  delay(10000);
}

void loop() {
  int flameValue = analogRead(flameSensorPin);
  int smokeValue = analogRead(mq2SensorPin);

  bool fireDetected = (flameValue < flameThreshold);
  bool smokeDetected = (smokeValue >= smokeThreshold);

  Serial.print("Flame Sensor: ");
  Serial.print(flameValue);
  Serial.print(" | Smoke Sensor: ");
  Serial.println(smokeValue);

  // Control water pump
  if (fireDetected) {
    digitalWrite(pumpRelayPin, HIGH);
  } else {
    digitalWrite(pumpRelayPin, LOW);
  }

  // Control fan with hysteresis
  static bool fanOn = false;
  if (smokeDetected && !fanOn) {
    digitalWrite(fanRelayPin, HIGH);
    fanOn = true;
  } else if (!smokeDetected && fanOn && smokeValue < smokeLowThreshold) {
    digitalWrite(fanRelayPin, LOW);
    fanOn = false;
  }

  // Control buzzer
  if (fireDetected || smokeDetected) {
    tone(buzzerPin, buzzerToneFreq);
  } else {
    noTone(buzzerPin);
  }

  // LCD Display logic
 lcd.clear();
if (fireDetected && smokeDetected) {
  lcd.setCursor(0, 0);
  lcd.print("FIRE ALERT!!!");
  lcd.setCursor(0, 1);
  lcd.print("STAY CALM & EXIT");
} else if (fireDetected) {
  lcd.setCursor(0, 0);
  lcd.print("FIRE ALERT!!!");
  lcd.setCursor(0, 1);
  lcd.print("EVACUATE AREA!");
} else if (smokeDetected) {
  lcd.setCursor(0, 0);
  lcd.print("SMOKE ALERT!!");
  lcd.setCursor(0, 1);
  lcd.print("FAN ON!!");
} else {
  lcd.setCursor(0, 0);
  lcd.print("SYSTEM NORMAL");
  lcd.setCursor(0, 1);
  lcd.print("GROUP D-7");
}

  delay(200);
}
