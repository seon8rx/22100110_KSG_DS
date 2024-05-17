#include <iostream>
using namespace std;

class MyCircularQueue{
    private:
        int maxsize;
        int front;
        int rear;
        int* list;

        int count;
    public:
        MyCircularQueue(int n=10);
        ~MyCircularQueue();
        void initialize();
        bool isEmpty() const;
        bool isFull() const;
        void enqueue(const int& n);
        void dequeue();
        int Front();
        int Rear();
        int size() const;
        void print();
        void printDetail() ;
};