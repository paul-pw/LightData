#pragma once
namespace LD{

    /* Stream class for the Hardware Protocoll implementation*/
    class LDStream
    {
    public:

    /*setup functions*/

        //these are the constructor functions of the class, they give the Variables their default values
        LDStream(long Speed):
            recievePin(0),
            recieve(false),
            transmitPin(0),
            transmit(false),
            Speed(Speed),
            buffer(0){};
        
        LDStream(unsigned char recievePin,unsigned char transmitPin, long Speed):
            recievePin(recievePin),
            recieve(true),
            transmitPin(transmitPin),
            transmit(true),
            Speed(Speed),
            buffer(0){};

        LDStream(unsigned char recievePin,unsigned char transmitPin):
            recievePin(recievePin),
            recieve(true),
            transmitPin(transmitPin),
            transmit(true),
            Speed(0),
            buffer(0){};

        //these functions (re)set the recieve and/or transmit pinn(s) and set the arduino also to recieve or transmit Data. these functions should be called bevore beginn() so the ISR works correctly
        void setrecieve(unsigned char recievePin);
        void settransmit(unsigned char transmitPin);
        void setPins(unsigned char transmitPin,unsigned char recievePin);
        //the beginn() functions initialize the ISR. because of this every function that changes the recieve pin has to be called bevore this function 
        void beginn();
        void beginn(long Speed);

    /*sending Functions*/
    //sends one Byte of Data
    void send(char Data);



    /*recieving functions*/
    //returns the last recieved byte of Data
    char read();


    protected:
        //needed because so the ISR works (ISR funtions have to be static thus static *)
        static LDStream *instance;

        unsigned char recievePin;
        bool recieve;
        unsigned char transmitPin;
        bool transmit;
        //transmition speed in Hz
        long Speed;

        /*variables needed for reciving*/
        volatile char buffer;
        volatile char data;
        volatile unsigned long oldTime;

        //ISR functions in classes have to be static
        static void ISRfunc(){
            instance->dataStream();
        }

        //this function converts the incomming data (the ISR calls) into bits and puts them into bytes
        void dataStream();

        /*whenever one byte is recieved by dataStream(), this function gets called by dataStream()
        and is defined in the derived LightData class, that handles the more high level conversion of Data thats why this function has to have the keyword "virtual" */
        virtual void processData(volatile char data){};
    };


}
