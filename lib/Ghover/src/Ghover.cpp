#include "Ghover.h"

Ghover::Ghover(MotorPins motorPinsLeft, MotorPins motorPinsRight, Radar radar, Receiver receiver) : motorLeft(motorPinsLeft), motorRight(motorPinsRight), radar(radar), receiver(receiver) {}

void Ghover::setSpeed(int speed) {
    motorLeft.setSpeed(speed);
    motorRight.setSpeed(speed);
}

void Ghover::setDirection(bool forward) {
    motorLeft.setDirection(forward);
    motorRight.setDirection(forward);
}

void Ghover::stop() {
    motorLeft.stop();
    motorRight.stop();
}

void Ghover::activateRadar() {
    radar.calculateDirection(); // Assuming servo is connected to pin 9
}

void Ghover::readRadarData() {
    radar.update();

}


void Ghover::TransmitData(Data_Package_Rcv &data, Data_Package_Snd &outData) {
    receiver.receiveData(data, outData);
}

void Ghover::startReceiver() {
    receiver.setParameters(true, RF24_1MBPS, RF24_PA_HIGH);
}
