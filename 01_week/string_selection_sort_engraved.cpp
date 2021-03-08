#include <iostream>
#include <string.h>
#define MAX_NAME_NUMBER 15
#define MAX_LEN 30

using namespace std;

void selectionSort(char arr[][MAX_LEN], int n){
    int i, j, minimum;
    char minStr[MAX_NAME_NUMBER];
    for (i = 0; i < n - 1; ++i) {
        minimum = i;
        strcpy(minStr, arr[i]);
        for(j = i + 1; j < n; ++j){
            if(strcmp(minStr, arr[j]) > 0){
                strcpy(minStr, arr[j]);
                minimum = j;
          }
        }
        if(minimum != i){
            char temp[MAX_NAME_NUMBER];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[minimum]);
            strcpy(arr[minimum], temp);
        }
    }
}

void printArray(char arr[][MAX_LEN], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    cout << endl;
}

int main(){
    char names[MAX_NAME_NUMBER][MAX_LEN] = {"John", "Adele", "Bethany", "Chase",
                                    "Rod", "Daniel", "Marie", "Dan",
                                    "Jim", "Lauren", "Gavin", "Ann",
                                    "Zoe", "Hardin", "Calvin"};
    int n = sizeof(names)/sizeof(names[0]);
    cout << "Unsorted array of names: \n\n";
    printArray(names, n);

    selectionSort(names, n);
    cout << "\nSorted array of names: \n\n";
    printArray(names, n);


    return 0;
}
