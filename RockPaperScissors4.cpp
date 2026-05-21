#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


class Game{
    public:
        string name;
        int isGameOver = 0;
        int countP = 0;
        int countC = 0;

        void run(){
            while(isGameOver != 3){
                int choiceP;
                int choiceNum;
                cout << "\n\n";
                cout << "chose your move 1.rock 2.paper 3.scissors: ";
                cin >> choiceNum;
                if(choiceNum == 1){
                    choiceP = 0;
                    cout << "Your move is: rock" << endl;
                }
                else if(choiceNum == 2){
                    choiceP = 1;
                    cout << "Your move is: paper" << endl;
                }
                else{
                    choiceP = 2;
                    cout << "Your move is: scissors" << endl;
                }

                int choiceC = rand() % 3;
                switch (choiceC){
                    case 0:
                        cout << "Computer's move: rock" << endl;
                        break;
                    case 1:
                        cout << "Computer's move: paper" << endl;
                        break;
                    case 2:
                        cout << "Computer's move: scissors" << endl;
                        break;

                }



                if((choiceC == 0 && choiceP == 0) || (choiceC == 1 && choiceP == 1) || (choiceC == 2 && choiceP == 2)){
                    cout << "Draw" << endl;
                }
                else if((choiceC == 0 && choiceP == 1) || (choiceC == 1 && choiceP == 2) || (choiceC == 2 && choiceP == 0)){
                    cout << "Person won" << endl;
                    countP++;
                }
                else{
                    cout << "Computer won" << endl;
                    countC++;
                }

                isGameOver++;

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
