#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

struct multiset{
    vector<int> elements; //unique elements
    vector<int> counts; //how many times unique elements repeats
};


//function for adding elements - if its new: add, if not: skip
void multiset_add(multiset &Set){
    int input;
    cout << "Insert 10 numbers:" << endl;
    for(int i = 0; i < 10; ++i){
        cin >> input;
        if(Set.elements.size() == 0){
            Set.elements.push_back(input);
            Set.counts.push_back(1);
        } else{
            bool isDublicate = false;
            for(int j = 0; j < Set.elements.size(); ++j){
                if(input == Set.elements[j]){
                    Set.counts[j] += 1;
                    isDublicate = true;
                    break;
                }
            }
            if(isDublicate == false){
                Set.elements.push_back(input);
                Set.counts.push_back(1);
            }
        }
    }
}

void multiset_toString(multiset &Set){
    ostringstream elements;
    ostringstream counts;

    copy(Set.elements.begin(), Set.elements.end()-1, ostream_iterator<int>(elements, " "));
    copy(Set.counts.begin(), Set.counts.end()-1, ostream_iterator<int>(counts, " "));

    elements << Set.elements.back();
    counts << Set.counts.back();

    cout << "\nUnique numbers: " << elements.str() << endl;
    cout << "\nCounters: " << counts.str() << endl;
}

int main(){
    multiset Set;
    multiset_add(Set);
    multiset_toString(Set);

    return 0;
}
