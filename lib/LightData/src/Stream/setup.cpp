#include "LDStream.h"
#include <Arduino.h>

namespace LD
{
/*setup functions*/


    void LDStream::setrecieve(unsigned char recievePin)
    {
        LDStream::recievePin=recievePin;
        LDStream::recieve=true;
    }
    void LDStream::settransmit(unsigned char transmitPin)
    {
        LDStream::transmitPin=transmitPin;
        LDStream::transmit=true;
    }
    void LDStream::setPins(unsigned char transmitPin,unsigned char recievePin)
    {
        LDStream::transmitPin=transmitPin;
        LDStream::transmit=true;
        LDStream::recievePin=recievePin;
        LDStream::recieve=true;
    }

    void LDStream::beginn(){
        if (LDStream::recieve)
        {
            pinMode(LDStream::recievePin, CHANGE);
            attachInterrupt(digitalPinToInterrupt(LDStream::recievePin), LDStream::ISRfunc , CHANGE);
        }
        /* TODO: add beginn for transmit */
    }

    void LDStream::beginn(long Speed){
        LDStream::Speed = Speed;
        if (LDStream::recieve)
        {
            pinMode(LDStream::recievePin, CHANGE);
            attachInterrupt(digitalPinToInterrupt(LDStream::recievePin), LDStream::ISRfunc , CHANGE);
        }/* TODO: add beginn for transmit */
    }

    static void LDStream::ISRfunc(){
        LDStream::instance->dataStream();
    }

} // namespace LD