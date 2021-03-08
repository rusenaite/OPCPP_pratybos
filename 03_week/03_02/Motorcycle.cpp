#include "Motorcycle.hpp"
#include "Time.cpp"
#include "Time.hpp"

//---------------------------------------------------------------------

Motorcycle::Motorcycle()
{
    ++bikeCount;
}

Motorcycle::Motorcycle(std::string bikeName, Time time)
{
    ++bikeCount;
    setBikeName(bikeName);
    setBikeCount(bikeCount);
    this->time = time;
}

Motorcycle::~Motorcycle()
{
    --bikeCount;
    std::cout << "Class deleted." << std::endl;
}

//---------------------------------------------------------------------


//setters
int Motorcycle::bikeCount;
void Motorcycle::setBikeCount(int bikeCount)
{
    this->bikeCount = bikeCount;
}

void Motorcycle::setBikeName(std::string bikeName)
{
    this->bikeName = bikeName;
}

//getters
std::string Motorcycle::getTime()
{
    return time.showTimeLT();
}

std::string Motorcycle::getBikeName()
{
    std::stringstream ss;
    ss << bikeName;
    return ss.str();
}

int Motorcycle::getBikeCount()
{
    return bikeCount;
}

bool Motorcycle::isWindy()
{
    time.addSec();
    return true;
}

std::string Motorcycle::printName(std::string bikeName, Time time, bool isWindy)
{
    std::stringstream ss;
    if(isWindy == true){
        ss << "Effected by wind: " << bikeName << "\t" << time.showTimeLT();
    } else {
        ss  << bikeName << "\t" << time.showTimeLT();
    }
    return ss.str();
}

