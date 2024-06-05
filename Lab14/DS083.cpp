#include <iostream>
using namespace std;

bool (*comp)(int*, int, int);

bool less(int* a, int i, int j){
    return a[i] < a[j];
}

bool more(int* a, int i, int j){
    return a[i] > a[j];
}

void swap(int* h, int p, int c){
    int item = h[p];
    h[p] = h[c];
    h[c] = item;
}

void swim(int* a, int k, int N){
    
    while(k>1 && comp(a, k/2, k)){
        swap(a, k, k/2);
        k = k/2;
    }

}

void sink(int* a, int k, int N){

    while(2*k <= N){
        int j = 2*k;
        if(j<N && comp(a, j, j+1)) j++;
        if(!comp(a, k, j)) break;
        swap(a, k, j);
        k = j;
    }

}

void grow(int* a, int key, int& N){
    a[++N] = key;
    swim(a, N, N);
}

void trim(int* a, int c, int& N){
    int index;
    for(int i=1; i<N; i++){
        if(a[i] == c){
            index = i;
            break;
        }
    }
    if(index == 0) return;
    swap(a, index, N--);
    sink(a, index, N);
}

void heapify(int* a, int N){
    for(int i=N/2; i>=1; i--){
        sink(a, i, N);
    }
}

void show(int* a, int N) {
	cout << "==> Heap : ";
	for (int i = 1; i <= N; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
    int menu;
    int value;
    int maxHeap[21];
    maxHeap[0] = -2000000000;
    int N = 0;

    comp = ::less;

    while(1){
        cout << "1. insert 2. delete 3. print 4. quit > ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "new value? ";
            cin >> value;
            grow(maxHeap, value, N);
            show(maxHeap, N);
            break;
        
        case 2:
            cout << "=> Delete ";
            cin >> value;
            trim(maxHeap, value, N);
            show(maxHeap, N);
            break;
        
        case 3:
            show(maxHeap, N);
            break;
        
        default:
            break;
        }

        if(menu == 4) {
            cout << "Bye!" << endl;
            break;
        }

    }
    return 0;
}