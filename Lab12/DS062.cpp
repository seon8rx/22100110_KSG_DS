#include <iostream>
#include "MyLLQueue.h"
using namespace std;

int main(){
    Node node;

    int input;
    cin >> input;

    int prevprev;
    int prev;

    for(int i=1; i<=input; i++){
        if(i%100==11 || i%100==12 || i%100==13){
            cout << i << "th : ";
        }else if(i%10==1){
            cout << i << "st : ";
        }else if(i%10==2){
            cout << i << "nd : ";
        }else if(i%10==3){
            cout << i << "rd : ";
        }else{
            cout << i << "th : ";
        }

        if(i==1 || i==2) {
            node.enqueue(1);
            cout << "1" << endl;
        }else{
            int fib = node.getFibonacci();
            node.enqueue(fib);
            node.dequeue();
            cout << fib << endl;
        }
    }

    return 0;
}