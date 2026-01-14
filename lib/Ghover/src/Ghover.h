#ifndef GHOOVER_H
#define GHOOVER_H

#include "Motor/src/Motor.h"

#include "Radar/src/Radar.h"

#include "Radio/src/Receiver.h"

#include <Servo.h>

class Ghover {
private:
    MotorPins motorPinsLeft;
    MotorPins motorPinsRight;
    Motor motorLeft;
    Motor motorRight;
    Radar radar;
    Receiver receiver;
public:
    Ghover(MotorPins motorPinsLeft, MotorPins motorPinsRight, Radar radar, Receiver receiver);
    void setSpeed(int speed);
    void setDirection(bool forward);
    void stop();
    void activateRadar();
    void readRadarData();
    void startReceiver();
    void TransmitData(Data_Package_Rcv &data, Data_Package_Snd &outData);
};

#endif // GHOOVER_H