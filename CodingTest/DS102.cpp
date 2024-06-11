#include <iostream>
#include "Sorting.h"

using namespace std;

int main(){
    int deckSize, maxNumExchange;
    int numberOfExchange = 0;
    int result = 0;
    cin >> deckSize >> maxNumExchange;
    if(deckSize < 1 || deckSize > 500) exit(0);
    if(maxNumExchange < 1 || maxNumExchange > deckSize) exit(0);

    int deckA[deckSize];
    int deckB[deckSize];

    for(int i=0; i<deckSize; i++) {
        cin >> deckA[i];
        if(deckA[i] < 1 || deckA[i] > 100000) exit(0);
    }
    for(int i=0; i<deckSize; i++) {
        cin >> deckB[i];
        if(deckB[i] < 1 || deckB[i] > 100000) exit(0);
    }

    selectionSort(deckA, deckSize); selectionSort(deckB, deckSize);

    for(int i=0; i<maxNumExchange; i++){
        if(deckA[i] >= deckB[deckSize-1-i]) break;
        int tmp = deckA[i];
        deckA[i] = deckB[deckSize-1-i];
        deckB[deckSize-1-i] = tmp;
        numberOfExchange++;
    }

    for(int x : deckA){
        result += x;
    }

    cout <<numberOfExchange << " " << result;

    return 0;
}