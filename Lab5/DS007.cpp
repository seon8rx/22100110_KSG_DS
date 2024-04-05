#include <iostream>
using namespace std;

int main(){
    char input[20];
    cin >> input;

    int result=0;
    
    for(int i=0; i<strlen(input); i++){
        if(input[i]=='I') result+=1;
        else if(input[i]=='V') result+=5;
        else if(input[i]=='X') result+=10;
        else if(input[i]=='L') result+=50;
        else if(input[i]=='C') result+=100;
        else if(input[i]=='D') result+=500;
        else if(input[i]=='M') result+=1000;
    }

    cout << result << endl;
}