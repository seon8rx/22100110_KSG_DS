#include <iostream>
#include <string>
using namespace std;
#define SIZE 3

string findPrefix(string* input);

int main(){
    string input[SIZE];
    for(int i=0; i<SIZE; i++){
        cin >> input[i];
    }

    string result = findPrefix(input);

    cout << result;

    return 0;
}

string findPrefix(string* input){
    int shortestString;
    for(int i=0; i<SIZE; i++){
        if(i==0) shortestString = input[i].length();
        if(shortestString > input[i].length()) shortestString = input[i].length();
    }

    string result_prefix = "";
    char tmp;
    bool check = true;
    for(int i=0; i<shortestString; i++){
        tmp = input[0][i];
        for(int j=1; j<SIZE; j++){
            if(input[j][i] != tmp){
                check = false;
                break;
            }
        }
        if(check) result_prefix += tmp;
        else break;
    }
    if(result_prefix.compare("")==0) return "?";
    else return result_prefix;
}