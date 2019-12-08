#include "LDStream.h"
#include <Arduino.h>
namespace LD
{

    //functions still undefined -> still need to be defined

    /*recieving functions*/
    char LDStream::read()
    {
        return LDStream::data; //temporary return value
    }

    void LDStream::dataStream(){
        //TODO: implement something for the end byte and the start byte
        unsigned char setnumbits = (micros() - LDStream::oldTime)/(1/LDStream::Speed);
        for(unsigned char i=0; i<setnumbits; i++)
        {

            if (!((LDStream::buffer >> 7) & 0x01)) /*check if the most significant bit of a function is NOT 1 (>1<1110101) 
            since the first bit is the start bit and always 1, this works*/
            {
                if(!digitalRead(LDStream::recievePin)/*if now low then it mustve been high before*/){
                    LDStream::buffer <<= 1; //shift left
                    LDStream::buffer |= 0x01; //set last bit as 1
                }else{
                    LDStream::buffer <<= 1; //shift left
                    LDStream::buffer &= ~0x01; //set last bit as 0
                }
            }else{
                /*still have to set the next bit and then all the 8 bits of the byte are set and the further processing can take place*/

                if(!digitalRead(LDStream::recievePin)/*if now low then it mustve been high before*/){
                    LDStream::buffer <<= 1; //shift left
                    LDStream::buffer |= 0x01; //set last bit as 1
                }else{
                    LDStream::buffer <<= 1; //shift left
                    LDStream::buffer &= ~0x01; //set last bit as 0
                }
                
                //this is the full byte, so it can be put into the data var
                LDStream::data = LDStream::buffer;
                //now the incomming bytes just have to be processed which is handled by the derived classes processData function
                LDStream::processData(LDStream::data);
                //set tha buffer to 0 again
                LDStream::buffer=0x00;

            }
            
        }

    }

    

} // namespace LD