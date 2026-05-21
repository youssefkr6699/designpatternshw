#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


class Move {
public:
    virtual string getName() = 0; 
    virtual int getId() = 0;    
    virtual ~Move() {} 
};


class Rock : public Move {
public:
    string getName() override { return "rock"; }
    int getId() override { return 1; } 
};

class Paper : public Move {
public:
    string getName() override { return "paper"; }
    int getId() override { return 2; }
};


class Scissors : public Move {
public:
    string getName() override { return "scissors"; }
    int getId() override { return 3; } 
};

class MoveFactory {
public:
   
    static Move* createMove(int choice) {
        switch (choice) {
            case 1: return new Rock();
            case 2: return new Paper();
            case 3: return new Scissors();
            default: return nullptr;
        }
    }
};

class Game{
    public:
        string name;
        int isGameOver = 0;
        int countP = 0;
        int countC = 0;

        void run(){
            while(isGameOver != 3){
               
                
                int choiceNum;
                cout << "choose your move 1.rock 2.paper 3.scissors: ";
                cin >> choiceNum;


                Move* playerMove = MoveFactory::createMove(choiceNum);
                if (playerMove != nullptr) {
                    cout << "Your move is: " << playerMove->getName() << endl;
                }

                int choiceC = (rand() % 3) + 1; 
                Move* computerMove = MoveFactory::createMove(choiceC);
                if (computerMove != nullptr) {
                    cout << "Computer's move: " << computerMove->getName() << endl;
                }

               
                delete playerMove;
                delete computerMove;

            }
            cout << "\n\n";
            if(countP > countC){
                cout << "You won in this game" << endl;
            }
            else if(countP < countC){
                cout << "Computer won in this game" << endl;
            }
            else{
                cout << "Draw in this game";
            }
        }








};




int main(){

   int p1;
   int p2;
   int arr[3][3] = {
   {0,1,2},
   {2,0,1},
   {1,2,0}};

   cout<<"plyaer one 1 r 2 p 3 s"<<endl;
   cin>>p1;
   cout<<"plyaer two 1.r 2.p 2.s"<<endl;
    cin>>p2;
   int result = arr[p2-1][p1-1];
    cout<<result;
   switch(result)
   {
   case 1:
    cout<<"player 1 won";
    break;
   case 2:
     cout<<"player 2 won";
     break;
     case 0:
     cout<<"draw";
   }


    return 0;
}

