#include <iostream>
using namespace std;

struct elem {
    int value;
};

class MyStack{
    private:
        int maxsize;
        int top;
        elem *list;

    public:
        void initialize();
        bool isEmpty() const;
        bool isFull() const; //const는 내부적으로 멤버 변수를 변경할 수 없다.
        void push(const elem&);
        elem* pop();
        void print();
        MyStack(int size = 10);
        ~MyStack(){delete[] list;};
};

MyStack::MyStack(int size){
    maxsize = size;
    list = new elem[maxsize];
    initialize();
}

void MyStack::initialize(){
    top = -1;
}

bool MyStack::isEmpty() const{
    // if(top==-1) return true;
    // else return false; 
    return (top==-1) ? true : false;
}

bool MyStack::isFull() const{
    return (top==maxsize-1) ? true : false;
}

void MyStack::push(const elem& e){
    if(isFull()) return;
    top++;
    list[top] = e;
}

elem* MyStack::pop(){
    if(isEmpty()) return nullptr;
    return &list[top--];
}

void MyStack::print(){
    for(int i=0; i < top+1; i++){
        cout << list[i].value << endl;
    }
}

int main(){
    int inputSize;
    cin >> inputSize;
    MyStack myStack(inputSize);

    while(1){
        string input;
        int inputVal;
        cin >> input;
        if(input == "push"){
            cin >> inputVal;
            elem e;
            e.value = inputVal;
            myStack.push(e);
        }
        else if(input == "pop") myStack.pop();
        else if(input == "print"){
            myStack.print();
            break;
        }

    }

    return 0;
}