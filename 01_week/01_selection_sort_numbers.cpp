#include <iostream>
#define MAX_SIZE 100
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
    int i, j, minimum;
    for (i = 0; i < n - 1; ++i) {
        minimum = i;
        for(j = i + 1; j < n; ++j){
            if(arr[j] < arr[minimum]){
            minimum = j;
          }
        }
        swap(&arr[minimum], &arr[i]);
    }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    /* array is engraved into the code */
    int arr1[10] = {1, 9, 8, 10, 5, 12, 7, 4, 9, 1};
    int x = sizeof(arr1)/sizeof(arr1[0]);
    int sizeOfArr1 = sizeof(arr1)/sizeof(arr1[0]);

    selectionSort(arr1, sizeOfArr1);
    cout << "Sorted array: \n";
    printArray(arr1, sizeOfArr1);

    /* custom array */
    int arr2[MAX_SIZE], count = 0;
    cout << "\nEnter elements of the array (enter '0' to finish):" << endl;
    for(int i = 0; i < MAX_SIZE; i++){
        cin >> arr2[i];
        if(arr2[i] == 0){
            break;
        }
        count++;
    }

    selectionSort(arr2, count);
    cout << "\nSorted entered array: \n";
    printArray(arr2, count);

    return 0;
}
