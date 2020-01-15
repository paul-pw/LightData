#include "LDStream.h"
#include <Arduino.h>
namespace LD
{
    /*recieving functions*/
    char LDStream::read(){ return LDStream::data; }

    void LDStream::dataStream(){
        unsigned char setnumbits = (micros() - LDStream::oldTime)/(1/LDStream::Speed); //calculates the number of bits that have been set as high or low (because the ISR only gets called on input change)
        for(unsigned char i=0; i<setnumbits; i++)
        {

            if (!((LDStream::buffer >> 7) & 0x01)) /*check if the most significant bit of a function is NOT 1 (>1<1110101) 
            if its one, the last bit still has to be put in the buffer and then one byte is recieved*/
            {
                if(!digitalRead(LDStream::recievePin)/*if now low then it mustve been high before, so the recieved bits were all 1 bits*/){
                    LDStream::buffer <<= 1; //shift left
                    LDStream::buffer |= 0x01; //set last bit as 1
                }else{
                    LDStream::buffer <<= 1; //shift left
                    LDStream::buffer &= ~0x01; //set last bit as 0
                }
            }else{
                /*sets the last bit and then all the 8 bits of the byte are set and the further processing can take place*/
                if(!digitalRead(LDStream::recievePin)/*if now low then it mustve been high before*/){
                    LDStream::buffer <<= 1; //shift left
                    LDStream::buffer |= 0x01; //set last bit as 1
                }else{
                    LDStream::buffer <<= 1; //shift left
                    LDStream::buffer &= ~0x01; //set last bit as 0
                }
                //now one Byte is recieved, further processing now can take place

                //this is the full byte, so it can be put into the data variable
                LDStream::data = LDStream::buffer;
                //now the incomming bytes are getting processed, this is handled by the derived classes processData function
                LDStream::processData(LDStream::data);
                
                //set tha buffer to 0 again
                LDStream::buffer=0x00;
            }
        }
    }
} // namespace LD