#include <iostream>
using namespace std;

void printarray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << "[" << arr[i] << "]" ;
        if(i+1!=n) cout << " ";
    }
    cout << endl;
}

void quickSort(int *arr, int low, int high, int arrsize){
    if (low >= high) return;
    
    int pivot = low;
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= arr[pivot]) i++;
        while (j > low && arr[j] >= arr[pivot]) j--;
        
        if (i > j) {
            swap(arr[j], arr[pivot]);
        } else {
            swap(arr[i], arr[j]);
        }
    }
    
    quickSort(arr, low, j - 1, arrsize);
    quickSort(arr, j + 1, high, arrsize);
    #ifdef DEBUG
    printarray(arr, arrsize);
    #endif
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
    quickSort(a, 0, N-1, N);
    printarray(a, N);
    return 0;
}