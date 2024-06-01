#include <iostream>
#include "Sorting.h"
using namespace std;

int main(){
    int menu;
    int numberOfInput;
    int N, M;
    while(1){
        cout << "1.selection 2.insertion 3.bubble 4.quick 5.merge 6.exit > ";
        cin >> menu;
        if(menu==6) break;

        switch (menu){
        case 1:{
            cout << "Enter count: ";
            cin >> numberOfInput;
            cout << "Enter numbers: ";
            int a[numberOfInput];
            for(int i=0; i<numberOfInput; i++){
                cin >> a[i];
            }
            N = sizeof(a) / sizeof(a[0]);
            cout << "===selectionsort===" << endl;
            #ifdef DEBUG
            printarray(a, N);
            #endif
            selectionSort(a, N);
            printarray(a, N);
            break;
        }
        case 2:{
            cout << "Enter count: ";
            cin >> numberOfInput;
            cout << "Enter numbers: ";
            int b[numberOfInput];
            for(int i=0; i<numberOfInput; i++){
                cin >> b[i];
            }
            N = sizeof(b) / sizeof(b[0]);
            cout << "===insertionsort===" << endl;
            #ifdef DEBUG
            printarray(b, N);
            #endif
            insertionSort(b, N);
            #ifndef DEBUG
            printarray(b, N);
            #endif
            break;
        }
        case 3:{
            cout << "Enter count: ";
            cin >> numberOfInput;
            cout << "Enter numbers: ";
            int ca[numberOfInput];
            int cd[numberOfInput];
            for(int i=0; i<numberOfInput; i++){
                cin >> ca[i];
            }
            N = sizeof(ca) / sizeof(ca[0]);
            for(int i=0; i<numberOfInput; i++){
                cd[i] = ca[i];
            }
            M = sizeof(cd) / sizeof(cd[0]);

            cout << "===bubblesort===" << endl;
            cout << "=== ascending order ===" << endl;
            #ifdef DEBUG
            printarray(ca, N);
            #endif
            bubbleSortAsc(ca, N);
            printarray(ca, N);
            
            cout << "=== descending order ===" << endl;
            #ifdef DEBUG
            printarray(cd, M);
            #endif
            bubbleSortDes(cd, M);
            printarray(cd, M);

            break;
        }
        case 4:{
            cout << "Enter count: ";
            cin >> numberOfInput;
            cout << "Enter numbers: ";
            int d[numberOfInput];
            for(int i=0; i<numberOfInput; i++){
                cin >> d[i];
            }
            N = sizeof(d) / sizeof(d[0]);
            cout << "===quiclsort===" << endl;
            #ifdef DEBUG
            printarray(d, N);
            #endif
            quickSort(d, 0, N-1, N);
            printarray(d, N);
            break;
        }
        case 5: {
            cout << "Enter count: ";
            cin >> numberOfInput;
            cout << "Enter numbers: ";
            int e[numberOfInput];
            for(int i=0; i<numberOfInput; i++){
                cin >> e[i];
            }
            N = sizeof(e) / sizeof(e[0]);
            int *aux = new int[N];
            cout << "===mergesort===" << endl;
            mergeSort(e, aux, N, 0, N-1);
            printarray(e, N);
            break;
        }
        default:
            break;
        }
    }
    return 0;
}