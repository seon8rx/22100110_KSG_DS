#include <iostream>
using namespace std;

int main(){
    int height, weight;
    double bmi;

    cin >> height >> weight;

    bmi = (weight)/((height/100.0)*(height/100.0));
    if(bmi>=25) cout << "Yes" << endl;
    else cout << "No" << endl;    
    return 0;
}