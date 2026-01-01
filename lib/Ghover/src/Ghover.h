#ifndef GHOOVER_H
#define GHOOVER_H

#include "Motor/src/Motor.h"

#include "Radar/src/Radar.h"

#include <Servo.h>

class Ghover {
private:
    MotorPins motorPins;
    Motor motor;
    Radar radar;
public:
    Ghover(MotorPins motorPins, Radar radar);
    void setSpeed(int speed);
    void setDirection(bool forward);
    void stop();
    void activateRadar();
    void readRadarData();
};

#endif // GHOOVER_H