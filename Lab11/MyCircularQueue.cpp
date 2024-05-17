#include "MyCircularQueue.h"

MyCircularQueue::MyCircularQueue(int n){
    maxsize = n;
    list = new int[maxsize];
    front = 0;
    rear = 0;
    count = 0;
}
MyCircularQueue::~MyCircularQueue(){
    delete[] list;
}

void MyCircularQueue::initialize(){
    front = 0; rear = 0; count = 0;
}

bool MyCircularQueue::isEmpty() const{
    return size()==0;
}

bool MyCircularQueue::isFull() const{
    return size()==maxsize-1;
}

void MyCircularQueue::enqueue(const int& n){
    if(isFull()){
        cout << "=> Queue is full !" << endl;
        return;
    }
    rear++;
    if(rear>maxsize-1) rear = 0;
    list[rear]=n;
    count++;
}

void MyCircularQueue::dequeue(){
    if(isEmpty()){
        cout << "=> Queue is empty !" << endl;
        return;
    }
    front++;;
    if(front>maxsize-1) front = 0;
    count--;
}

int MyCircularQueue::Front(){
    return list[front+1];
}

int MyCircularQueue::Rear(){
    return list[rear];
}

int MyCircularQueue::size() const{
    return count;
}

void MyCircularQueue::print(){
    int f = front;
    int r = rear;
    while(f!=r){
        f++;
        if(f>maxsize-1) f=0;
        cout << list[f];
        if(f!=r) cout << " => ";
    } 
    cout << endl;
}

void MyCircularQueue::printDetail() {
    cout << "Size : " << size() << endl;
    cout << "Queue :";
    int f = front;
    int r = rear;
    while(f!=r){
        f++;
        if(f>maxsize-1) f=0;
        cout << '[' << list[f] << ']';
    } 
    cout << endl;
    cout << "index : ";
    f = front;
    r = rear;
    while(f!=r){
        f++;
        if(f>maxsize-1) f=0;
        cout << f;
        if(f!=r) cout << " ";
    }
    cout << endl;
    cout << "front : " << front << ", rear : " << rear << endl;
}