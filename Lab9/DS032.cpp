#include <iostream>
#include <fstream>
using namespace std;

struct elem {
    double gpa;
    string name;
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
        MyStack(int size = 100);
        ~MyStack(){delete[] list;};
        double getTopGPA() const;
        string getTopName() const;
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

double MyStack::getTopGPA() const{
    if (!isEmpty()) {
        return list[top].gpa;   
    }
    return 0.0;
}

string MyStack::getTopName() const{
    if (!isEmpty()) {
        return list[top].name;   
    }
    return NULL;
}



void MyStack::print(){
    cout << "Top GPA: " << getTopGPA() << endl;
    while(!isEmpty()){
        cout << getTopName() << endl;
        pop();
    }
}

void readFile(MyStack& myStack){
    ifstream readFile;
    readFile.open("list.txt");

    while(!readFile.eof()){
        elem e;
        string tmp;

        getline(readFile, tmp);
        if(tmp == "") break;
        e.gpa = stod(tmp.substr(0, tmp.find(' ')));
        e.name = tmp.substr(tmp.find(' ')+1);
        if(myStack.isEmpty()){
            myStack.push(e);
        }else{
            if(myStack.getTopGPA() == e.gpa){
                myStack.push(e);
            }else if(myStack.getTopGPA() < e.gpa){
                myStack.initialize();
                myStack.push(e);
            }
        }
    }
    readFile.close();
}




int main(){

    MyStack myStack;
    readFile(myStack);
    myStack.print();
    return 0;
}