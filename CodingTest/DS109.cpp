#include <iostream>
#include <stack>
using namespace std;

int main(){
    string input;
    getline(cin, input);
    
    stack<char> stack;
    
    for(char c : input){
        if(!stack.empty()){
            if(stack.top() != c){
                stack.push(c);
            }else{
                stack.pop();
            }
        }else{
            stack.push(c);
        }
    }

    string result = "";

    while(!stack.empty()) {
        result += stack.top();
        stack.pop();
    }
    for(char c : result) stack.push(c);

    while(!stack.empty()){
        cout << stack.top();
        stack.pop();
    }

    return 0;
}