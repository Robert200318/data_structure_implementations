#include "list.h"

template<typename T>
List<T>::List() : list_size{0}, m_head{nullptr}
{
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::clear()
{
    while(list_size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::pop_front()
{
    list_node* tmp = m_head;
    m_head = m_head->next;
    delete tmp;
    --list_size;
}

template<typename T>
int List<T>::getSize() const
{
    return list_size;
}

template<typename T>
void List<T>::push_front(const T& data)
{
    list_node* node = new list_node;
    node->data = data;
    node->next = m_head;
    m_head = node;
    ++list_size;
}

template<typename T>
void List<T>::push_back(const T& data)
{
    list_node* node = new list_node;
    node->next = nullptr;
    node->data = data;
    if(m_head == nullptr)
    {
        m_head = node;
        return;
    }
    else
    {
        list_node* tmp = m_head;
        while(tmp->next != nullptr)
        {
        tmp = tmp -> next;
        }
        tmp-> next= node;
    }
    ++list_size;
} 

template<typename T>
void List<T>::print()
{
    list_node* tmp = m_head;
    while (tmp->next != nullptr )
    {
        std::cout<< tmp -> data;
        std::cout<< " -> ";
        tmp = tmp -> next;
    }
    std::cout<< "nullptr" << std::endl;
}

template <typename T>
void List<T>::removeAt(int position)
{
    if(position < 1 || position - 1 > list_size)
    {
        std::cout << "Wrong position" << std::endl;
        return;
    }
    else if(position == 1)
    {
        pop_front();
        return;
    }
    else{

        list_node* tmp = m_head;
        for(int i = 2; i < position; ++i)
        {
            if(tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
        }

        list_node* toDelete = tmp->next;
        tmp->next = toDelete->next;
        delete toDelete;
        --list_size;
    }
}

template <typename T>
void List<T>::pop_back()
{
    removeAt(list_size);
}

template<typename T>
void List<T>::insert(const T& data, int position)
{   
    if(position < 1)
    {
        std::cout << "Wrong position" << std::endl;
        return;
    }
    
    if(position == 1)
    {
        push_front(data);
        return;
    }
    
    if(position - 1 > list_size)
    {
        std::cout << "Wrong position" << std::endl;
        return;
    }
    
    else
    {
        list_node* node = new list_node;

        list_node* tmp = m_head;
        node->data = data;

        for(int i = 1; i <= position; ++i)
        {
            if(tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
        }
        node->next = tmp->next;
        tmp->next = node;
        ++list_size;
    }
}
