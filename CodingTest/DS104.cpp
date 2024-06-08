#include <iostream>
using namespace std;

struct Node {
    int data;
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
        int temp = x->data;
        x->data = y->data;
        y->data = temp;
    }

    Node* createNode(int input) {
        Node* newNode = new Node();
        newNode->data = input;
        newNode->next = nullptr;
        return newNode;
    }

    void addLast(int input) {
        Node* newNode = createNode(input);
        if (start == nullptr) {
            start = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    void printLinked() const {
        Node* temp = start;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void clearLinked() {
        Node* temp;
        while (start != nullptr) {
            temp = start;
            start = start->next;
            delete temp;
        }
        start = nullptr;
        last = nullptr;
    }

    void init(int size) {
        int number;
        clearLinked();
        cout << "Enter numbers... ";
        for (int i = 0; i < size; i++) {
            cin >> number;
            addLast(number);
        }
    }

    static bool more(int a, int b) {return a > b;}
    static bool less(int a, int b) {return a < b;}

    void selectionLinked(int type) {
        Node* key = start;
        Node* temp;

        bool (*comp)(int, int);
        if(type%2 != 0) comp = LinkedList::more;
        else comp = LinkedList::less;

        while (key != nullptr) {
            temp = key->next;
            while (temp != nullptr) {
                if (comp(key->data, temp->data)) swapNode(key, temp);
                temp = temp->next;
            }
            key = key->next;
        }
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
        cout << ("Ascending : 1, Descending : 2 (Odd number for Ascending, Even number for Descending) > ");
        cin >> type;

        list.init(choice);
        list.selectionLinked(type);
        list.printLinked();
        cout << endl;
    }

    return 0;
}
