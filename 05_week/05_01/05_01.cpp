#include <iostream>
#include <string>
#include <stdexcept>
#include "Time.hpp"
#include "Time.cpp"

int main(){
    try{

        std::cout << "Checking overloaded operators:\n\n";

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
        /* operator + */
        Time time1(17, 45, 50);

        time1 = time1 + 1;
        std::cout << "Time 1 (operator + with int from right):" << std::endl;
        std::cout << time1.showTimeUS() << std::endl;

        time1 = 1 + time1;
        std::cout << "\nTime 1 (operator + with int from left):" << std::endl;
        std::cout << time1.showTimeUS() << std::endl;


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
        /* operator += */
        Time time2(4, 2, 00);
        time2 += time1;

        std::cout << "\nTime 2 (operator += ):" << std::endl;
        std::cout << time2.showTimeUS() << std::endl;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
        /* operator ++ */
        time2++;
        Time time3(23, 45, 33);
        ++time3;

        std::cout << "\nTime 2 (operator ++ postfix) :" << std::endl;
        std::cout << time2.showTimeUS() << std::endl;
        std::cout << "\nTime 3 (operator ++ prefix) :" << std::endl;
        std::cout << time3.showTimeUS() << std::endl;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
        /* operators <, >, ==, !=, <=, >= */
        int n1 = 55;
        std::cout << "\n\nIs " << time3.getSeconds() << " < "
                  << n1 << " ? " << (time3.getSeconds() < n1) << std::endl;
        std::cout << "Is " << time3.getSeconds() << " > "
                  << n1 << " ? " << (time3.getSeconds() > n1) << std::endl;
        std::cout << "Is " << time3.getSeconds() << " == "
                  << n1 << " ? " << (time3.getSeconds() == n1) << std::endl;
        std::cout << "Is " << time3.getSeconds() << " != "
                  << n1 << " ? " << (time3.getSeconds() != n1) << std::endl;
        std::cout << "Is " << time3.getSeconds() << " <= "
                  << n1 << " ? " << (time3.getSeconds() <= n1) << std::endl;
        std::cout << "Is " << time3.getSeconds() << " >= "
                  << n1 << " ? " << (time3.getSeconds() >= n1) << std::endl;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
        /* operator << (member method) */
        Time time4(11, 45, 11);
        std::cout << "\nTime 4 (operator << (member method)) :" << std::endl;
        time4 << std::cout;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
        /* operator << and >> (friend functions) */
        Time time5;
        std::cin >> time5;
        std::cout << "\nTime 5 (operator << (friend functions)) :" << std::endl;
        std::cout << time5 << std::endl;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    }
    catch(std::invalid_argument &error){
        std::cerr << "Error value: " << error.what() << std::endl;
        std::cout << "Re-enter hours, minutes and seconds." << std::endl;
    }
    catch(...){
        std::cout << "Default exception" << std::endl;
    }

    return 0;
}
