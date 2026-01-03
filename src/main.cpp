#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Ghover.h>

MotorPins motorPins = {0, 0, 0, 0, 0, 0};

SoftwareSerial altSerial(2, 3); // RX, TX

Radar radar(5, altSerial); // Assuming servo is connected to pin 9

Receiver receiver(7, 8); // CE, CSN pins

Ghover ghover(motorPins, radar, receiver);

uint32_t startTime = 0;

RadarState state;

Data_Package_Rcv dataPackage_rcv;
Data_Package_Snd dataPackage_snd;

unsigned long lastSignalMillis = 0; 

void setup() {
    Serial.begin(9600);
    altSerial.begin(115200);
    receiver.begin();
    receiver.setParameters(false, RF24_250KBPS, RF24_PA_MAX);
    radar.begin();
}


void loop() {
    
    //ghover.setDirection(true); // Move forward
    radar.update();
    radar.calculateDirection();
    
    
    uint16_t distance = radar.getDistance();
    uint8_t strength = radar.getStrength();
    float temperature = radar.getTemperature();



    receiver.receiveData(dataPackage_rcv, dataPackage_snd);  
	dataPackage_snd.status[0] = distance;
    dataPackage_snd.status[1] = distance << 8; 

    if(millis() > startTime + 1000) {
        startTime = millis();
        //Serial.print("Distance: ");
    Serial.print(dataPackage_rcv.command[0]);
    Serial.print(",");
    Serial.print(dataPackage_rcv.timestamp);
    Serial.print(",");
    Serial.println(dataPackage_rcv.command[1]);
    
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
