#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
#include <cassert>
using namespace std;

const int MIN_CAPACITY = 10;

class myArray
{
    public:
        myArray();
        myArray(int);
        myArray(int*, int);
        virtual ~myArray();

        //setters
        void setData(myArray *arr, int);
        void setSize(int);
        void setCapacity(int);

        //getters
        int getData(int);
        int getSize();
        int getCapacity();

        //methods
        void insertIntoPos(int, int);
        void insert(int);
        void remove(int);
        void resize();
        void printData();

        int& operator[](int);

    protected:

    private:
        int *data;
        int size;
        int capacity = MIN_CAPACITY;
};

#endif // MYARRAY_H
