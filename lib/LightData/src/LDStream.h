#pragma once

namespace LD{

    /* Stream class for the Hardware Protocoll implementation*/
    class LDStream
    {
    public:

    /*setup functions*/

    /*sending Functions*/
        void send(char data);
    /*recieving functions*/
        char read();


    protected:
        char Data;

        virtual void processData(char Data)=0;
    /*virtual because we need the inheriting classes to have a definition for this function
    Diese function wird in der derived class ('LightData') deffiniert und wird immer gecalled wenn ein neues byte an input daten vorhanden ist*/
    };


}
