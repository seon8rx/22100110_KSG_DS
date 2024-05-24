#include "MyLLQueue.h"

bool Node::isEmpty(){
    bool result = false;
    if(front == NULL && rear == NULL) result=true;;
    return result;
}

void Node::enqueue(int input){
    N* tmp = new N(input);
    if(isEmpty()){
        front = tmp;
        rear = tmp;
    }else{
        rear->link = tmp;
        rear = tmp;
    }
}

void Node::dequeue(){
    if(isEmpty()){
        cout << "Queue is empty!" << endl;
        return;
    }

    if(front == rear){
        free(front);
        front = rear = NULL;
    }else{
        N* tmp = front;
        front = front -> link;
        free(tmp);
    }

}

void Node::showfront(){
    if(isEmpty()) cout << "Queue is empty" << endl;
    else cout << "element at front is:" << front->data << endl;
}

void Node::showrear(){
    if(isEmpty()) cout << "Queue is empty" << endl;
    else cout << "element at rear is:" << rear->data << endl;
}

void Node::displayQueue(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;        
    }
    N* tmp = front;
    while(tmp != NULL){
        cout << tmp->data;
        if(tmp->link != NULL) cout << " -> ";
        tmp = tmp->link;
    }
    cout << endl;
}

int Node::getFibonacci(){
    return front->data + front->link->data;
}

int Node::getFront(){
    return front->data;
}