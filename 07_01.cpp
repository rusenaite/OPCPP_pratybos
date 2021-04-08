#include "myArray.h"
#include "myArray.cpp"

#include <iostream>
using namespace std;

int main(){
    try{
        myArray data;
        cout << "> Empty array: \t\t";
        data.printData();
        cout << "<<Current capacity: \t" << data.getCapacity() << endl;
        cout << "> Insert(num): \t\t";
        data.insert(2);
        data.insert(12);
        data.insert(9);
        data.insert(6);
        data.insert(8);
        data.insert(16);
        data.insert(23);
        data.printData();
        cout << "\n<<Current capacity: \t" << data.getCapacity() << endl;
        cout << "> Insert(num, pos): \t";
        data.insertIntoPos(1, 0);
        data.insertIntoPos(1, 2);
        data.insertIntoPos(1, 4);
        data.printData();
        cout << "<<Current capacity: \t" << data.getCapacity() << endl;
        cout << "> Delete(pos): \t(0)\t";
        data.remove(0);
        data.printData();
        data.remove(3);
        cout << "\t\t(3)\t";
        data.printData();
        data.remove(5);
        cout << "\t\t(5)\t";
        data.printData();
        cout << "\n<<Current capacity: \t" << data.getCapacity() << endl;
        cout << "> array[num]: \t[6]\t";
        cout << data[6];
    }
    catch(invalid_argument &error){
        cerr << "Error value: " << error.what() << endl;
    } catch(...){
        cout << "Default exception" << endl;
    }

    return 0;
}
