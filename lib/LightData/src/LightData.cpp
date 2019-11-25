#include "LightData.h"


namespace LD
{
/*setup functions*/
    void LightData::setrecievePin(unsigned char recievePin)
    {
        LightData::recievePin=recievePin;
    }
    void LightData::settransmitPin(unsigned char transmitPin)
    {
        LightData::transmitPin=transmitPin;
    }
    void LightData::setPins(unsigned char transmitPin,unsigned char recievePin)
    {
        LightData::transmitPin=transmitPin;
        LightData::recievePin=recievePin;
    }

    void LightData::setSpeed(long checkSpeed)
    {
        LightData::checkSpeed = checkSpeed;
    }
    void LightData::setSpeed(long checkSpeed, long transmitSpeed)
    {
        LightData::checkSpeed = checkSpeed;
        LightData::transmitSpeed= transmitSpeed;
        LightData::Method = LightData::Flags::SuperSpeed; 
    }

    void LightData::setMethod(Flags Method)
    {
        LightData::Method = Method;
    }

/*sending Functions*/



/*recieving functions*/



} // namespace LD
