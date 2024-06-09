#include <iostream>
using namespace std;

struct Node {
    int data;
    string name;
    Node* next;
};

class LinkedList {
private:
    Node* start;
    Node* last;

public:
    LinkedList(){
        start = nullptr;
        last = nullptr;
    }

    ~LinkedList() {
        clearLinked();
    }

    void swapNode(Node* x, Node* y) {
        int tmp = x->data;
        x->data = y->data;
        y->data = tmp;

        string t = x->name;
        x->name = y->name;
        y->name = t;
    }

    Node* createNode(int input, string inputName) {
        Node* newNode = new Node();
        newNode->data = input;
        newNode->name = inputName;
        newNode->next = nullptr;
        return newNode;
    }

    void addLast(int input, string inputName) {
        Node* newNode = createNode(input, inputName);
        if (start == nullptr) {
            start = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    void printLinked() const {
        Node* tmp = start;
        int i=1;
        while (tmp != nullptr) {
            cout << i << "> " << tmp->data << " " << tmp->name << endl;
            tmp = tmp->next;
            i++;
        }
    }

    void clearLinked() {
        Node* tmp;
        while (start != nullptr) {
            tmp = start;
            start = start->next;
            delete tmp;
        }
        start = nullptr;
        last = nullptr;
    }

    void init(int size) {
        int number;
        string name;
        clearLinked();
        cout << "Enter info... \n";
        for (int i = 0; i < size; i++) {
            cin >> number;
            cin >> name;
            addLast(number, name);
        }
    }

    void bubbleLinked(){
        bool check;
        Node* key;
        Node* tmp = nullptr;

        do {
            check = false;
            key = start;

            while (key->next != tmp) {
                if (key->data < key->next->data) {
                    swapNode(key, key->next);
                    check = true;
                }
                key = key->next;
            }
            tmp = key;
        } while (check);

    }

    
};

int main() {
    LinkedList list;
    int choice;
    int type;

    while (true) {
        cout << "How many numbers do you want to create (0:exit) ... ";
        cin >> choice;
        if (choice == 0) break;
        
        list.init(choice);
        list.bubbleLinked();
        list.printLinked();
        cout << endl;
    }

    return 0;
}
