#include <iostream>
#include <string>
#include <math.h>
using namespace std;

typedef struct info{
        string subject;
        int credit;
        int score;
        string grade;
    } Info;

const int SIZE = 3;

int main(){
    Info subj[SIZE];
    int t_credit=0;
    double t_gpa=0.0;
    double gpa[3];
    string g[9] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};

    for(int i=0; i<SIZE; i++){
        cin >> subj[i].subject >> subj[i].credit >> subj[i].score;
    }

    for(int i=0; i<SIZE; i++){
        if(subj[i].score<60) {subj[i].grade = g[8]; gpa[i]=0.0;}
        else if(subj[i].score<65) {subj[i].grade = g[7]; gpa[i]=1.0;}
        else if(subj[i].score<70) {subj[i].grade = g[6]; gpa[i]=1.5;}
        else if(subj[i].score<75) {subj[i].grade = g[5]; gpa[i]=2.0;}
        else if(subj[i].score<80) {subj[i].grade = g[4]; gpa[i]=2.5;}
        else if(subj[i].score<85) {subj[i].grade = g[3]; gpa[i]=3.0;}
        else if(subj[i].score<90) {subj[i].grade = g[2]; gpa[i]=3.5;}
        else if(subj[i].score<95) {subj[i].grade = g[1]; gpa[i]=4.0;}
        else {subj[i].grade = g[0]; gpa[i]=4.5;}
    }

    cout << fixed;
    cout.precision(1);

    for(int i=0; i<SIZE; i++){
        replace(subj[i].subject.begin(), subj[i].subject.end(), '_', ' ');
        cout << subj[i].subject << '(' << subj[i].credit << ')' << "\t\t" << subj[i].grade << ' ' << gpa[i] <<endl;
        t_credit+=subj[i].credit;
        t_gpa+=subj[i].credit*gpa[i];
    }

    cout.precision(2);
    double r=100*t_gpa/(1.0*t_credit);
    r=floor(r);
    r/=100;

    cout << "Total Credits " << t_credit << ',' << " GPA " << r << endl;

}