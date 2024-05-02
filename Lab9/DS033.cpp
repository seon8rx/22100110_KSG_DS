#include <iostream>
using namespace std;

struct elem {
    int rank;
    string name;
};

class CouponStack{
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
        void rprint();
        int getTopRank() const;
        string getTopName() const;
        CouponStack(int size = 10);
        ~CouponStack(){delete[] list;};
};

CouponStack::CouponStack(int size){
    maxsize = size;
    list = new elem[maxsize];
    initialize();
}

void CouponStack::initialize(){
    top = -1;
}

bool CouponStack::isEmpty() const{
    // if(top==-1) return true;
    // else return false; 
    return (top==-1) ? true : false;
}

bool CouponStack::isFull() const{
    return (top==maxsize-1) ? true : false;
}

void CouponStack::push(const elem& e){
    if(isFull()) return;
    top++;
    list[top] = e;
}

elem* CouponStack::pop(){
    if(isEmpty()) return nullptr;
    return &list[top--];
}

void CouponStack::print(){
    for(int i=top; i>-1; i--){
        cout << list[i].rank << "등 - " << list[i].name << endl;
    }
}

void CouponStack::rprint(){
    while(!isEmpty()){
        cout << list[top].rank << "등 - " << list[top].name << endl;
        pop();
    }
}

int CouponStack::getTopRank() const{
    return isEmpty() ? -1 : list[top].rank;
}
string CouponStack::getTopName() const{
    return isEmpty() ? "-" : list[top].name;
}

int main(){
    int inputSize;
    cin >> inputSize;
    CouponStack couponStack(inputSize);

    while(1){
        char input;
        cin >> input;

        if(input == '+'){
            elem e;
            cin >> e.rank;
            getline(cin, e.name);
            couponStack.push(e);
        }
        else if(input == '-'){
            cout << couponStack.getTopRank() << "등 - " << couponStack.getTopName() << endl;
            couponStack.pop();
        }
        else if(input == 'q'){
            // couponStack.print();
            // cout << couponStack.isEmpty() << endl;
            // cout << endl;
            // couponStack.rprint();
            // cout << couponStack.isEmpty() << endl;

            break;
        }

    }

    return 0;
}