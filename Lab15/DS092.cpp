#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;
    int inputSize, nth, tmp;
    cin >> inputSize >> nth;

    for(int i=0; i<inputSize; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    make_heap(v.begin(), v.end());

    for(int i=0; i<nth-1; i++){
        pop_heap(v.begin(), v.end()-i);
    }
    
    cout << v.front();

    return 0;
}