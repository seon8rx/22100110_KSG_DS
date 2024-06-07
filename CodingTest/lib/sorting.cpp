#include "Sorting.h"

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

int isSorted(char *a, int i, int j){
    return a[i] <= a[j];
}

void merge(int *a, int *aux, int lo, int mi, int hi){
    for(int k=lo; k<=hi; k++){
        aux[k] = a[k];
    }

    int i = lo;
    int j = mi + 1;
    for(int k=lo; k <= hi; k++){
        if(i > mi) a[k] = aux[j++];
        else if(j > hi) a[k] = aux[i++];
        else if(aux[j] > aux[i]) a[k] = aux[j++];
        else a[k] = aux[i++];
    }
}

void mergeSort(int *a, int *aux, int N, int lo, int hi){

    if(hi<=lo) return;
    int mi = lo + (hi - lo) / 2;
    mergeSort(a, aux, N, lo, mi);
    mergeSort(a, aux, N, mi+1, hi);
#ifdef DEBUG
    for(int i=0 ; i<N; i++){
        cout <<'[' << a[i] << ']';
        if(i+1!=N) cout << " ";
    }
    cout << endl;
#endif
    if(a[mi] >= a[mi+1]) return;
    merge(a, aux, lo, mi, hi);
    
}