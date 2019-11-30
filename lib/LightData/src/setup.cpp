#include "LightData.h"

namespace LD
{
/*setup functions*/
    void LightData::setrecieve(unsigned char recievePin)
    {
        LightData::recievePin=recievePin;
        LightData::recieve=true;
    }
    void LightData::settransmit(unsigned char transmitPin)
    {
        LightData::transmitPin=transmitPin;
        LightData::transmit=true;
    }
    void LightData::setPins(unsigned char transmitPin,unsigned char recievePin)
    {
        LightData::transmitPin=transmitPin;
        LightData::transmit=true;
        LightData::recievePin=recievePin;
        LightData::recieve=true;
    }

} // namespace LD
