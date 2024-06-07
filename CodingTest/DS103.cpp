#include <iostream>
#include "Sorting.h"
using namespace std;

int main(){
    int numOfStudents, prize;
    cin >> numOfStudents >> prize;

    int a[numOfStudents];
    for(int i=0; i<numOfStudents; i++){
        cin >> a[i];
    }

    int N = sizeof(a) / sizeof(a[0]);
    int *aux = new int[N];
    
    mergeSort(a, aux, N, 0, N-1);

    cout << a[prize-1];

    return 0;
}