#include <iostream>
using namespace std;

int main(){
    int m, d;
    int sum=0;

    cin >> m >> d;

    for(int i=1; i<m; i++){
        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) sum+=31;
        else if(i==4 || i==6 || i==9 || i==11) sum+=30;
        else sum+=28;
    }
    sum+=d;

    cout << sum <<endl;

    return 0;
}