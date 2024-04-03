#include <iostream>
using namespace std;

int main(){
    struct st_score{
        int kor, eng, math;
        int total;
        double average;
    };

    struct st_score s;
    cin >> s.kor >> s.eng >> s.math;

    s.total = 0;
    s.total = s.kor + s.eng + s.math;
    s.average = s.total/3.0;

    cout << fixed;
    cout.precision(1);
    cout << s.total << " " << s.average << endl;

    if(s.kor >= 70) cout << "Korean -  Pass" << endl;
    else cout << "Korean -  Fail" << endl;

    if(s.eng >= 70) cout << "English -  Pass" << endl;
    else cout << "English -  Fail" << endl;

    if(s.math >= 70) cout << "Math -  Pass" << endl;
    else cout << "Math -  Fail" << endl;

    return 0;
}