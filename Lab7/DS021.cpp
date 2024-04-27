#include <iostream>
using namespace std;

class Student {
        double getAvg() const;
    public :
        string name;
        string sid;
        int *score;
        void print() const;
};

double Student::getAvg() const{
    return (1.0*score[0]+score[1]+score[2])/3.0;
}

void Student::print() const{
    cout << "[" << sid << "] " << name << endl;
    cout << "The Average score is ";
    printf("%.1f", getAvg());
}

int main(){

    Student s1;
    s1.score = new int[3];

    cin >> s1.sid;
    for(int i=0; i<3; i++){
        cin >> s1.score[i];
    }
    cin.ignore();

    getline(cin,s1.name);

    s1.print();
    
    return 0;
}