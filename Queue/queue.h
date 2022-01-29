template <typename T>
class Queue {
    static const int SIZE=100;
    T *queue;
    int frnt;
    int rear;
  public :
    Queue () ;
    void push ( int num ) ;
    void out();
    int size();
    void pop();
    T front();
    T back();
} ;