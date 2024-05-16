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
        MyCircularQueue(int n=10){
            maxsize = n;
            list = new int[maxsize];
            front = 0;
            rear = 0;
            count = 0;
        }
        ~MyCircularQueue(){
            delete[] list;
        }
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
    while(f!=r+1){
        cout << '[' << list[f+1] << ']';
        f++;
        if(f>maxsize-1) f=0;
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



int main(){
    MyCircularQueue myQue;
    
    cout << "=====Dequeue x 1 =====" << endl;
    myQue.dequeue();
    myQue.printDetail();

    cout << "=====Enqueue x 7 (10 ~ 70) =====" << endl;
    for(int i=0; i<7; i++){
        myQue.enqueue((i+1)*10);
    }
    myQue.printDetail();

    cout << "=====Dequeue x 3 =====" << endl;
    for(int i=0; i<3; i++) myQue.dequeue();
    myQue.printDetail();

    cout << "=====Enqueue x 6 (10 ~ 60) =====" << endl;
    for(int i=0; i<7; i++){
        myQue.enqueue((i+1)*10);
        if(myQue.isFull()) break;
    }
    myQue.printDetail();

    return 0;
}