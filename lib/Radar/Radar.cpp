
#include "Radar.h"

#include <Arduino.h>



Servo radarServo;

Radar::Radar(int servoPin, Stream& serialPort) : currentDirection(90.0f), radarLuna(TFLuna_Serial(serialPort, 115200)), state(RadarState::IDLE),
    distance(0), strength(0), temperature(0.0f) {
    
}

void Radar::begin() {
    radarServo.attach(11); // Assuming servo is connected to pin 9
    radarServo.write(90); // Center the servo
}

void Radar::update() {
    if(readSensors()){

        state = RadarState::SCANNING;
    } else {
        state = RadarState::IDLE;
    }
    //calculateDirection();
}

int Radar::getDirection() {
    return currentDirection;
}

int Radar::activate() {
    // Code to activate the radar system
    // Return status code (e.g., 0 for success)
    return 0;
}

bool Radar::readSensors() {
    
    if(radarLuna.readDistance(distance, strength, temperature)){
        return true;
    };
    return false;
    
}

void Radar::calculateDirection() {
    static int angle = 0;           // current angle
    static int8_t direction = 1;    // +1 = forward, -1 = backward
    static uint32_t lastMoveTime = 0;

    const uint32_t stepDelay = 10; // ms per step

    if (millis() - lastMoveTime >= stepDelay) {
        lastMoveTime = millis();

        angle += direction;

        if (angle >= 90) {
            angle = 90;
            direction = -1;
        } 
        else if (angle <= 0) {
            angle = 0;
            direction = 1;
        }

        radarServo.write(angle);
        currentDirection = angle;
    }
}

uint16_t Radar::getDistance() const {
    return this->distance;
}

uint8_t Radar::getStrength() const {
    return this->strength;
}

float Radar::getTemperature() const {
    return this->temperature;
}
   


    

