#include <iostream>
#include <string>
#include "Time.hpp"
#include "Time.cpp"

//---------------------------------------------------------------------

int main(){
    Time time1(15, 5, 50);
    std::cout << "Printing Time 1:" << std::endl;
    std::cout << time1.showTimeLT() << std::endl;
    std::cout << time1.showTimeUS() << std::endl;

    Time time2(19, 15, 59);
    time2.addSec();
    std::cout << "\nPrinting Time 2 (add a second):" << std::endl;
    std::cout << time2.showTimeLT() << std::endl;
    std::cout << time2.showTimeUS() << std::endl;

    Time time3(7, 59, 1);
    time3.addMin();
    std::cout << "\nPrinting Time 3 (add a minute):" << std::endl;
    std::cout << time3.showTimeLT() << std::endl;
    std::cout << time3.showTimeUS() << std::endl;

    Time time4(23, 23, 59);
    time4.addHour();
    std::cout << "\nPrinting Time 4 (add an hour):" << std::endl;
    std::cout << time4.showTimeLT() << std::endl;
    std::cout << time4.showTimeUS() << std::endl;

    return 0;
}
