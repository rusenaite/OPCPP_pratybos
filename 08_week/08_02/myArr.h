#ifndef MYARR_H
#define MYARR_H

#include <iostream>
#include <cassert>
using namespace std;

const int MIN_CAPACITY = 10;

template <class T>
class myArr
{
    public:
        myArr();
        myArr(int);
        myArr(T* data, int);
        virtual ~myArr();

        //setters
        void setData(myArr *arr, int);
        void setSize(int);
        void setCapacity(int);

        //getters
        T getData(int);
        int getSize();
        int getCapacity();

        //methods
        void insertIntoPos(T const &, int);
        void insert(T const &);
        void remove(int);
        void resize();
        void printData();

        T& operator[](int);

    protected:

    private:
        T *data;
        int size;
        int capacity = MIN_CAPACITY;
};

#endif // MYARR_H
