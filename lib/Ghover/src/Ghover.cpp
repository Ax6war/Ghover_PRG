#include "Ghover.h"

Ghover::Ghover(MotorPins motorPins, Radar radar) : motor(motorPins), radar(radar) {}

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

