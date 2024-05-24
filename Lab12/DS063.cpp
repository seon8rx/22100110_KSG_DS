#include <iostream>
#include "MyLLQueue.h"
using namespace std;

int main(){

    Node player1;
    Node player2;

    int numOfCard;
    cin >> numOfCard;

    int input;

    for(int i=0; i<numOfCard; i++){
        cin >> input;
        player1.enqueue(input);
    }

    for(int i=0; i<numOfCard; i++){
        cin >> input;
        player2.enqueue(input);
    }

    int player1point=0;
    int player2point=0;
    int player1card;
    int player2card;
    int player1prev;
    int player2prev;
    int gameresult=0;
    int gamecount=1;
    while(gamecount<=numOfCard){
        player1card = player1.getFront();
        player2card = player2.getFront();
        if(gameresult==0){

            if(player1card>player2card) {
                gameresult=1;
                player1point++;
                cout << "Round" << gamecount << " - P1 win!" << endl;
            }
            else if(player1card<player2card) {
                gameresult=2;
                player2point++;
                cout << "Round" << gamecount << " - P2 win!" << endl;
            }
            else {
                gameresult=0;
                cout << "Round" << gamecount << " - Draw!" << endl;
            }

        }else if(gameresult==1){
            player1card = player1card + player1prev - player2prev - 1;

            if(player1card>player2card) {
                gameresult=1;
                player1point++;
                cout << "Round" << gamecount << " - P1 win!" << endl;
            }
            else if(player1card<player2card) {
                gameresult=2;
                player2point++;
                cout << "Round" << gamecount << " - P2 win!" << endl;
            }
            else {
                gameresult=0;
                cout << "Round" << gamecount << " - Draw!" << endl;
            }

        }else if(gameresult==2){
            player2card = player2card + player2prev - player1prev - 1;

            if(player1card>player2card) {
                gameresult=1;
                player1point++;
                cout << "Round" << gamecount << " - P1 win!" << endl;
            }
            else if(player1card<player2card) {
                gameresult=2;
                player2point++;
                cout << "Round" << gamecount << " - P2 win!" << endl;
            }
            else {
                gameresult=0;
                cout << "Round" << gamecount << " - Draw!" << endl;
            }

        }

        player1prev = player1card;
        player2prev = player2card;
        player1.dequeue();
        player2.dequeue();
        gamecount++;
    }

    if(player1point>player2point) cout << "Final - P1 win!";
    else if(player1point<player2point) cout << "Final - P2 win!";
    else cout << "Final - Draw!";

    return 0;
}