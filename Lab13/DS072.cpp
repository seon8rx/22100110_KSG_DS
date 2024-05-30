#include <iostream>
using namespace std;

void printarray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << "[" << arr[i] << "]" ;
        if(i+1!=n) cout << " ";
    }
    cout << endl;
}

void insertionSort(int *arr, int n){

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]<arr[j]){
                int tmp = arr[i];
                for(int k=i; k>j; k--){
                    arr[k] = arr[k-1];
                }
                arr[j] = tmp;
                #ifdef DEBUG
                printarray(arr, n);
                #endif
                break;
            }
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
    insertionSort(a, N);
    #ifndef DEBUG
    printarray(a, N);
    #endif
    return 0;
}