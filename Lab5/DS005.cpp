#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    char input[50];
    int space=0;
    int alphabet[26]={0}; // 0~25: A(a)~Z(z)
    string b="blanks";
    string output[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

    cin.getline(input, 50);

    // for(int i=0; i<strlen(input); i++){
    //     tolower(input[i]);
    //     if(isspace(input[i])) space++;
    //     for(int j=0; j<sizeof(alphabet)/sizeof(alphabet[0]); j++){
    //         if(input[i]==65+j || input[i]==97+j) alphabet[j]++;
    //     }
    // }

    int i;
    for(int j=0; j<strlen(input); j++){
        i=tolower(input[j])-'a';
        if(isspace(input[j])) space++;
        else if(isalpha(input[j])) alphabet[i]++;
    }
    

    if(space) cout << b << " : " << space << endl;

    for(int a=0; a<sizeof(output)/sizeof(output[0]); a++){
        if(alphabet[a]) cout << output[a] << " : " << alphabet[a] << endl;
    }

}