#include "stack.h"

template<typename T>
Stack<T>::Stack(T s)
{
    index=0;
    mas_simvol[index]=s;
    simvol=s;
}

template<typename T>
void Stack<T>::push(T s1)
{
    if(index==SIZE)
    {
        std::cout<<"Stack is full "<<simvol<<std::endl;
        return;
    }
    mas_simvol[++index]=s1;
}

template<typename T> 
T Stack<T>::pop()
{
    if(index==0)
    {
        std::cout<<"Stack is empty"<<simvol<<std::endl;
        return 0;
    }
return mas_simvol[index--];
}

template<typename T> 
void Stack<T>::clear()
{
    while(index!=0)
    {
        index--;
    }
}

template<typename T>
T Stack<T>::top()
{
    return mas_simvol[index];
}
 
template<typename T>
bool Stack<T>::empty(){
    if( index == 0 )
    {
        return false;
    }
    else
    {
        return true;
    }
}

template<typename T> 
void Stack<T>::show(){
    int temp=index;
    if(temp==0)
    {
        std::cout<<"Stack is empty"<<simvol<<std::endl;
        return;
    }
    while(temp!=0)
    {
        std::cout<<mas_simvol[temp]<<std::endl;
        temp--;
    }
    std::cout<<mas_simvol[0]<<std::endl;
}
