#include <iostream>
using namespace std;

class MinHeap {
private:
    int arr[30];
    int length;
public:
    MinHeap(){
        length = 0;
    }
    // ~MinHeap(){
    //     delete[] arr;
    // }

    void insert(int value){
        arr[length++] = value;
        minHeapifyUP(length-1);
    }

    int deleteOne(){
        if(isEmpty()) return -1;
        int tmp = arr[0];
        arr[0] = arr[length-1];
        length--;
        minHeapifyDown(0);

        return tmp;
    }

    int peek(){
        return isEmpty() ? -1 : arr[0];
    }

    int size(){
        return length;
    }

    bool isEmpty(){
        return length == 0;
    }

    void swap(int p, int c){
        int tmp = arr[p];
        arr[p] = arr[c];
        arr[c] = tmp;
    }

    void minHeapifyUP(int index){
        while(index > 0 && (arr[index] < arr[(index-1)/2])){
            swap((index-1)/2, index);
            index = (index-1)/2;
        }
    }

    void minHeapifyDown(int root){
        while(2*root+1 < length){
            int child = 2*root+1;
            if(child < length-1 && (arr[child] > arr[child+1])) child++;
            if(!(arr[root] > arr[child])) break;
            swap(root, child);
            root = child;
        }
    }

    void printHeap(){
        for(int i=0; i<length; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
};

int main(){
    MinHeap minheap;
    int menu, input;

    while(1){
        cout << "1. Array to minHeap 2.insert 3.delete 4.print 0.quit > ";
        cin >> menu;
        switch(menu){
            case 1:
                int arrLength;
                cin >> arrLength;
                for(int i=0; i<arrLength; i++){
                    cin >> input;
                    minheap.insert(input);
                }
                cout << "minHeap => ";
                minheap.printHeap();
                break;
            case 2:
                cin >> input;
                minheap.insert(input);
                cout << "minHeap => ";
                minheap.printHeap();
                break;
            case 3:
                cout << "min value : " << minheap.deleteOne() << endl;
                cout << "minHeap => ";
                minheap.printHeap();
                break;
            case 4:
                minheap.printHeap();
                break;
            default:
                break;
        }

        if(menu == 0) break;
    }

    cout << "bye!";


    return 0;
}