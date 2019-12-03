#include "LDStream.h"

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

    }

    void LDStream::beginn(long Speed){
        LDStream::Speed = Speed;
    }

} // namespace LD