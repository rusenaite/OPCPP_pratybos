#ifndef MOTORCYCLE_HPP
#define MOTORCYCLE_HPP

#include "Time.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//---------------------------------------------------------------------

class Motorcycle
{
    public:
        Motorcycle();
        Motorcycle(std::string bikeName, Time time);
        virtual ~Motorcycle();

        //setters
        void setBikeCount(int);
        void setBikeName(std::string);

        //getters
        static int getBikeCount();
        std::string getBikeName();
        std::string getTime();

        //methods
        bool isWindy();
        std::string printName(std::string, Time time, bool);

    protected:

    private:
        static int bikeCount;
        std::string bikeName;
        Time time;
};

#endif // MOTORCYCLE_HPP
