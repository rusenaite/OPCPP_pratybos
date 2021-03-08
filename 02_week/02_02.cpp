#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "multiset.hpp"
#include "multiset.cpp"

//------------------------------------------------------------------------

int main(){
    int num;
    Multiset set; //no values to initialize
    std::vector<int> data{1, 3, 3, 5, 3, 3, 1};

    for(int i = 0; i < data.size(); ++i){
        set.addAndCount(data[i]); //or Set.data[i]?
    }

    std::cout << "-> Number to add to the multiset: ";
    std::cin >> num;
    set.addAndCount(num);

    std::cout << "-> Number to remove from the multiset: ";
    std::cin >> num;
    std::cout << "\nGiven values:\t\t";
    for (int i = 0; i < data.size(); ++i){
        std::cout << data[i] << " ";
    }
    set.eraseElement(num);

    std::cout << "\nAfter adding and removing entered numbers: \n";
    std::cout << set.convertToString();
}
