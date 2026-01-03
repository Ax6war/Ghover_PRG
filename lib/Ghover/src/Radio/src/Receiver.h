#ifndef RECEIVER_H
#define RECEIVER_H

#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

struct Data_Package_Rcv{
    uint8_t command[10];
    unsigned long timestamp;
};

struct Data_Package_Snd{
    uint8_t status[10];
    unsigned long timestamp;
};

class Receiver{
    public:
        Receiver(uint16_t CE_Pin, uint16_t CS_Pin);   
        void begin();
        void setParameters(bool AutoAck,rf24_datarate_e rate, rf24_pa_dbm_e level);
        void receiveData(Data_Package_Rcv &data, Data_Package_Snd &outData);
    private:
        RF24 *radio;
        const byte address_Slave[5] = {'R','X','G','^','A'};
        const byte address_Master[5] = {'T','X','G','^','A'};
        int packageSize;
        bool newData;
        void sendData(Data_Package_Snd &data);




};












#endif