#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1, s2;

    cin >> s1;
    cout << s1 << endl;

    cin.ignore();

    getline(cin, s2);
    cout << s2 ;

    //cout << "Hello World" << endl;
    return 0;
}