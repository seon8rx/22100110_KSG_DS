#include <iostream>
using namespace std;

void printarray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << "[" << arr[i] << "]" ;
        if(i+1!=n) cout << " ";
    }
    cout << endl;
}

void bubbleSortAsc(int *arr, int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        #ifdef DEBUG
        printarray(arr, n);
        #endif
    }
}

void bubbleSortDes(int *arr, int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        #ifdef DEBUG
        printarray(arr, n);
        #endif
    }
}

int main(){
    int numberOfInput;
    cin >> numberOfInput;
    int a[numberOfInput];
    int b[numberOfInput];
    for(int i=0; i<numberOfInput; i++){
        cin >> a[i];
    }
    int N = sizeof(a) / sizeof(a[0]);
    for(int i=0; i<numberOfInput; i++){
        b[i] = a[i];
    }
    int M = sizeof(b) / sizeof(b[0]);

    cout << "=== ascending order ===" << endl;
    #ifdef DEBUG
    printarray(a, N);
    #endif
    bubbleSortAsc(a, N);
    printarray(a, N);
    
    cout << "=== descending order ===" << endl;
    #ifdef DEBUG
    printarray(b, M);
    #endif
    bubbleSortDes(b, M);
    printarray(b, M);
    return 0;
}