#include <iostream>
using namespace std;

class Node{
    public:
        char data;
        Node* next;
        Node(char d){
            data = d;
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
        char peek() const;
        void printAll() const;
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

char LinkedStack::peek() const{
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

bool checkString(string s){
    for(char c : s){
        int tmp = c;
        if(!(tmp>=48 || tmp<=57 || tmp==60 || tmp==62 || tmp>=65 || tmp<=90 || tmp>=97 || tmp<=122)){
            return false;
        }
    }
    return true;
}

int main(){
    LinkedStack* linkedStackL = new LinkedStack();
    LinkedStack* linkedStackR = new LinkedStack();

    while(1){
        string input;
        getline(cin, input);
        if(input == "q") break;
        else if(!checkString(input)){
            cout << "Enter char : a-z , A-Z , 0-1 , < , >" << endl;
        }else{
            for(char c : input){
                if(c=='<'){
                    if(!linkedStackL->isEmpty()){
                        linkedStackR->push(Node(linkedStackL->peek()));
                        linkedStackL->pop();
                    }
                }else if(c=='>'){
                    if(!linkedStackR->isEmpty()){
                        linkedStackL->push(Node(linkedStackR->peek()));
                        linkedStackR->pop();
                    }
                }else{
                    linkedStackL->push(Node(c));
                }
            }

            while(!linkedStackL->isEmpty()){
                linkedStackR->push(Node(linkedStackL->peek()));
                linkedStackL->pop();
            }

            cout << "=> ";
            while(!linkedStackR->isEmpty()){
                cout << linkedStackR->peek();
                linkedStackR->pop();
            }
            cout << endl;

        }

        linkedStackL->initialize();
        linkedStackR->initialize();

    }
    linkedStackL->~LinkedStack();
    linkedStackR->~LinkedStack();

    return 0;
}