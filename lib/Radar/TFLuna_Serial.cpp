#include "TFLuna_Serial.h"

const uint8_t TFLuna_Serial::FRAME_HEADER[2] = {0x59, 0x59};



TFLuna_Serial::TFLuna_Serial(Stream& serialPort, uint32_t baudRate){

    this->port = &serialPort;
    this->_baudRate = 115200;
}


bool TFLuna_Serial::readDistance(int16_t& distance, int16_t& strength, float& temperature) {
    static uint8_t index = 0;

    while (port->available()) {
        uint8_t b = port->read();

        // Header sync
        if (index == 0 && b != 0x59) continue;
        if (index == 1 && b != 0x59) {
            index = 0;
            continue;
        }

        frame[index++] = b;

        if (index == FRAME_SIZE) {
            index = 0;

            if (!validateFrame(frame)) return false;

            distance    = frame[2] | (frame[3] << 8);
            strength    = frame[4] | (frame[5] << 8);
            temperature = ((frame[6] | (frame[7] << 8)) / 8.0f) - 256.0f;

            return true;
        }
    }
    return false;
}





bool TFLuna_Serial::validateFrame(const uint8_t* frame) {

    int check = frame[0] + frame[1] + frame[2] + frame[3] + frame[4] + frame[5] + frame[6] + frame[7];

    if(frame[8] == (check & 0xFF)){
        return true;
        
    }
    return false;
}

bool TFLuna_Serial::calculateChecksum(const uint8_t* frame) {
    uint8_t sum = 0;
    
	for (size_t i = 0; i < 8; ++i) {
        sum += frame[i];
	}

	return sum == frame[8];
}
