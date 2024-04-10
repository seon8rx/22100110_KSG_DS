#include <iostream>
#include <cctype>
using namespace std;
//#define SIZE 2

struct Product {
    string name;
    int price;
    string manufac;
};

bool compareProduct(Product p[]);
void printResult(bool b, Product p[]);

int main(){
    Product p[2];

    for(int i=0; i<2; i++){
        cin >> p[i].name >> p[i].price >> p[i].manufac;
    }

    printResult(compareProduct(p), p);

    return 0;
}

bool compareProduct(Product p[]){
    if(p[0].price != p[1].price) return false;
    if (p[0].name.length() != p[1].name.length()) return false;
    for(int i=0; i<p[0].name.length(); i++){
        if (tolower(p[0].name[i]) != tolower(p[1].name[i])) return false;
    }
    return true;
}

void printResult(bool b, Product p[]){
    if(b){
        cout << p[0].name << " is equal";
    }else{
        cout << p[0].name << " and " << p[1].name << " is not equal.";
    }
}