#include "Time.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>


Time::Time()
:hours(12), minutes(0), seconds(0) { }

Time::Time(int hours, int minutes, int seconds)
{
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

Time::~Time()
{
    std::cout << "Class deleted" << std::endl;
}

void Time::setHours(int h_value)
{
    if(0 <= h_value && h_value < 24) {
        hours = h_value;
    } else{
        throw std::invalid_argument("Entered invalid 'hours' value.");
    }
}

void Time::setMinutes(int m_value)
{
    if(0 <= m_value && m_value < 60) {
        minutes = m_value;
    } else{
        throw std::invalid_argument("Entered invalid 'minutes' value.");
    }
}

void Time::setSeconds(int s_value)
{
    if(0 <= s_value && s_value < 60) {
        seconds = s_value;
    } else{
        throw std::invalid_argument("Entered invalid 'seconds' value.");
    }
}

int Time::getHours()
{
    return hours;
}

int Time::getMinutes()
{
    return minutes;
}

int Time::getSeconds()
{
    return seconds;
}

/* unary operator as method member */
Time& Time::operator+=(const Time &t1)
{
    /* checking for self assignment */
    if(this != &t1){
        this->hours += t1.hours;
        this->minutes += t1.minutes;
        this->seconds += t1.seconds;
        return *this;
    } else{
        return *this;
    }
}


/* binary class methods to add 'int' from left and right */
Time operator+(const Time &t1, int value)
{
    Time temp;
    temp.hours = t1.hours + value;
    temp.minutes = t1.minutes + value;
    temp.seconds = t1.seconds + value;
    return temp;
}

Time operator+(int value, const Time &t1)
{
    Time temp;
    temp.hours = t1.hours + value;
    temp.minutes = t1.minutes + value;
    temp.seconds = t1.seconds + value;
    return temp;
}

/* comparison operators */
bool Time::operator<(const Time &t1) const
{
    return (t1 > *this);
}

bool Time::operator>(const Time &t1) const
{
    return (t1 < *this);
}

bool Time::operator==(const Time &t1) const
{
    if(hours == t1.hours && minutes == t1.minutes && seconds == t1.seconds){
        return true;
    } else{
        return false;
    }
}

bool Time::operator!=(const Time &t1) const
{
    return !(*this == t1);
}

bool Time::operator<=(const Time &t1) const
{
    return !(t1 < *this);
}

bool Time::operator>=(const Time &t1) const
{
    return !(t1 > *this);
}

/* overloading << as a member method */
std::ostream& Time::operator<<(std::ostream &o)
{
    o << std::setfill('0');
    o << "LT Time: " << std::setw(2) << hours << ":"
      << std::setw(2) << minutes << ":"
      << std::setw(2) << seconds;
    return o;
}

/* overloading operators << and >> as global functions */
std::ostream& operator<<(std::ostream &out, Time &t1)
{
    out << std::setfill('0');
    out << "LT Time: " << std::setw(2) << t1.hours << ":"
        << std::setw(2) << t1.minutes << ":"
        << std::setw(2) << t1.seconds;
    return out;
}


std::istream& operator>>(std::istream &in, Time &t1)
{
    std::cout << "Enter hours, minutes and seconds in same order: ";
    in >> t1.hours;
    in >> t1.minutes;
    in >> t1.seconds;
    return in;
}

/* unary operators ++ */
Time& Time::operator++()
{
    ++this->hours;
    ++this->minutes;
    ++this->seconds;
    return *this;
}

Time Time::operator++(int)
{
    Time temp = *this;
    hours++;
    minutes++;
    seconds++;
    return temp;
}

void Time::addHour()
{
    setHours(++hours);
    if(hours > 23){
        hours = 0;
    }
}

void Time::addMin()
{
    setMinutes(++minutes);
    if(minutes > 59){
        addHour();
        minutes = 0;
    }
}

void Time::addSec()
{
    setSeconds(++seconds);
    if(seconds > 59){
        addMin();
        seconds = 0;
    }
}

std::string Time::showTimeUS()
{
    std::stringstream ss;
    bool am = false;
    if(hours <= 12){
        am = true;
    }
    if(hours > 13){
        hours -= 12;
    }
    ss << std::setfill('0');
    ss << "US Time: " << std::setw(2) << hours << ":"
       << std::setw(2) << minutes << ":"
       << std::setw(2) << seconds;
    if(am == true){
        ss << " AM";
    } else{
        ss << " PM";
    }
    return ss.str();
}

std::string Time::showTimeLT()
{
    std::stringstream ss;
    ss << std::setfill('0');
    ss << "LT Time: " << std::setw(2) << hours << ":"
       << std::setw(2) << minutes << ":"
       << std::setw(2) << seconds;
    return ss.str();
}
