#ifndef MOTORCYCLE_HPP
#define MOTORCYCLE_HPP

#include "Time.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
#include <iomanip>

//---------------------------------------------------------------------

class Motorcycle
{
    public:
        Motorcycle();
        Motorcycle(std::string bikeName, Time time, double distance);
        virtual ~Motorcycle();

        //setters
        void setBikeCount(int);
        void setBikeName(std::string);
        void setDistance(double);

        //getters
        static int getBikeCount();
        std::string getBikeName();
        std::string getTime();
        double getDistance();

        //methods
        bool isWindy();
        double averageSpeed(Time time, double);
        std::string printName(std::string, Time time, bool);
        std::string printSpeed(std::string, Time time);


    protected:

    private:
        static int bikeCount;
        std::string bikeName;
        Time time;
        double distance;
};

#endif // MOTORCYCLE_HPP
