#include <Servo.h>

const int motor_1 = 4;
const int motor_2 = 5;
const int motor_3 = 6;
const int motor_4 = 7;

const int left_sensor = 8;
const int middle_sensor = 9;
const int right_sensor = 10;
const int servo_pin = 11;
const int water_pump = 12;

Servo myservo;
int pos = 0;

void setup() {
  pinMode(water_pump, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  pinMode(motor_3, OUTPUT);
  pinMode(motor_4, OUTPUT);
  pinMode(left_sensor, INPUT);
  pinMode(middle_sensor, INPUT);
  pinMode(right_sensor, INPUT);

  myservo.write(90);                    // Note: servo not attached yet (may have no effect)
  digitalWrite(motor_1, LOW);
  digitalWrite(motor_2, LOW);
  digitalWrite(motor_3, LOW);
  digitalWrite(motor_4, LOW);
  digitalWrite(water_pump, HIGH);       // Relay active-LOW → HIGH = pump off
}

void loop() {
  if (digitalRead(middle_sensor) == LOW) {              // Front flame detected
    // Move forward briefly
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, HIGH);
    digitalWrite(motor_3, LOW);
    digitalWrite(motor_4, HIGH);
    delay(3000);

    // Stop
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);
    digitalWrite(motor_3, LOW);
    digitalWrite(motor_4, LOW);
    delay(15);

    // Activate pump
    digitalWrite(water_pump, LOW);
    delay(15);

    // Attach servo and sweep 90° → 180° → 90° (4 times)
    myservo.attach(servo_pin);
    for (int j = 0; j < 4; j++) {
      for (pos = 90; pos <= 180; pos += 1) {
        myservo.write(pos);
        delay(15);
      }
      for (pos = 180; pos >= 90; pos -= 1) {
        myservo.write(pos);
        delay(15);
      }
    }
    myservo.detach();
  }
  else if (digitalRead(left_sensor) == LOW) {           // Left flame detected
    // Turn left
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, HIGH);
    digitalWrite(motor_3, HIGH);
    digitalWrite(motor_4, LOW);
    delay(2000);

    delay(15);

    // Stop
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);
    digitalWrite(motor_3, LOW);
    digitalWrite(motor_4, LOW);
    delay(1000);

    // Activate pump
    digitalWrite(water_pump, LOW);
    delay(15);

    // Attach servo and sweep 90° → 180° → 90° (4 times)
    myservo.attach(servo_pin);
    for (int j = 0; j < 4; j++) {
      for (pos = 90; pos <= 180; pos += 1) {
        myservo.write(pos);
        delay(15);
      }
      for (pos = 180; pos >= 90; pos -= 1) {
        myservo.write(pos);
        delay(15);
      }
    }
    myservo.detach();
  }
  else if (digitalRead(right_sensor) == LOW) {          // Right flame detected
    // Turn right
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);
    digitalWrite(motor_3, LOW);
    digitalWrite(motor_4, HIGH);
    delay(2000);

    // Stop
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);
    digitalWrite(motor_3, LOW);
    digitalWrite(motor_4, LOW);
    delay(1000);

    delay(15);

    // Activate pump
    digitalWrite(water_pump, LOW);
    delay(15);

    // Attach servo and sweep 90° → 180° → 90° (4 times)
    myservo.attach(servo_pin);
    for (int j = 0; j < 4; j++) {
      for (pos = 90; pos <= 180; pos += 1) {
        myservo.write(pos);
        delay(15);
      }
      for (pos = 180; pos >= 90; pos -= 1) {
        myservo.write(pos);
        delay(15);
      }
    }
    myservo.detach();
  }

  // Default (no flame detected) → stop motors and turn pump off
  digitalWrite(motor_1, LOW);
  digitalWrite(motor_2, LOW);
  digitalWrite(motor_3, LOW);
  digitalWrite(motor_4, LOW);
  digitalWrite(water_pump, HIGH);
}
