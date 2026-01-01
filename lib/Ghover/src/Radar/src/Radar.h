#ifndef RADAR_DIRECTION_H
#define RADAR_DIRECTION_H

#include "TFLuna_Serial.h"

#include <Servo.h>

enum class RadarState {
    IDLE,
    SCANNING,
};

class Radar {
public:
    Radar(int servoPin, Stream& serialPort);
    void begin();
    void update();
    int getDirection(); // Returns direction in degrees   
    int activate(); // Activates the radar system
    void calculateDirection();
    uint16_t getDistance() const;
    uint8_t getStrength() const;
    float getTemperature() const;
    void getRadarState(RadarState& outState) const {
        outState = state;
    }
private:
    int currentDirection;
    bool readSensors();
    TFLuna_Serial radarLuna;
    RadarState state;
    int16_t distance;
    int16_t strength;
    float temperature;
    
};

#endif // RADAR_DIRECTION_H