#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* start;
    Node* last;
    int size ;

public:
    LinkedList(){
        start = nullptr;
        last = nullptr;
        size = 0;
    }

    Node* createNode(int input) {
        Node* newNode = new Node();
        newNode->data = input;
        newNode->next = nullptr;
        return newNode;
    }

    void addNode(int input){
        Node* newNode = createNode(input);
        if (start == nullptr) {
            start = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        size++;
    }

    int returnSize(){
        return size;
    }

    void popFront(){
        if(start != nullptr){
            Node* tmp = start;
            start = start->next;
            delete tmp;
            size--;
        }
    }

    void topToBottom(){
        if(size <= 1) return;

        Node* tmp = start;
        start = start->next;
        
        last->next = tmp;
        tmp->next = nullptr;
        last = tmp;
    }

    int topValue(){
        return start->data;
    }

    int lastValue(){
        return last->data;
    }
};

int main(){
    LinkedList linkedList;
    int inputSize;
    cin >> inputSize;

    for(int i=0; i<inputSize; i++){
        linkedList.addNode(i+1);
    }

    while(linkedList.returnSize() != 1){
        linkedList.popFront();
        linkedList.topToBottom();
    }

    cout << linkedList.topValue();

    return 0;
}