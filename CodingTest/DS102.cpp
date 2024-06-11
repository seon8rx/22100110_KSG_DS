#include <iostream>
#include "Sorting.h"

using namespace std;

int main(){
    int deckSize, maxNumExchange;
    int numberOfExchange = 0;
    int result = 0;
    cin >> deckSize >> maxNumExchange;

    int deckA[deckSize];
    int deckB[deckSize];

    for(int i=0; i<deckSize; i++) cin >> deckA[i];
    for(int i=0; i<deckSize; i++) cin >> deckB[i];

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