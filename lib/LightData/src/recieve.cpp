#include "LightData.h"

namespace LD
{
/*recieving functions*/


    void LightData::processData(volatile char Data)
    {
        if (L2_buffer == nullptr)
        { /*all of this basicaly just evaluates the length needed for the byte array*/
            if(L2_buffer_type == types::empty)
            {
                L2_buffer_type = (types)Data;
            }
            else if((L2_buffer_type==types::arr_char)|| (L2_buffer_type==types::arr_double)
            ||(L2_buffer_type==types::arr_float)||      (L2_buffer_type==types::arr_int)
            ||(L2_buffer_type==types::arr_ldouble)||    (L2_buffer_type==types::arr_llint)
            ||(L2_buffer_type==types::arr_sint)||       (L2_buffer_type==types::arr_uchar)
            ||(L2_buffer_type==types::arr_uint)||       (L2_buffer_type==types::arr_ullint)
            ||(L2_buffer_type==types::arr_usint)) //is anny array
            {
                if (L2_buffer_arraylength_byteindex==0)
                {
                    L2_buffer_arraylength = (unsigned short int)Data << 8;
                    L2_buffer_arraylength_byteindex++;
                }
                else if (L2_buffer_arraylength_byteindex==1)
                {
                    L2_buffer_arraylength |= Data;
                    L2_buffer_arraylength_byteindex++;
                }else
                {
                    if ((L2_buffer_type == types::arr_char) || (L2_buffer_type == types::arr_uchar))
                    {
                        L2_buffer = new char[3+sizeof(char)*L2_buffer_arraylength];
                        L2_buffer_length = 3+sizeof(char)*L2_buffer_arraylength;
                    }
                    else if ((L2_buffer_type == types::arr_sint) || (L2_buffer_type == types::arr_usint))
                    {
                        L2_buffer = new char[3+sizeof(short int)*L2_buffer_arraylength];
                        L2_buffer_length = 3+sizeof(short int)*L2_buffer_arraylength;
                    }
                    else if ((L2_buffer_type == types::arr_int) || (L2_buffer_type == types::arr_uint))
                    {
                        L2_buffer = new char[3+sizeof(int)*L2_buffer_arraylength];
                        L2_buffer_length = 3+sizeof(int)*L2_buffer_arraylength;
                    }
                    else if ((L2_buffer_type == types::arr_llint) || (L2_buffer_type == types::arr_ullint))
                    {
                        L2_buffer = new char[3+sizeof(long long int)*L2_buffer_arraylength];
                        L2_buffer_length = 3+sizeof(long long int)*L2_buffer_arraylength;
                    }
                    else if ((L2_buffer_type == types::arr_float))
                    {
                        L2_buffer = new char[3+sizeof(float)*L2_buffer_arraylength];
                        L2_buffer_length = 3+sizeof(float)*L2_buffer_arraylength;
                    }
                    else if ((L2_buffer_type == types::arr_double))
                    {
                        L2_buffer = new char[3+sizeof(double)*L2_buffer_arraylength];
                        L2_buffer_length = 3+sizeof(double)*L2_buffer_arraylength;
                    }
                    else if ((L2_buffer_type == types::arr_ldouble))
                    {
                        L2_buffer = new char[3+sizeof(long double)*L2_buffer_arraylength];
                        L2_buffer_length = 3+sizeof(long double)*L2_buffer_arraylength;
                    }

                    L2_buffer_index = 0;
                    L2_buffer[L2_buffer_index] = (char)L2_buffer_type;
                    L2_buffer_index++;
                    L2_buffer[L2_buffer_index] = (char)(L2_buffer_arraylength >> 8);
                    L2_buffer_index++;
                    L2_buffer[L2_buffer_index] = (char)(L2_buffer_arraylength & 0xff);
                    L2_buffer_index++;
                }
                
            }else
            {
                if ((L2_buffer_type == types::_char) || (L2_buffer_type == types::_uchar))
                {
                    L2_buffer = new char[1+sizeof(char)];
                    L2_buffer_length = 1+sizeof(char);
                }
                else if ((L2_buffer_type == types::_sint) || (L2_buffer_type == types::_usint))
                {
                    L2_buffer = new char[1+sizeof(short int)];
                    L2_buffer_length = 1+sizeof(short int);
                }
                else if ((L2_buffer_type == types::_int) || (L2_buffer_type == types::_uint))
                {
                    L2_buffer = new char[1+sizeof(int)];
                    L2_buffer_length = 1+sizeof(int);
                }
                else if ((L2_buffer_type == types::_llint) || (L2_buffer_type == types::_ullint))
                {
                    L2_buffer = new char[1+sizeof(long long int)];
                    L2_buffer_length = 1+sizeof(long long int);
                }
                else if ((L2_buffer_type == types::_float))
                {
                    L2_buffer = new char[1+sizeof(float)];
                    L2_buffer_length = 1+sizeof(float);
                }
                else if ((L2_buffer_type == types::_double))
                {
                    L2_buffer = new char[1+sizeof(double)];
                    L2_buffer_length = 1+sizeof(double);
                }
                else if ((L2_buffer_type == types::_ldouble))
                {
                    L2_buffer = new char[1+sizeof(long double)];
                    L2_buffer_length = 1+sizeof(long double);
                }

                L2_buffer_index = 0;
                L2_buffer[L2_buffer_index] = (char)L2_buffer_type;
                L2_buffer_index++;
            }
        }

        if(L2_buffer_index<L2_buffer_length)
        {
            L2_buffer[L2_buffer_index]=(char)Data;
            L2_buffer_index++;
        }
        else
        {
            delete [] L2_data;
            L2_data = L2_buffer;
            L2_data_length = L2_buffer_length;
            L2_buffer_length = 0;
            L2_buffer = nullptr;

            L2_buffer_index = 0;
            L2_buffer_type = types::empty;
            L2_buffer_arraylength = 0;
            L2_buffer_arraylength_byteindex = 0;
        }
        
    }


    /* these functions convert the char array into useable data*/
    bool LightData::getData(char &Buffer)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::_char)
        {
            return false;
        }
        if(L2_data_length!=(sizeof(char)+1)){
            return false;
        }
        Buffer=0;
        for(unsigned int i = 1; i<L2_data_length;i++)
        {
            Buffer |= (char)L2_data[i] << 8*(i-1);
        }
        return true;
    }

    bool LightData::getData(unsigned char &Buffer)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::_uchar)
        {
            return false;
        }
        if(L2_data_length!=(sizeof(unsigned char)+1)){
            return false;
        }
        Buffer=0;
        for(unsigned int i = 1; i<L2_data_length;i++)
        {
            Buffer |= (char)L2_data[i] << 8*(i-1);
        }
        return true;
    }

    bool LightData::getData(short int &Buffer)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::_sint)
        {
            return false;
        }
        if(L2_data_length!=(sizeof(short int)+1)){
            return false;
        }
        Buffer=0;
        for(unsigned int i = 1; i<L2_data_length;i++)
        {
            Buffer |= (short int)L2_data[i] << 8*(i-1);
        }
        return true;
    }

    bool LightData::getData(unsigned short int &Buffer)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::_usint)
        {
            return false;
        }
        if(L2_data_length!=(sizeof(unsigned short int)+1)){
            return false;
        }
        Buffer=0;
        for(unsigned int i = 1; i<L2_data_length;i++)
        {
            Buffer |= (short int)L2_data[i] << 8*(i-1);
        }
        return true;
    }
    
    bool LightData::getData(int &Buffer)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::_int)
        {
            return false;
        }
        if(L2_data_length!=(sizeof(int)+1)){
            return false;
        }
        Buffer=0;
        for(unsigned int i = 1; i<L2_data_length;i++)
        {
            Buffer |= (int)L2_data[i] << 8*(i-1);
        }
        return true;
    }

    bool LightData::getData(unsigned int &Buffer)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::_uint)
        {
            return false;
        }
        if(L2_data_length!=(sizeof(unsigned int)+1)){
            return false;
        }
        Buffer=0;
        for(unsigned int i = 1; i<L2_data_length;i++)
        {
            Buffer |= (int)L2_data[i] << 8*(i-1);
        }
        return true;
    }


    bool LightData::getData(long long int &Buffer)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::_llint)
        {
            return false;
        }
        if(L2_data_length!=(sizeof(long long int)+1)){
            return false;
        }
        Buffer=0;
        for(unsigned int i = 1; i<L2_data_length;i++)
        {
            Buffer |= (long long int)L2_data[i] << 8*(i-1);
        }
        return true;
    }

    bool LightData::getData(unsigned long long int &Buffer)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::_ullint)
        {
            return false;
        }
        if(L2_data_length!=(sizeof(unsigned long long int)+1)){
            return false;
        }
        Buffer=0;
        for(unsigned int i = 1; i<L2_data_length;i++)
        {
            Buffer |= (long long int)L2_data[i] << 8*(i-1);
        }
        return true;
    }


    /*these functions convert the char array into useable array data*/
    bool LightData::getData(char*&Buffer, unsigned short int &length)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::arr_char)
        {
            return false;
        }
        length = (short int)L2_data[1]<<8;
        length |= (short int)L2_data[2];

        delete Buffer;
        Buffer= new char[length];
        for (unsigned short int j = 0; j < length; j++)
        {
            for(unsigned char i = 0; i<sizeof(Buffer[0]);i++)
            {
                Buffer[j] |= (char)L2_data[i+j*sizeof(Buffer[0])+3] << 8*i;
            }
        }
        return true;
    }

    bool LightData::getData(unsigned char*&Buffer, unsigned short int &length)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::arr_uchar)
        {
            return false;
        }
        length = (short int)L2_data[1]<<8;
        length |= (short int)L2_data[2];

        delete Buffer;
        Buffer= new unsigned char[length];
        for (unsigned short int j = 0; j < length; j++)
        {
            for(unsigned char i = 0; i<sizeof(Buffer[0]);i++)
            {
                Buffer[j] |= (char)L2_data[i+j*sizeof(Buffer[0])+3] << 8*i;
            }
        }
        return true;
    }

    bool LightData::getData(short int*&Buffer, unsigned short int &length)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::arr_sint)
        {
            return false;
        }
        length = (short int)L2_data[1]<<8;
        length |= (short int)L2_data[2];

        delete Buffer;
        Buffer= new short int[length];
        for (unsigned short int j = 0; j < length; j++)
        {
            for(unsigned char i = 0; i<sizeof(Buffer[0]);i++)
            {
                Buffer[j] |= (short int)L2_data[i+j*sizeof(Buffer[0])+3] << 8*i;
            }
        }
        return true;
    }

    bool LightData::getData(unsigned short int*&Buffer, unsigned short int &length)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::arr_usint)
        {
            return false;
        }
        length = (short int)L2_data[1]<<8;
        length |= (short int)L2_data[2];

        delete Buffer;
        Buffer= new unsigned short int[length];
        for (unsigned short int j = 0; j < length; j++)
        {
            for(unsigned char i = 0; i<sizeof(Buffer[0]);i++)
            {
                Buffer[j] |= (short int)L2_data[i+j*sizeof(Buffer[0])+3] << 8*i;
            }
        }
        
        return true;
    }

    bool LightData::getData(int*&Buffer, unsigned short int &length)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::arr_int)
        {
            return false;
        }
        length = (short int)L2_data[1]<<8;
        length |= (short int)L2_data[2];

        delete Buffer;
        Buffer= new int[length];
        for (unsigned short int j = 0; j < length; j++)
        {
            for(unsigned char i = 0; i<sizeof(Buffer[0]);i++)
            {
                Buffer[j] |= (int)L2_data[i+j*sizeof(Buffer[0])+3] << 8*i;
            }
        }
        
        return true;
    }

    bool LightData::getData(unsigned int*&Buffer, unsigned short int &length)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::arr_uint)
        {
            return false;
        }
        length = (short int)L2_data[1]<<8;
        length |= (short int)L2_data[2];

        delete Buffer;
        Buffer= new unsigned int[length];
        for (unsigned short int j = 0; j < length; j++)
        {
            for(unsigned char i = 0; i<sizeof(Buffer[0]);i++)
            {
                Buffer[j] |= (int)L2_data[i+j*sizeof(Buffer[0])+3] << 8*i;
            }
        }
        
        return true;
    }

    bool LightData::getData(long long int*&Buffer, unsigned short int &length)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::arr_llint)
        {
            return false;
        }
        length = (short int)L2_data[1]<<8;
        length |= (short int)L2_data[2];

        delete Buffer;
        Buffer= new long long int[length];
        for (unsigned short int j = 0; j < length; j++)
        {
            for(unsigned char i = 0; i<sizeof(Buffer[0]);i++)
            {
                Buffer[j] |= (long long int)L2_data[i+j*sizeof(Buffer[0])+3] << 8*i;
            }
        }
        
        return true;
    }

    bool LightData::getData(unsigned long long int*&Buffer, unsigned short int &length)
    {
        if (L2_data == nullptr)
        {
            return false;
        }
        if ((types)L2_data[0] != types::arr_ullint)
        {
            return false;
        }
        length = (short int)L2_data[1]<<8;
        length |= (short int)L2_data[2];

        delete Buffer;
        Buffer= new unsigned long long int[length];
        for (unsigned short int j = 0; j < length; j++)
        {
            for(unsigned char i = 0; i<sizeof(Buffer[0]);i++)
            {
                Buffer[j] |= (long long int)L2_data[i+j*sizeof(Buffer[0])+3] << 8*i;
            }
        }
        
        return true;
    }

    //function definitions still missing
    /*** these function deffinitions are not ready since 
     * turning them into bytes is complicated 
     * and we havend found a way to do so ...Yet***/
    bool LightData::getData(float &Buffer){return false;};
    bool LightData::getData(double &Buffer){return false;};
    bool LightData::getData(long double &Buffer){return false;};

    bool LightData::getData(float* &Buffer,unsigned short int &length){return false;};
    bool LightData::getData(double* &Buffer,unsigned short int &length){return false;};
    bool LightData::getData(long double* &Buffer,unsigned short int &length){return false;};



} // namespace LD