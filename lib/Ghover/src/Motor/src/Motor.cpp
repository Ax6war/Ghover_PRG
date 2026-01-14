#include "Motor.h"

Motor::Motor(MotorPins motorPins) {
  this->IN1_PIN = motorPins.IN1_PIN;
  this->IN2_PIN = motorPins.IN2_PIN;
  this->ENA_PIN = motorPins.ENA_PIN;


  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(ENA_PIN, OUTPUT);

}

void Motor::setSpeed(int speed_Pur) {
  this->currentSpeed = speed_Pur;
  speed_Pur = map(speed_Pur, 0, 100, 0, 255);
  analogWrite(ENA_PIN, speed_Pur);
}

int Motor::GetSpeed() {
    return currentSpeed;
}


void Motor::setDirection(Motor_Logic Motor_State) {
  switch (Motor_State)
  {
  case MOTOR_FORWARD:
    digitalWrite(IN1_PIN, HIGH);
    digitalWrite(IN2_PIN, LOW);
    analogWrite(ENA_PIN, currentSpeed);
    break;
  case MOTOR_BACKWARD:
    digitalWrite(IN1_PIN, LOW); 
    digitalWrite(IN2_PIN, HIGH);
    analogWrite(ENA_PIN, currentSpeed);
    break;
  case MOTOR_STOP:
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, LOW);
    analogWrite(ENA_PIN, 0);
    break;
  case MOTOR_COAST:
    digitalWrite(IN1_PIN, HIGH);
    digitalWrite(IN2_PIN, HIGH);
    analogWrite(ENA_PIN, 0);
    break;

  default:
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, LOW);
    analogWrite(ENA_PIN, 0);
    break;
}

}

void Motor::stop() {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  analogWrite(ENA_PIN, 0);
}