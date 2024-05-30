#include <iostream>
using namespace std;

void printarray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << "[" << arr[i] << "]" ;
        if(i+1!=n) cout << " ";
    }
    cout << endl;
}

void selectionSort(int *arr, int n){
    int index;
    for(int i=0; i<n-1; i++){
        index = i;
        for(int j=i+1; j<n; j++){
            if(arr[index]>arr[j]) index = j;
        }
        if(index!=i) {
            swap(arr[i], arr[index]);
#ifdef DEBUG
    printarray(arr, n);
#endif
        }
    }
}

int main(){
    int numberOfInput;
    cin >> numberOfInput;
    int a[numberOfInput];
    for(int i=0; i<numberOfInput; i++){
        cin >> a[i];
    }
    int N = sizeof(a) / sizeof(a[0]);
    #ifdef DEBUG
    printarray(a, N);
    #endif
    selectionSort(a, N);
    printarray(a, N);
    return 0;
}