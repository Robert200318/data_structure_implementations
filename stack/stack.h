#include <iostream>

template<typename T>
class Stack{
public:
    Stack(T s);
public: 
    void clear();
    bool empty();
    void show();
    void push(T s1);
    T pop();
    T top();
private:
    T mas_simvol[SIZE];
    T simvol;
    static const int SIZE = 8;
    int index;
};