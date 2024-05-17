#include <iostream>

using namespace std;

struct CircularQueue {
    string *items;
    int front, back;
    int maxlen;
    string dash;
    int shown;

    CircularQueue(int capa=4) {
		items = new string[capa]; 
        front = -1;
        back = -1;
        maxlen = capa;
        }
	~CircularQueue() {
    delete[] items;
  }
};