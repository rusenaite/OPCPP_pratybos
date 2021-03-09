#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Motorcycle.cpp"
#include "Motorcycle.hpp"

//---------------------------------------------------------------------

int main(){
    std::vector<Motorcycle*> v;
    bool wind = true;

    try{
        //time when finished the race
        Time time1(1, 4, 10);
        Time time2(0, 59, 2);
        Time time3(0, 58, 55);
        Time time4(1, 9, 58);

        Motorcycle *bike1 = new Motorcycle;
        v.push_back(bike1);
         Motorcycle *bike2 = new Motorcycle;
        v.push_back(bike2);
        Motorcycle *bike3 = new Motorcycle;
        v.push_back(bike3);
        Motorcycle *bike4 = new Motorcycle;
        v.push_back(bike4);

        bike1->setBikeName("Motorcycle1");
        bike2->setBikeName("Motorcycle2");
        bike3->setBikeName("Motorcycle3");
        bike4->setBikeName("Motorcycle4");

        std::cout << "1. " << bike1->printName(bike1->getBikeName(), time1, !wind) << std::endl;
        std::cout << "2. " << bike2->printName(bike2->getBikeName(), time2, !wind) << std::endl;
        time3.addSec();
        time3.addSec();
        std::cout << "3. " << bike3->printName(bike3->getBikeName(), time3, wind) << std::endl;
        time4.addSec();
        std::cout << "4. " << bike4->printName(bike4->getBikeName(), time4, wind) << "\n\n";
        std::cout << "Count: " << Motorcycle::getBikeCount() << std::endl;

        double distance = 120;
        bike1->setDistance(distance);
        bike2->setDistance(distance);
        bike3->setDistance(distance);
        bike4->setDistance(distance);
        std::cout << "\nAverage speeds, when distance is " << distance << " km:" << std::endl;
        std::cout << bike1->printSpeed(bike1->getBikeName(), time1) << std::endl;
        std::cout << bike2->printSpeed(bike2->getBikeName(), time2) << std::endl;
        std::cout << bike3->printSpeed(bike3->getBikeName(), time3) << std::endl;
        std::cout << bike4->printSpeed(bike4->getBikeName(), time4) << "\n\n";

        delete bike1;
        delete bike2;
        std::cout << "Count: " << Motorcycle::getBikeCount() << std::endl;
        delete bike3;
        delete bike4;
        std::cout << "Motorcycle count after deleting: " << Motorcycle::getBikeCount() << std::endl;

    }
    catch(std::invalid_argument &arg){
        std::cerr << "Error occurred: " << arg.what() << std::endl;
    }
    catch(std::range_error &range){
        std::cerr << "Error occurred: " << range.what() << std::endl;
    }
    catch(std::runtime_error &runtime){
        std::cerr << "Error occurred: " << runtime.what() << std::endl;
    }
    catch(...){
        std::cerr << "Unrecognised error." << std::endl;
    }

    return 0;
}
