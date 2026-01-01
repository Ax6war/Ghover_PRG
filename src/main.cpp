#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Ghover.h>

MotorPins motorPins = {12, 13, 3, 6, 7, 8};



SoftwareSerial altSerial(2, 3); // RX, TX

Radar radar(11, altSerial); // Assuming servo is connected to pin 9

Ghover ghover(motorPins, radar);

uint32_t startTime;

RadarState state;

void setup() {
    Serial.begin(9600);
    altSerial.begin(115200);
    radar.begin();
     startTime = millis();
}


void loop() {
    
    ghover.setDirection(true); // Move forward
    radar.update();
    radar.calculateDirection();
    
    
    uint16_t distance = radar.getDistance();
    //uint8_t strength = radar.getStrength();
    //float temperature = radar.getTemperature();
    
    if(millis() > startTime + 100) {
        startTime = millis();
        //Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(",");
    Serial.println(radar.getDirection());
    //Serial.print(" cm, Strength: ");
    //Serial.print(strength);
    //Serial.print(", Temperature: ");
    //Serial.print(temperature);
    //Serial.println(" C");
    //radar.getRadarState(state);
    //if(state == RadarState::SCANNING){
     //   Serial.println("Radar is SCANNING");
    //} else {
    //    Serial.println("Radar is IDLE");
    //} 
    //Serial.print("Direction: ");
    //Serial.print(radar.getDirection()); 
    }
    
}
