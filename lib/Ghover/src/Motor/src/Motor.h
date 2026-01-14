#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

struct MotorPins
{
    int IN1_PIN;
    int IN2_PIN;
    int ENA_PIN;

};

enum Motor_Logic{
    MOTOR_STOP,
    MOTOR_BACKWARD,
    MOTOR_FORWARD,
    MOTOR_COAST 
};

class Motor {
private:
  int IN1_PIN;
  int IN2_PIN;
  int ENA_PIN;
  int currentSpeed;
  bool currentDirection; // true for forward, false for backward
public:
  Motor(MotorPins motorPins);
  void setSpeed(int speed_Pur); // Set the speed of the motor (0-100%)
  void setDirection(Motor_Logic Motor_State); // Set the direction of the motor (MOTOR_FORWARD or MOTOR_BACKWARD) or (MOOTR_STOP or MOTOR_COAST)
  void stop();  //Stop the motor
  int GetSpeed(); // Get the current speed of the motor (0-100%)
};  

#endif // MOTOR_H