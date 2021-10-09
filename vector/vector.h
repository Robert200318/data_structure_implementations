#include <iostream>

template <typename T>
class vector
{
public:
    vector();
    vector(int colum,T value);
    vector(const vector& other);
    ~vector();
public:
    vector & operator=(const vector & other);
    T operator[] (int index);
public:
    void push_back(T value);
    void push_back(T value,int index);
    void pop_back();
    void push_front(T value);
    T getSize() const { return size; }
    T getCapacity() const { return capacity; }
    void shrink_to_fit();
public:
   class iterator {
    public:
        iterator() { iter = nullptr ; }
        iterator(const iterator& it) {
            iter = it.iter ;
        }
        T& operator++() {
            ++iter ;
            return *iter ;
        }
        T& operator++(int) {
            T *tmp = iter ;
            ++iter ;
            return *tmp ;
        }
        bool operator!=(const iterator& other) {
            return this->iter != other.iter ;
        }
        T * iter ;
    } ;
    iterator begin() {
       iterator it ;
       it.iter = this->arr ;
       return it ;
    }
    iterator end() {
        iterator it ;
        it.iter = this->arr + size ;
        return it ;
    }
    
private:
    T * arr;
    int size;
    int capacity;
};