#include "Motor.h"

Motor::Motor(MotorPins motorPins) {
  this->IN1_PIN = motorPins.IN1_PIN;
  this->IN2_PIN = motorPins.IN2_PIN;
  this->ENA_1_PIN = motorPins.ENA_1_PIN;
  this->ENA_2_PIN = motorPins.ENA_2_PIN;
  this->IN3_PIN = motorPins.IN3_PIN;
  this->IN4_PIN = motorPins.IN4_PIN;

  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(ENA_1_PIN, OUTPUT);
  pinMode(ENA_2_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);
}

void Motor::setSpeed(int speed) {
  analogWrite(ENA_1_PIN, speed);
  analogWrite(ENA_2_PIN, speed);
}

void Motor::setDirection(bool forward) {
  if (forward) {
    digitalWrite(IN1_PIN, HIGH);
    digitalWrite(IN2_PIN, LOW);
    digitalWrite(IN3_PIN, HIGH);
    digitalWrite(IN4_PIN, LOW);
  } else {
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, HIGH);
    digitalWrite(IN3_PIN, LOW);
    digitalWrite(IN4_PIN, HIGH);
  }
}

void Motor::stop() {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, LOW);
}