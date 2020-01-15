#include "LightData.h"

namespace LD
{
/*recieving functions*/

    //function definitions still missing

    data LightData::getData()
    {
        LD::data tmp;
        tmp.Data = L2_data.Data;
        tmp.length = L2_data.length;
        tmp.type = L2_data.type;
        return tmp;
    }

    void LightData::processData(volatile char Data)
    {
        if(L2_buffer.type==types::empty)
        {
            L2_buffer.type = (types)Data;
        }
        /*check if its anny array*/
        else if((L2_buffer.type==types::arr_char)||(L2_buffer.type==types::arr_double)||(L2_buffer.type==types::arr_float)||(L2_buffer.type==types::arr_int)||(L2_buffer.type==types::arr_ldouble)||(L2_buffer.type==types::arr_llint)||(L2_buffer.type==types::arr_sint)||(L2_buffer.type==types::arr_uchar)||(L2_buffer.type==types::arr_uint)||(L2_buffer.type==types::arr_ullint)||(L2_buffer.type==types::arr_usint))
        {
            if (recieve_arraysintIndex<2)
            {
                L2_buffer.length |= Data;
                L2_buffer.length <<= 8;
                recieve_arraysintIndex++;
            }
            if (recieve_arraysintIndex>=2)
            {
                /* calculate lenth of the byte array*/ 
            }
        }else if(!(recieve_charIndex>0))
        {
            /*calculate lenth of the byte array*/
        }else
        {
            /*put one byte in the L2_buffer.Data*/
            recieve_charIndex--;
        }

        if (recieve_charIndex<=0)
        {
            recieve_arraysintIndex=0;

            L2_data.Data = L2_buffer.Data;
            L2_buffer.Data = nullptr;

            L2_data.length = L2_buffer.length;
            L2_buffer.length = 0;

            L2_data.type = L2_buffer.type;
            L2_buffer.type = types::empty;
        }
        /*read the bytes */
    }

} // namespace LD