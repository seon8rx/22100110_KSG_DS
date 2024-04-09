#include <iostream>
using namespace std;

int* maxNum(int input[], int size);

int main(){
    int num, sum=0;
    cin >> num;

    int* input = new int[num];

    for(int i=0; i<num; i++){
        cin >> input[i];
        sum+=input[i];
    }

    int* max = maxNum(input, num);

    cout << sum << " " << *max;
    
    return 0;
}

int* maxNum(int input[], int size){
    int* max;
    for(int i=0; i<size; i++){
        if(i==0) max = &input[i];
        if(*max<input[i]) max = &input[i];
    }
    return max;
}