#include <iostream>
#include <string>
using namespace std;

string ltrim(string input);
string rtrim(string input);
int lastWordLength(string input);

int main(){
    string input;
    getline(cin, input);

    input = ltrim(input);
    input = rtrim(input);
    
    int result = lastWordLength(input);
    cout << result;

    return 0;
}

string ltrim(string input){
    if(input.find_first_not_of(" \t")==string :: npos) return "";   
    return input.substr(input.find_first_not_of(" \t"));
}

string rtrim(string input){
    if(input.find_last_not_of(" \t")==string :: npos) return "";
    return input.substr(0, input.find_last_not_of(" \t")+1);
}

int lastWordLength(string input){
    if(input.find_last_of(" ")==string::npos) return input.length();
    else return input.substr(input.find_last_of(" \t")+1).length();
}