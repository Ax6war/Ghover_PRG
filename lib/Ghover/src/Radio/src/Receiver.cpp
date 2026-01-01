#include "Receiver.h"

Receiver::Receiver(uint16_t CE_Pin, uint16_t CS_Pin) {
    radio = new RF24(CE_Pin, CS_Pin);
    
}   

void Receiver::begin(){
    radio->begin();
}


void Receiver::setParameters(bool AutoAck,rf24_datarate_e rate, rf24_pa_dbm_e level){
    packageSize = sizeof(Data_Package_Rcv);
    radio->setPayloadSize(packageSize);
    radio->openReadingPipe(1, address_Slave);
    radio->openWritingPipe(address_Master);
    radio->setAutoAck(AutoAck);
    radio->setDataRate(rate);
    radio->setPALevel(level);
    radio->setRetries(3,5);
    radio->startListening();
}

void Receiver::receiveData(Data_Package_Rcv &data, Data_Package_Snd &outData){
    if(radio->available()){
        radio->read(&data, packageSize);
        newData = true;
    }
    sendData(outData);
        // Data send failed;    

}


void Receiver::sendData(Data_Package_Snd &data){
    // Fill dataToSend with relevant status information
if(newData){
   radio->stopListening();
    bool rslt;
    rslt = radio->write( &data, sizeof(data) );
    radio->startListening();

    
    newData = false;
    rslt = false;
}
}