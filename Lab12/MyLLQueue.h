#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* link;
        Node(){}
        Node(int input){
            data = input;
            link = NULL;
        }
        bool isEmpty();
        void enqueue(int input);
        void dequeue();
        void showfront();
        void showrear();
        void displayQueue();
};