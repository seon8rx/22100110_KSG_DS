#include <iostream>
using namespace std;

int main(){
    char input[20];
    cin >> input;

    int result=0;
    
    for(int i=0; i<strlen(input); i++){
        if(input[i]=='I') {result+=1;}
        else if(input[i]=='V') {
            if(input[i-1]=='I') result+=3;
            else result+=5;
        }else if(input[i]=='X') {
            if(input[i-1]=='I') result+=8;
            else result+=10;
        }else if(input[i]=='L') {
            if(input[i-1]=='X') result+=30;
            else result+=50;
        }else if(input[i]=='C') {
            if(input[i-1]=='X') result+=80;
            else result+=100;
        }else if(input[i]=='D') {
            if(input[i-1]=='C') result+=300;
            else result+=500;
        }else if(input[i]=='M') {
            if(input[i-1]=='C') result+=800;
            else result+=1000;
        }
    }

    cout << result << endl;

    return 0;
}