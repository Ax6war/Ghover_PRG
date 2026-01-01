#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

struct MotorPins
{
    int IN1_PIN;
    int IN2_PIN;
    int ENA_1_PIN;
    int ENA_2_PIN;
    int IN3_PIN;
    int IN4_PIN;
};
class Motor {
private:
  int IN1_PIN;
  int IN2_PIN;
  int ENA_1_PIN;
  int ENA_2_PIN;
  int IN3_PIN;
  int IN4_PIN;
public:
  Motor(MotorPins motorPins);
  void setSpeed(int speed);
  void setDirection(bool forward);
  void stop();  
};  

#endif // MOTOR_H