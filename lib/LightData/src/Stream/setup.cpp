#include "LDStream.h"
#include <Arduino.h>

namespace LD
{
/*setup functions*/

/*** these functions are explained in LDStream.h***/
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
            //deklares the ISR
            attachInterrupt(digitalPinToInterrupt(LDStream::recievePin), LDStream::ISRfunc , CHANGE);
        }
    }

    void LDStream::beginn(long Speed){
        LDStream::Speed = Speed;
        if (LDStream::recieve)
        {
            pinMode(LDStream::recievePin, CHANGE);
            //deklares the ISR
            attachInterrupt(digitalPinToInterrupt(LDStream::recievePin), LDStream::ISRfunc , CHANGE);
        }
    }


} // namespace LD