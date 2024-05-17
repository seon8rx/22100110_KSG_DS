#include <iostream>
#include "MyCircularQueue.h"
using namespace std;

int main(){
    int size;
    cin >> size;
    MyCircularQueue myQue(size);

    string input;
    while(input!="q"){
        cin >> input;
        if(input=="en"){
            int enq;
            cin >> enq;
            myQue.enqueue(enq); 
        }else if(input=="de"){
            myQue.dequeue();
        }else if(input=="front"){
            cout << "=> " << myQue.Front() << endl;
        }else if(input=="rear"){
            cout << "=> " << myQue.Rear() << endl;
        }else if(input=="size"){
            cout << "=> " << myQue.size() << endl;
        }else if(input=="empty"){
            if(myQue.isEmpty()) cout << "=> 1" << endl;
            else cout << "=> 0" << endl;
        }else if(input=="print"){
            myQue.print();
        }else if(input=="q"){
            cout << "bye!" << endl;
            break;
        }
    }

    return 0;
}