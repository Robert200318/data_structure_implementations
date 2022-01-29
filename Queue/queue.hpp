#include <iostream>

#include "queue.h"

template <typename T>
Queue<T>::Queue() 
{
    queue = new int[SIZE];
    frnt = rear = 0 ;
}

template <typename T>
void Queue<T>::out() 
{
    for(int i=frnt+1;i<rear+1;i++)
    std::cout<<" "<<queue[i];
}

template <typename T>
void Queue<T>::push ( int num ) 
{
    if ( rear+1 == frnt || ( rear + 1 ==SIZE && !frnt )) 
    {
        cout << "Queue is full" <<endl ;
        return ;
    }
    rear++;
    if ( rear==SIZE ) 
    {
        rear = 0 ;
    }
    queue [ rear ] = num;
}

template <typename T>
void Queue<T>::pop() 
{
    if ( frnt == rear ) 
    {
        cout << "Queue is empty" <<endl ;
        return;
    }
    frnt++;
    if ( frnt==SIZE ) 
    {
        frnt = 0 ;
    }
}

template <typename T>
int Queue<T>::size() 
{
    int s=0;
    for(int i=frnt; i<rear; i++)
    {
        s++;
    }
    return s;
}

template <typename T>
T Queue<T>::back() 
{
    return queue[rear]; 
}

template <typename T>
T Queue<T>::front() 
{
    return queue[frnt+1]; 
}