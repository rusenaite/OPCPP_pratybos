#include "myArray.h"


myArray::myArray()
:capacity(4), size(0)
{
    data = new int[capacity];
}

myArray::myArray(int size)
{
    setSize(size);
    setCapacity(capacity);
    data = new int[capacity];
    for(int i = 0; i < 10; ++i){
        data[i] = 0;
    }
}

myArray::myArray(int* data, int size)
{
    setSize(size);
    setCapacity(capacity);
    data = new int[capacity];
}

myArray::~myArray()
{
    delete [] data;
    cout << "\n\nPointer-based array space deleted." << endl;
}

//setters

void myArray::setData(myArray *arr, int index)
{
    assert(index >= 0);
    arr->data[index];
}

void myArray::setSize(int s_value)
{
    if(s_value <= capacity){
        size = s_value;
    } else{
        throw std::invalid_argument("Invalid size: size cannot be greater than capacity.");
    }
}

void myArray::setCapacity(int c_value)
{
    if(size <= c_value){
        capacity = c_value;
    } else{
        throw std::invalid_argument("Invalid capacity: capacity cannot be smaller than size.");
    }
}

//getters

int myArray::getData(int index)
{
    return data[index];
}

int myArray::getSize()
{
    return size;
}

int myArray::getCapacity()
{
    return capacity;
}

//methods

void myArray::insertIntoPos(int value, int index)
{
    assert(0 <= index && index <= size);
    if(size >= capacity){
        resize();
    }
    for(int i = size; i > index; --i){
        data[i] = data[i - 1];
    }
    ++size;
    data[index] = value;

}

void myArray::insert(int value)
{
    size++;
    if(size >= capacity){
        resize();
    }
    data[size - 1] = value;
}

void myArray::remove(int index)
{
    assert(0 <= index && index < size);
    --size;
    for(int i = index; i < size; ++i){
        data[i] = data[i + 1];
    }
}

void myArray::resize()
{
    capacity *= 2;
    int *temp = new int[capacity];
    copy(data, data + size, temp);
    delete [] data;
    data = temp;
}

void myArray::printData()
{
    cout << "[ ";
    for (int i = 0; i < size; ++i){
        cout << data[i] << " ";
    }
    cout << "]\n";
}

//operator overloading

int& myArray::operator[](int index)
{
    assert(0 <= index && index < size);
    return data[index];
}

