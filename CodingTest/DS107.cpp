#include <iostream>
#include "Sorting.h"
using namespace std;

int main(){
    int numOfScoreA, numOfScoreB, numOfScoreT;
    cin >> numOfScoreA >> numOfScoreB;
    numOfScoreT = numOfScoreA + numOfScoreB;

    int classA[numOfScoreA];
    int classB[numOfScoreB];
    int classT[numOfScoreT];

    for(int i=0; i<numOfScoreA; i++) cin >> classA[i];
    for(int i=0; i<numOfScoreB; i++) cin >> classB[i];

    for(int i=0; i<numOfScoreA; i++){
        classT[i] = classA[i];
    }
    for(int i=0; i<numOfScoreB; i++){
        classT[numOfScoreA+i] = classB[i];
    }

    int N = sizeof(classT) / sizeof(classT[0]);
    int *aux = new int[N];
    
    mergeSort(classT, aux, N, 0, N-1);

    for(int i=0; i<numOfScoreT; i++){
        cout << classT[i];
        if(i!=numOfScoreT-1) cout << " ";
    }

    return 0;
}