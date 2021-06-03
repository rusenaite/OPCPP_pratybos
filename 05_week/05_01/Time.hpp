#ifndef TIME_HPP
#define TIME_HPP

#include <string>

class Time
{
        friend std::ostream& operator<<(std::ostream &, Time &);
        friend std::istream& operator>>(std::istream &, Time &);

        friend Time operator+(const Time &, int);
        friend Time operator+(int, const Time &);

    public:
        Time();
        Time(int, int, int);
        ~Time();

        void setHours(int);
        void setMinutes(int);
        void setSeconds(int);

        int getHours();
        int getMinutes();
        int getSeconds();

        Time& operator+=(const Time &);

        bool operator<(const Time &) const;
        bool operator>(const Time &) const;
        bool operator==(const Time &) const;
        bool operator!=(const Time &) const;
        bool operator<=(const Time &) const;
        bool operator>=(const Time &) const;

        std::ostream& operator<<(std::ostream &);

        Time& operator++();
        Time operator++(int);

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
