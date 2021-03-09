#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

//---------------------------------------------------------------------

class Time
{
    public:
        Time();
        Time(int, int, int);
        virtual ~Time();

        //setters
        void setHours(int);
        void setMinutes(int);
        void setSeconds(int);

        //getters
        int getHours();
        int getMinutes();
        int getSeconds();

        //methods
        void addHour();
        void addMin();
        void addSec();
        std::string showTimeUS();
        std::string showTimeLT();

    protected:

    private:
        int hours;
        int minutes;
        int seconds;
};

#endif // TIME_HPP
