#include <iostream>
#include <fstream>
using namespace std;

class MyCircularStringQueue{
    private:
        int maxsize;
        int front;
        int rear;
        string* list;

        int count;
    public:
        MyCircularStringQueue(int n=10){
            maxsize = n;
            list = new string[maxsize];
            front = 0;
            rear = 0;
            count = 0;
        }
        ~MyCircularStringQueue(){
            delete[] list;
        }
        void initialize();
        bool isEmpty() const;
        bool isFull() const;
        void enqueue(const string& n);
        void dequeue();
        string Front();
        string Rear();
        int size() const;
        void print();
        void printDetail() ;
};

void MyCircularStringQueue::initialize(){
    front = 0; rear = 0; count = 0;
}

bool MyCircularStringQueue::isEmpty() const{
    return size()==0;
}

bool MyCircularStringQueue::isFull() const{
    return size()==maxsize-1;
}

void MyCircularStringQueue::enqueue(const string& n){
    if(isFull()){
        cout << "=> Queue is full !" << endl;
        return;
    }
    rear++;
    if(rear>maxsize-1) rear = 0;
    list[rear]=n;
    count++;
}

void MyCircularStringQueue::dequeue(){
    if(isEmpty()){
        cout << "=> Queue is empty !" << endl;
        return;
    }
    front++;;
    if(front>maxsize-1) front = 0;
    count--;
}

string MyCircularStringQueue::Front(){
    return list[front+1];
}

string MyCircularStringQueue::Rear(){
    return list[rear];
}

int MyCircularStringQueue::size() const{
    return count;
}

void MyCircularStringQueue::print(){
    cout << "Highest GPA = " << stod(Front().substr(Front().find(' ')+1)) << endl;
    while(!isEmpty()){
        cout << Front() << endl;
        dequeue();
    }
}

void MyCircularStringQueue::printDetail() {
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

int getNumFile(){
    int c=0;
    ifstream readFile;
    // readFile.open("list.txt");
    readFile.open("data.txt");
    while(!readFile.eof()){
        string tmp;

        getline(readFile, tmp);
        if(tmp == "") break;
        else c++;
    }
    readFile.close();
    return c;

}

void getHighestScoreFromFile(MyCircularStringQueue& myQue){
    ifstream readFile;
    // readFile.open("list.txt")
    readFile.open("data.txt");;

    while(!readFile.eof()){
        string tmp;

        getline(readFile, tmp);
        if(tmp == "") break;
        double gpa = stod(tmp.substr(0, tmp.find(' ')));
        string name = tmp.substr(tmp.find(' ')+1);
        string enq;
        enq.append(name);
        enq.append(" ");
        enq.append(tmp.substr(0, tmp.find(' ')));

        if(myQue.isEmpty()){
            myQue.enqueue(enq);
        }else{
            if(stod(myQue.Rear().substr(myQue.Rear().find(' ')+1))==gpa){
                myQue.enqueue(enq);
            }else if(stod(myQue.Rear().substr(myQue.Rear().find(' ')+1)) < gpa){
                myQue.initialize();
                myQue.enqueue(enq);
            }
        }
    }
    readFile.close();
}




int main(){
    MyCircularStringQueue myQue(100);
    getHighestScoreFromFile(myQue);
    myQue.print();


    
    return 0;
}