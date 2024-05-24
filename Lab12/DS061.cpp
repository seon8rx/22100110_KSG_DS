#include <iostream>
#include "MyLLQueue.h"
using namespace std;

int main(){
    Node n;

    int choice, flag=1, value;
    while( flag == 1){
        cout<<"1.enqueue 2.dequeue 3.showfront 4. showrear 5.displayQueue 6.exit > ";
        cin>>choice;
        switch (choice){
            case 1: 
            cout<<"Enter Value: ";
            cin>>value;
            n.enqueue(value);
            cout << endl;
            break;
            case 2:
            n.dequeue();
            cout << endl;
            break;
            case 3:
            n.showfront();
            cout << endl;
            break;
            case 4:
            n.showrear();
            cout << endl;
            break;
            case 5:
            n.displayQueue();
            cout << endl;
            break;
            case 6:
            flag = 0;
            break;
        }
    }
    cout << "bye!";
    return 0;
}