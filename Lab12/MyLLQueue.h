#include <iostream>
using namespace std;

class N{
    public:
    int data;
    N* link;
    N(){}
    N(int input){
        data = input;
        link = NULL;
    }
};

class Node {
    private:
        N* front;
        N* rear;
    public:
        Node(){front=NULL; rear=NULL;}

        bool isEmpty();
        void enqueue(int input);
        void dequeue();
        void showfront();
        void showrear();
        void displayQueue();

        int getFibonacci();

        int getFront();

};