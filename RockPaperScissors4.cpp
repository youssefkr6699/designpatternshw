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
class ScoreAdapter {
private:
  
    int matrix[3][3] = {
        {0, 1, 2},
        {2, 0, 1},
        {1, 2, 0}
    };

public:
    
    int evaluateMatch(Move* p1, Move* p2) {
       
        int index1 = p1->getId() - 1;
        int index2 = p2->getId() - 1;
        
       
        return matrix[index2][index1]; 
    }
};
class Game {
public:
    string name;
    int isGameOver = 0;
    int countP = 0;
    int countC = 0;
    ScoreAdapter adapter;

    void run() {
       
        srand(time(0)); 

        while (isGameOver != 3) {
            int choiceNum;
            cout << "\nChoose your move 1.rock 2.paper 3.scissors: ";
            cin >> choiceNum;

            Move* playerMove = MoveFactory::createMove(choiceNum);
            if (playerMove != nullptr) {
                cout << "Your move is: " << playerMove->getName() << endl;
            } else {
                cout << "Invalid choice, trying again." << endl;
                continue;
            }

            int choiceC = (rand() % 3) + 1; 
            Move* computerMove = MoveFactory::createMove(choiceC);
            if (computerMove != nullptr) {
                cout << "Computer's move: " << computerMove->getName() << endl;
            }

            int result = adapter.evaluateMatch(playerMove, computerMove);

            if (result == 0) {
                cout << "Round Result: Draw" << endl;
            } 
            else if (result == 1) {
                cout << "Round Result: Person won" << endl;
                countP++;
            } 
            else if (result == 2) {
                cout << "Round Result: Computer won" << endl;
                countC++;
            }

           
            delete playerMove;
            delete computerMove;

            isGameOver++;
        }

        
        cout << "\n--- Final Match Results ---" << endl;
        if (countP > countC) {
            cout << "You won the entire game! (" << countP << "-" << countC << ")" << endl;
        } else if (countP < countC) {
            cout << "Computer won the entire game! (" << countC << "-" << countP << ")" << endl;
        } else {
            cout << "The entire game ended in a draw! (" << countP << "-" << countC << ")" << endl;
        }
    }
};

class GameFacade {
private:
    Game gameEngine;
public:
    void playMatch() {
        cout << "=========================================" << endl;
        cout << "  Welcome to Rock, Paper, Scissors Pro!  " << endl;
        cout << "=========================================" << endl;
        
        
        gameEngine.run(); 
        
        cout << "=========================================" << endl;
        cout << "        Thank you for playing!          " << endl;
        cout << "=========================================" << endl;
    }
};


int main() {
    GameFacade game;
    game.playMatch(); 
    return 0;
}
