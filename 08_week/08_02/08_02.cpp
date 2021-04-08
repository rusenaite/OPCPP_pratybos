#include "myArr.h"
#include "myArr.cpp"

#include <iostream>
using namespace std;

int main(){
    try{
        //array of ints
        myArr<int> data;
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
        cout << "<<Current capacity: \t" << data.getCapacity() << endl;
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
        cout << data[6] << endl;

        cout << "\n-----------------------------------------------\n\n";

        //array of strings
        myArr<string> str;
        cout << "> Empty array: \t\t";
        str.printData();
        cout << "<<Current capacity: \t" << str.getCapacity() << endl;
        cout << "> Insert(word): \t";
        str.insert("programming");
        str.insert("build");
        str.insert("array");
        str.insert("memory");
        str.insert("data");
        str.insert("strings");
        str.insert("values");
        str.printData();
        cout << "<<Current capacity: \t" << str.getCapacity() << endl;
        cout << "> Insert(word, pos): \t";
        str.insertIntoPos("new", 0);
        str.insertIntoPos("inserted", 2);
        str.insertIntoPos("word", 4);
        str.printData();
        cout << "<<Current capacity: \t" << str.getCapacity() << endl;
        cout << "> Delete(pos): \t(0)\t";
        str.remove(0);
        str.printData();
        str.remove(3);
        cout << "\t\t(3)\t";
        str.printData();
        str.remove(5);
        cout << "\t\t(5)\t";
        str.printData();
        cout << "\n<<Current capacity: \t" << str.getCapacity() << endl;
        cout << "> array[num]: \t[6]\t";
        cout << str[6] << endl;
    }
    catch(invalid_argument &error){
        cerr << "Error value: " << error.what() << endl;
    } catch(...){
        cout << "Default exception" << endl;
    }

    return 0;
}
