#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>

//---------------------------------------------------------------------

class Time
{
    public:
        //constructors
        Time();
        Time(int, int, int);
        ~Time();

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

    private:
        int hours;
        int minutes;
        int seconds;
};

#endif // TIME_HPP
