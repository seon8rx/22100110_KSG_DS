#include <iostream>
#include <fstream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int s){
            data = s;
            next = NULL;
        }
};

class LinkedStack{
    private:
        Node* stacktop;
    public:
        LinkedStack();
        ~LinkedStack();
        void initialize();
        bool isEmpty() const;
        void push(const Node& n);
        void pop();
        int peek() const;
        void printAll() const;
        int countStack() const;
};

LinkedStack::LinkedStack(){
    stacktop = nullptr;
}

LinkedStack::~LinkedStack(){
    initialize();
}

void LinkedStack::initialize(){
    // if(isEmpty()) return;
    // Node* tmp = stacktop;
    // while(tmp!=nullptr){
    //     Node* next = tmp->next;
    //     delete tmp;
    //     tmp = next;
    // }
    while(!isEmpty()){
        pop();
    }
}

bool LinkedStack::isEmpty() const{
    return stacktop==nullptr;
}

void LinkedStack::push(const Node& n){
    Node* node = new Node(n.data);
    if(isEmpty()){
        stacktop = node;
        return;
    }
    
    node->next = stacktop;
    stacktop = node;
}

void LinkedStack::pop(){
    if(isEmpty()){
        return;
    }
   Node* tmp = stacktop;
   stacktop = stacktop->next;
   delete tmp;

}

int LinkedStack::peek() const{
    return stacktop->data;
}

void LinkedStack::printAll() const{
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return;
    }

    int count=0;
    Node* tmp = stacktop;
    while(tmp!=nullptr){
        cout << tmp->data;
        if(tmp->next!=nullptr){
            cout << " -> ";
        }
        tmp = tmp->next;
        count++;
    }
    cout << " (" << count << " nodes)" << endl;

}

int LinkedStack::countStack() const{
    int count=0;
    Node* tmp = stacktop;
    while(tmp!=nullptr){
        tmp = tmp->next;
        count++;
    }
    return count;
}

int main(){
    LinkedStack* linkedStack = new LinkedStack();

    ifstream readFile;
    readFile.open("DS042-1.txt");

    while(!readFile.eof()){
        int result=0;
        string tmp;
        getline(readFile, tmp);
        string s;
        int num, errorcheck=0;
        string error;
        for(char c : tmp){
            if(errorcheck==0){
                error += c;
                if(c=='#'){
                    continue;
                }else if(c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9' || c=='0'){
                    s = s+c;
                }else if(c==' '){
                    if(s.empty()) continue;
                    num = stoi(s);
                    linkedStack->push(Node(num));
                    s.clear();
                }else if(c=='+' || c=='-' || c=='*' || c=='/'){
                    if(linkedStack->countStack()<2){
                        if(error[0] == ' ') error.erase(0,1);
                        cout << error;
                        errorcheck=1;
                        linkedStack->initialize();
                        continue;
                    }
                    if(c=='+'){
                        int b = linkedStack->peek();
                        linkedStack->pop();
                        int a = linkedStack->peek();
                        linkedStack->pop();
                        linkedStack->push(Node(a+b));
                    }else if(c=='-'){
                        int b = linkedStack->peek();
                        linkedStack->pop();
                        int a = linkedStack->peek();
                        linkedStack->pop();
                        linkedStack->push(Node(a-b));
                    }else if(c=='*'){
                        int b = linkedStack->peek();
                        linkedStack->pop();
                        int a = linkedStack->peek();
                        linkedStack->pop();
                        linkedStack->push(Node(a*b));
                    }else if(c=='/'){
                        int b = linkedStack->peek();
                        linkedStack->pop();
                        int a = linkedStack->peek();
                        linkedStack->pop();
                        if(b==0){
                            //cout << '#' << a << " " << '#' << b <<  " /" << endl;
                            cout << error << endl;
                            cout << "=> Division by 0" <<endl;
                            error.clear();
                            // errorcheck=0;
                        }else{
                            linkedStack->push(Node(a/b));
                        }
                    }
                }else if(c=='='){
                    if(linkedStack->countStack()==1){
                        cout << tmp << " " << linkedStack->peek() << endl;
                        linkedStack->pop();
                    }else if(linkedStack->isEmpty()){
                        cout << tmp << endl;
                        cout << "=> Expression error !!!" << endl;
                        linkedStack->initialize();
                    }else{
                        cout << tmp << endl;
                        cout << "=> Too many operands !!!" << endl;
                        linkedStack->initialize();
                    }
                }else{
                    cout << tmp << endl;
                    cout << "=> Expression error !!!" << endl;
                    linkedStack->initialize();
                    break;
                }
            }else{
                cout << c;
            }
        }
        if(errorcheck==1){
            cout << endl;
            cout << "=> Expression error !!!" << endl;
        }
            
    }
    readFile.close();
    linkedStack->~LinkedStack();
    return 0;
}