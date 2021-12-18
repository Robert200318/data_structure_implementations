#ifndef LIST_H
#define LIST_H
#include <iostream>

template<typename T>
class List
{
    public:
        List();
        ~List();
    public:
        int getSize() const;
        void push_back(const T&);
        void push_front(const T&);
        void pop_front();
        void clear();
        void removeAt(int position);
        void pop_back();
        void insert(const T&, int position);
        void print();
    private:
        struct list_node
        {
            T data;
            list_node* next;
        };
        std::size_t list_size;
        list_node* m_head = nullptr;
};
#endif /*LIST_H*/