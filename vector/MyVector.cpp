#include "vector.h"
#include <initializer_list>

template<typename T>
vector<T>::vector()
{
    size = 0;
    capacity = 1;
    arr = new T[1];
}

template<typename T>
vector<T>::vector(int colum,T value)
{
    size = colum;
    capacity = size * 2;
    arr = new T[capacity];
    for(int i = 0; i < size;i++){
        arr[i] = value;
    }
}

template<typename T>
vector<T>::~vector()
{
    delete [] arr;    
}

template<typename T>
void vector<T>::push_back(T value) {
    if(capacity == size) {
        T *tmp = new T[capacity * 2];
        for(int i = 0; i < capacity;i++) {
            tmp[i] = arr[i];
        }
        delete [] arr;
        arr = tmp;
        capacity *= 2;
        tmp = nullptr;
    }
    arr[size] = value;
    size++;
}

template<typename T>
void vector<T>::push_back(T value,int index) {
    if(index == capacity) {
        push_back(value);
    } else {
        arr[index] = value;
    }
}

template<typename T>
void vector<T>::pop_back() {
    T *tmp = new T[capacity - 1];
    for(int i = 0; i < size - 1; i++) {
        tmp[i] = arr[i];
    }
    delete [] arr;
    arr = tmp;
    capacity--;
    size--;
}


template<typename T>
vector<T>::vector(const vector & other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->arr = new T [other.capacity];
    for(int i = 0;i < size; i++){
    
        this->arr[i] = other.arr[i];
    }
}

template<typename T>
vector<T> & vector<T>::operator=(const vector & other){
    if(this == &other) {
        return * this;
    }
    delete [] arr;
    this->size = other.size;
    this->capacity = other.capacity;
    this->arr = new T [other.capacity];
    for(int i = 0;i < size; i++){
    
        this->arr[i] = other.arr[i];
    }
    return *this;   
}

template<typename T>
void vector<T>::push_front( T elem )
{
    if ( size == capacity )
    {
        capacity *= 2;
        T* tmp = new T[capacity];
        for (int i = 0; i < size; ++i)
        {
            tmp[i+1] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }

    else
    {
        for (int i = size; i >= 0; i--)
        {
            arr[i+1] = arr[i];
        }
    } 
    arr[0] = elem;   
    ++size;
}

template<typename T>
T vector<T>::operator[](int index) {
    return arr[index];
}

template<typename T>
void vector<T>::shrink_to_fit() {
    capacity = size;
}
