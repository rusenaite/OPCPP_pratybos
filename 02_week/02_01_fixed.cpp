/*
* Usage of iterators:
* An iterator refers to the first element in the multiset container.
* Bidirectional iterators are iterators that can be used to access
* the sequence of elements in a range in both directions
* (towards the end and towards the beginning).
*/

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
            Set.counts.push_back(1); //adds 1 to the new element
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
                Set.counts.push_back(1); //adds more to that 1 because of dublicates
            }
        }
    }
}

/*
  copy(strt_iter1, end_iter1, strt_iter2) :
* Defined in header <algorithm>.
* The generic copy function used to copy a range of elements from one
  container to another.
* It takes 3 arguments:

strt_iter1 : The pointer to the beginning of the source container,
            from where elements have to be started copying.
end_iter1 : The pointer to the end of source container, till where
            elements have to be copied.
strt_iter2 : The pointer to the beginning of destination container,
            to where elements have to be started copying.
*/


//to convert elements and count into a string
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

/*

The stringstream, ostringstream, and istringstream objects are used for
input and output to a string. They behave in a manner similar to fstream,
ofstream and ifstream objects.


An ostringstream object can be used to write to a string.
This is similar to the C sprintf() function.

An istringstream object can be used to read from a string.
This is similar to the C sscanf() function.

A stringstream object can be used for both input and output to a string.
This is similar to the C fstream object.

<< operator inserts data INTO the stream.
>> operator extracts data OUT OF a string stream.

*/

int main(){
    multiset Set; //defining name of struct
    multiset_add(Set); //passing struct as an parameter
    multiset_toString(Set);

    return 0;
}
