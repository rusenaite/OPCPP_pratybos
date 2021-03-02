#include "multiset.hpp"

//------------------------------------------------------------------------

void Multiset::addAndCount(int num){
    bool isDublicate = false;
    int pos = 0;
    for(int i = 0; i < elements.size(); ++i){
        if(num == elements[i]){
            isDublicate = true;
            pos = i;
            break;
        }
    }
    if(isDublicate == false){
        elements.push_back(num);
        counts.push_back(1);
    } else{
        counts[pos] += 1;
    }
}

std::string Multiset::convertToString(){
    std::ostringstream ss;
    ss << "\nUnique numbers:\t\t";
    for(int i = 0; i < elements.size(); ++i){
        ss << elements[i] << " ";
    }
    ss << "\nCounters:\t\t";
    for(int i = 0; i < elements.size(); ++i){
        ss << counts[i] << " ";
    }
    ss << "\nSize of the multiset is " << elements.size() << "." << std::endl;
    ss << std::endl;
    return ss.str();
}

void Multiset::eraseElement(int num){
    std::cout << "\n\nNumber " << num << " will be removed from the multiset." << std::endl;
    for(int i = 0; i < elements.size(); ++i){
        if(num == elements[i]){
            elements.erase(elements.begin() + i);
            counts.erase(counts.begin() + i);
            break;
        }
    }
}
