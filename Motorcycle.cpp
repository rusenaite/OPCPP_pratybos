#include "Motorcycle.hpp"
#include "Time.cpp"
#include "Time.hpp"

//---------------------------------------------------------------------

Motorcycle::Motorcycle()
{
    ++bikeCount;
}

Motorcycle::Motorcycle(std::string bikeName, Time time, double distance)
{
    ++bikeCount;
    setBikeName(bikeName);
    setBikeCount(bikeCount);
    this->time = time;
    setDistance(distance);
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
    if(!bikeName.empty()){
        this->bikeName = bikeName;
    } else{
        throw std::invalid_argument("Invalid argument. Name does not contain any word.");
    }
}

void Motorcycle::setDistance(double distance){
    if(distance > 0){
        this->distance = distance;
    } else{
        throw std::range_error("Distance value is out of range (has to be bigger than 0).");
    }
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

double Motorcycle::averageSpeed(Time time, double distance)
{
    double avg = 0;
    double hr = time.getHours();
    double mn = time.getMinutes();
    double sec = time.getSeconds();
    if(hr == 0 && mn == 0 && sec == 0){
        throw std::runtime_error("Mathematical error. Attempted to divide by 0.");
    }
    double timeToHr = hr + (mn / 60) + (sec / 60 / 60);
    avg = distance / timeToHr;
    return avg * 1.0;
}

std::string Motorcycle::printSpeed(std::string bikeName, Time time)
{
    std::stringstream ss;
    ss  << bikeName << "\t\t\t\t|| " << std::setw(6) << averageSpeed(time, distance) << " km/h";
    return ss.str();
}


std::string Motorcycle::printName(std::string bikeName, Time time, bool isWindy)
{
    std::stringstream ss;
    if(isWindy == true){
        ss << "Effected by wind: " << bikeName << "\t|| " << time.showTimeLT();
    } else {
        ss  << bikeName << "\t\t\t\t|| " << time.showTimeLT();
    }
    return ss.str();
}

