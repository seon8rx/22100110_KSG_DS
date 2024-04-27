#include <iostream>
using namespace std;

class Prod{
    private :
        string name;
        int price;
        int discount;
        string amount;
        string manuf;
        int size;
    public :
        int addProd(int s);
        void listProd();
        int discountedPrice();
};

int Prod::addProd(int s){
    cin.ignore();
    getline(cin, name);
    cin >> price >> discount >> amount >> manuf;
    s++;
    return s;
}

void Prod::listProd(){
    if(discount!=0)
        cout << discountedPrice() << " (-" << discount << "%) " << name << " " << amount << " " << manuf <<endl;
    else
        cout << discountedPrice() << " (" << discount << "%) " << name << " " << amount << " " << manuf <<endl;
}

int Prod::discountedPrice(){
    return price - (price*discount/100);
}

int main(){
    int size = 10;
    Prod* item = new Prod[size];

    int s=0;
    int input=0;
    
    while(1){
        cout << "1. Add 2. List 3. Quit > ";
        cin >> input;
        if(input == 1) s=item[s].addProd(s);
        else if(input == 2){
            for(int i=0; i<s; i++){
                item[i].listProd();
            }
        }else break;
    }

    delete[] item;
    
    return 0;
}