#include <iostream>
using namespace std;

//10:36

struct Menu{
    string name;
    int price;
};

struct Cafe{
    string name;
    int msize;
    Menu *list;
};

void addCafe(Cafe &r1);
void addMenu(Menu &m1);
void displayMenus(Cafe &r1);

int main(){
    Cafe c;
    
    addCafe(c);

    // for(Menu a : c.list[]){
    //     addMenu(a);
    // }
    for(int i=0; i<c.msize; i++){
        addMenu(c.list[i]);
    }

    displayMenus(c);

    delete[] c.list;

    return 0;
}

void addCafe(Cafe &r1){
    getline(cin, r1.name);
    cin >> r1.msize;
    r1.list = new Menu[r1.msize];
}

void addMenu(Menu &m1){
    cin >> m1.name >> m1.price;
}

void displayMenus(Cafe &r1){
    cout << "=====" << r1.name << "=====" << endl;
    // for(Menu m : r1.list){
    //     cout << m.name << " " << m.price << endl;
    // }

    for(int i=0; i<r1.msize; i++){
        cout << r1.list[i].name << " " << r1.list[i].price << endl;
    }
    cout << "=================";
}