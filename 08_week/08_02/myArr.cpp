#include "myArr.h"

template<class T>
myArr<T>::myArr()
:capacity(4), size(0)
{
    data = new T[capacity];
}

template<class T>
myArr<T>::myArr(int size)
{
    setSize(size);
    setCapacity(capacity);
    data = new T[capacity];
    for(int i = 0; i < 10; ++i){
        data[i] = 0;
    }
}

template<class T>
myArr<T>::myArr(T* data, int size)
{
    setSize(size);
    setCapacity(capacity);
    data = new T[capacity];
}

template<class T>
myArr<T>::~myArr()
{
    delete [] data;
    cout << "\nDynamically allocated memory deleted." << endl;
}

//setters
template<class T>
void myArr<T>::setData(myArr<T> *arr, int index)
{
    assert(index >= 0);
    arr->data[index];
}

template<class T>
void myArr<T>::setSize(int s_value)
{
    if(s_value <= capacity){
        size = s_value;
    } else{
        throw std::invalid_argument("Invalid size: size cannot be greater than capacity.");
    }
}

template<class T>
void myArr<T>::setCapacity(int c_value)
{
    if(size <= c_value){
        capacity = c_value;
    } else{
        throw std::invalid_argument("Invalid capacity: capacity cannot be smaller than size.");
    }
}

//getters

template<class T>
T myArr<T>::getData(int index)
{
    return data[index];
}

template<class T>
int myArr<T>::getSize()
{
    return size;
}

template<class T>
int myArr<T>::getCapacity()
{
    return capacity;
}

//methods

template<class T>
void myArr<T>::insertIntoPos(T const &obj, int index)
{
    assert(0 <= index && index <= size);
    if(size >= capacity){
        resize();
    }
    for(int i = size; i > index; --i){
        data[i] = data[i - 1];
    }
    ++size;
    data[index] = obj;

}

template<class T>
void myArr<T>::insert(T const &obj)
{
    size++;
    if(size >= capacity){
        resize();
    }
    data[size - 1] = obj;
}

template<class T>
void myArr<T>::remove(int index)
{
    assert(0 <= index && index < size);
    --size;
    for(int i = index; i < size; ++i){
        data[i] = data[i + 1];
    }
}

template<class T>
void myArr<T>::resize()
{
    capacity *= 2;
    T *temp = new T[capacity];
    copy(data, data + size, temp);
    delete [] data;
    data = temp;
}

template<class T>
void myArr<T>::printData()
{
    cout << "[ ";
    for (int i = 0; i < size; ++i){
        cout << data[i] << "; ";
    }
    cout << "]\n";
}

//operator overloading
template<class T>
T& myArr<T>::operator[](int index)
{
    assert(0 <= index && index < size);
    return data[index];
}
