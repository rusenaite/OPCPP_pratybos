//Time class implementation for motorcycle class

#include <iostream>
#include <string>
#include <vector>
#include "Motorcycle.cpp"
#include "Motorcycle.hpp"

//---------------------------------------------------------------------

int main(){
    std::vector<Motorcycle*> v;
    bool wind = true;

    //time when reached maximum speed
    Time time1(0, 0, 10);
    Time time2(0, 0, 9);
    Time time3(0, 0, 11);
    Time time4(0, 0, 13);

    Motorcycle *bike1 = new Motorcycle;
    v.push_back(bike1);
     Motorcycle *bike2 = new Motorcycle;
    v.push_back(bike2);
    Motorcycle *bike3 = new Motorcycle;
    v.push_back(bike3);
    Motorcycle *bike4 = new Motorcycle;
    v.push_back(bike4);

    bike1->setBikeName("Suzuki");
    bike2->setBikeName("Ducati");
    bike3->setBikeName("Kawasaki");
    bike4->setBikeName("Yamaha");

    time3.addSec();
    time3.addSec();
    time4.addSec();

    std::cout << "1. " << bike1->printName(bike1->getBikeName(), time1, !wind) << std::endl;
    std::cout << "2. " << bike2->printName(bike2->getBikeName(), time2, !wind) << std::endl;
    std::cout << "3. " << bike3->printName(bike3->getBikeName(), time3, wind) << std::endl;
    std::cout << "4. " << bike4->printName(bike4->getBikeName(), time4, wind) << "\n\n";
    std::cout << "Count: " << Motorcycle::getBikeCount() << std::endl;

    delete bike1;
    delete bike2;
    std::cout << "Count: " << Motorcycle::getBikeCount() << std::endl;
    delete bike3;
    delete bike4;
    std::cout << "Motorcycle count after deleting: " << Motorcycle::getBikeCount() << std::endl;


    return 0;
}
