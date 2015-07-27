#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>

#include "mastermind.h"

using namespace std;
int main()
{
    bool MainLoop=1;
    int GameOver=0;

    UserInterface ui;

    while(MainLoop)
    {

        
        int input,codelength,maxturns;
        ui.WelcomeScreen();
        ui.DifficultyLevel(codelength,maxturns);

        GameField game(maxturns,codelength);                  //Take Values from user
        game.setCodeRandom();
        vector<int> inputRow(game.getCodeLength());

		system("cls");
        while(!GameOver)
        {
        	
			ui.AskCode(inputRow,game.getCodeLength());
			system("cls");
            game.setRow(inputRow);

			game.printGame();
            GameOver=game.checkGame();

            if(GameOver==1||GameOver==-1)
            {
                ui.gameOver(game,GameOver);
                break;
            }
            
            cout<<endl<<endl<<"Press Enter to continue"<<endl<<endl;
			getch();
			
			
        }
        MainLoop=ui.PlayAgain(GameOver);
    }
}
