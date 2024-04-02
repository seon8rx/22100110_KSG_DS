#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x1, y1;
    double x2, y2;
    double d;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    d = sqrt(pow(x1-x2,2)+pow(y1-y2,2));

    cout << d << endl;
}