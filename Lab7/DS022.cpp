#include <iostream>
using namespace std;

class EnglishTest{
        string name;
        int lc;
        int rc;
    public :
        // EnglishTest(){
        //     name = "";
        //     lc = rc =0;
        // }
        EnglishTest(){
            getline(cin, name);
            while(1){
                cout << "LC> ";
                cin >> lc;
                if(scoreCheck(lc)) break;
            }
            while(1){
                cout << "RC> ";
                cin >> rc;
                if(scoreCheck(rc)) break;
            }
        }
        EnglishTest(string namee, int lcc, int rcc){
            name = namee;
            lc = lcc;
            rc = rcc;
        }

        bool scoreCheck(int input){
            if(input>=0 && input <=495) return true;
            else return false;
        }

        string passFail(int input){
            if(input>=300) return "Pass";
            else return "Fail";
        }

        int totalScore(EnglishTest et){
            return et.lc+et.rc;
        }

        void printInfo(EnglishTest et){
            cout << "[" << et.name << "]" << endl;
            if(scoreCheck(et.lc))
            cout << "LC - " << et.lc << " " << passFail(et.lc) << endl;
            else
            cout << "LC - out of range" << endl;
            if(scoreCheck(et.rc))
            cout << "RC - " << et.rc << " " << passFail(et.rc) << endl;
            else
            cout << "RC - out of range" << endl;
            if(scoreCheck(et.lc)){
                if(scoreCheck(et.rc)){
                    cout << "Total - " << totalScore(et);
                }else{
                    cout << "RC - out of range";
                }
            }else{
                cout << "LC - out of range";
            }
        }
};

int main(){

    EnglishTest et1("Constructor with parameter", 4400, 280);
    et1.printInfo(et1);


    return 0;
}