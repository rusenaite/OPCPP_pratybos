#include <iostream>
#include <vector>
#define MAX_SIZE 100
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(vector<int> &vect){
    int minimum;
    for (size_t i = 0; i < vect.size() - 1; ++i) {
        size_t min = i;
        for(size_t j = i + 1; j < vect.size(); ++j){
            if(vect[j] < vect[min]){
                min = j;
            }
        }
        swap(&vect[min], &vect[i]);
    }
}

void printVector(vector<int> &vect){
    for(size_t i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << endl;
}

int main(){
    /* vector is engraved into the code */
    vector <int> vect1 {
        3,
        43,
        1,
        5,
        76,
        65,
        8
    };

    selectionSort(vect1);
    cout << "Sorted vector will be: \n";
    printVector(vect1);

    /* custom vector */
    vector <int> vect2;
    int num, count = 0;

    cout << "\nNow, enter some integers of your vector (enter 0 to finish): \n";
    do {
        cin >> num;
        if(num == 0){
            break;
        }
        vect2.push_back(num);
        count++;
        if(count == MAX_SIZE - 1){
            cout << "\n* You have reached the limit for the numbers you can enter. * Press 0 to finish the input:";
        }
    } while(num && count < MAX_SIZE);

    cout << "\nYour vector stores " << int(vect2.size()) << " numbers.\n";

    selectionSort(vect2);
    cout << "\nSorted entered vector will be: \n";
    printVector(vect2);

    return 0;
}
