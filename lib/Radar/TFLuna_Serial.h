#ifndef TFLUNA_SERIAL_H
#define TFLUNA_SERIAL_H

#include <Arduino.h>


#define FRAME_SIZE 9

class TFLuna_Serial {
public:
    TFLuna_Serial(Stream& port, uint32_t baudRate = 115200);
    bool readDistance(int16_t& distance, int16_t& strength, float& temperature);

private:
    Stream* port;    
    uint32_t _baudRate;
    static const uint8_t FRAME_HEADER[2];
    bool validateFrame(const uint8_t* frame);
    bool calculateChecksum(const uint8_t* frame);
    uint8_t frame[FRAME_SIZE];
    
};

#endif // TFLUNA_SERIAL_H