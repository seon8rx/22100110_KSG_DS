#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int inputSize, tmp;
    cin >> inputSize;
    vector<int> v;
    for(int i=0; i<inputSize; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    unordered_map<int, int> map;
    int result = 0;
    int resultCount = 0;

    for(int x : v){
        map[x]++;
        if(map[x] > resultCount){
            result = x;
            resultCount = map[x];
        }
    }

    cout << result;

    return 0;
}