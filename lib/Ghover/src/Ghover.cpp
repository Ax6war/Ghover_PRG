#include "Ghover.h"

Ghover::Ghover(MotorPins motorPins, Radar radar, Receiver receiver) : motor(motorPins), radar(radar), receiver(receiver) {}

void Ghover::setSpeed(int speed) {
    motor.setSpeed(speed);
}

void Ghover::setDirection(bool forward) {
    motor.setDirection(forward);
}

void Ghover::stop() {
    motor.stop();
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
