#ifndef MULTISET_HPP
#define MULTISET_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
//------------------------------------------------------------------------

void addAndCount(int num);
std::string convertToString();
void eraseElement(int num);

//------------------------------------------------------------------------

//structure changed into a class

class Multiset
{
    //private:
        std::vector<int> elements; //unique elements
        std::vector<int> counts; //how many times unique elements repeats

    public:
        void addAndCount(int num);
        std::string convertToString();
        void eraseElement(int num);
};

//------------------------------------------------------------------------

#endif // MULTISET_HPP
