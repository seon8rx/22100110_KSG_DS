#include <iostream>
using namespace std;

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
        else if(aux[j] < aux[i]) a[k] = aux[j++];
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
    if(a[mi] <= a[mi+1]) return;
    merge(a, aux, lo, mi, hi);
    
}

int main(){

    int numberOfInput;
    cin >> numberOfInput;
    int a[numberOfInput];
    for(int i=0; i<numberOfInput; i++){
        cin >> a[i];
    }
    int N = sizeof(a) / sizeof(a[0]);
    int *aux = new int[N];
    mergeSort(a, aux, N, 0, N-1);

    for(int i=0 ; i<N; i++){
        cout <<'[' << a[i] << ']';
        if(i+1!=N) cout << " ";
    }
    cout << endl;

    return 0;
}