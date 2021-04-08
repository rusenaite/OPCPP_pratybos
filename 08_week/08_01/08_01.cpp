#include <iostream>
#include <vector>
#include <string>
#include <cwchar>
using namespace std;

template<typename T>
void swap(T *a, T *b);
template <class T>
void selectionSort(vector<T> &vect);
template <class T>
void printVector(vector<T> &vect);


int main(){

    vector <int> numbers {3, 43, 1, 5, 76, 65, 8};
    selectionSort(numbers);
    cout << "Sorted vector of numbers: \n";
    printVector(numbers);

    //--------------------------------------------------

    vector <string> names {
        "John", "Adele", "Bethany", "Chase",
        "Rod", "Daniel", "Marie", "Dan",
        "Jim", "Lauren", "Gavin", "Ann",
        "Zoe", "Hardin", "Calvin"
    };
    selectionSort(names);
    cout << "\nSorted vector of names: \n";
    printVector(names);

    //--------------------------------------------------
    //using ASCII values

    vector <char> characters {91, 96, 95, 94, 92, 93};
    selectionSort(characters);
    cout << "\nSorted vector of characters: \n";
    printVector(characters);
    //sorted array should look like: [, \, ], ^, _, `

    //--------------------------------------------------
    /* function does not work with vector of vectors
    vector <vector<int>> vectors {  {4, 5, 2, 1, 9},
                                    {4, 3},
                                    {9, 9, 7, 5} };
    selectionSort(vectors);
    cout << "\nSorted vector of vectors: \n";
    printVector(vectors);
    */
    //--------------------------------------------------
    /*function does not work with vector of booleans
    vector<bool> booleans = {true, false, false, true, false, true, false};
    selectionSort(booleans);
    cout << "\nSorted vector of booleans: \n";
    printVector(booleans);
    */
    //--------------------------------------------------

    vector<wchar_t> widechars = {L'a', L'G', L'd', L'A'};
    selectionSort(widechars);
    cout << "\nSorted vector of wide characters: \n";
    printVector(widechars);

    return 0;
}

template<typename T>
bool comparison(const T& x, const T& y)
{
    return x < y;
}

template <class T>
void swap(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <class T>
void selectionSort(vector<T> &vect){
    for (size_t i = 0; i < vect.size() - 1; ++i) {
        size_t min = i;
        for(size_t j = i + 1; j < vect.size(); ++j){
            if(comparison(vect[j], vect[min])){
                min = j;
            }
        }
        swap(&vect[min], &vect[i]);
    }
}

template <class T>
void printVector(vector<T> &vect){
    for(size_t i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << endl;
}
