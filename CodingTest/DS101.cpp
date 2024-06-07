#include <iostream>
#include <cassert>
#include "Sorting.h"
using namespace std;

int main(){
    int numberOfInput;
    cin >> numberOfInput;
    if(numberOfInput < 1 || numberOfInput > 500) exit(0);
    
    int a[numberOfInput];
    for(int i=0; i<numberOfInput; i++){
        cin >> a[i];
        if(a[i] < 1 || a[i] > 100000) exit(0);
    }

    int N = sizeof(a) / sizeof(a[0]);
    int *aux = new int[N];
    
    mergeSort(a, aux, N, 0, N-1);

    for(int i=0 ; i<N; i++){
        cout << a[i];
        if(i+1!=N) cout << " ";
    }
    cout << endl;

    return 0;
}