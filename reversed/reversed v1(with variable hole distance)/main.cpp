#include<iostream>
#include"list.h"
#include"player.h"
#include<ctime>
#include<cstdlib>
#include<conio.h>
#include<unistd.h>
#include<windows.h>
using namespace std;
void printmap(pointer& wallsofgame,int& spacebywalls)
{
	spacebywalls=1;
	for(int i=wallsofgame.returncount()-1;i>=0;i--)
	{
		if((i==(wallsofgame.returncount()-1)))
		(*(wallsofgame.returnwall(i))).printwithupdate(); //if it is the top wall,print with increasing y
		else
		(*(wallsofgame.returnwall(i))).print();
		spacebywalls+=(*(wallsofgame.returnwall(i))).returny();
	}
}
void newwall(pointer& wallsofgame,bool firsttime,int& before,int difficulty)
{
	wall a;
	a.initialise(firsttime,before,difficulty);
	if(firsttime)
	before=a.returnx();
	wallsofgame.newwall(a);
}

int main()
{
	int difficulty;
	cout<<"1.Easy\n2.Medium\n3.Difficult\nEnter your difficulty level";
	cin>>difficulty;
	switch(difficulty)
	{
		case 1: 
			{
				difficulty=0;
				break;
			}
			case 2: 
			{
				difficulty=8;
				break;
			}
		case 3: 
			{
				difficulty=12;
				break;
			}
		
	}
	for(int i=0;i<24;i++)
	cout<<"\n";
	for(int i=0;i<4;i++)
	cout<<" ";
	cout<<"Press Enter when ready";
	getch();
	system("cls");
	bool firsttime=1;
	int before=0;
	int spacebywalls=0;
	bool reversed=0;
	srand(time(0));
	player object;     //the player of the game is object
	int vartodeletewall=1;      //variable required to delete wall after it has exited screen
	int wallrand;      //randomvariable for generation of walls
	int score=0;
	char move;
	pointer wallsofgame;
	wallsofgame.initialise(); //the linked list is now up and running
	newwall(wallsofgame,firsttime,before,difficulty);     //the first wall was added
	firsttime=0;
	wallrand=rand()%4+5;
	int reverserand;
	reverserand=rand()%6+20;
	int i=0,j=0;
	while(1)
	{
		//while(!_kbhit())
			for(;!_kbhit();i++,vartodeletewall++,j++)
			{
				
				if(i%9==wallrand)     //if the time has come for a new wall to be made
				{
					newwall(wallsofgame,firsttime,before,difficulty);
					i=0;
					wallrand=rand()%4+5;
				}
                printmap(wallsofgame,spacebywalls);
				object.print(spacebywalls);
				if(j==reverserand)
				{
					cout<<"\a";
					reversed=!reversed;
					reverserand=rand()%6+20;
					j=0;
				}
				if(vartodeletewall==49)      //checking whether the object crosses the wall
				{
					int temp=(object.returnx()-(*(wallsofgame.returnwall(0))).returnx());
					if(!(temp>=0&&temp<=4))
					{
						system("cls");
						cout<<"GAME OVER!!!!"<<endl;
						cout<<"Your score is "<<score;
						goto end;
					}
					else
					score++;
				}
				if(vartodeletewall==49)     //deletes the wall when it reaches the end of screen
				{
					vartodeletewall=vartodeletewall-((*(wallsofgame.returnwall(0))).returny());  //this reduces space between walls
					wallsofgame.deletewall();      //-1 is needed, can be checked through imagination
					
					
				}
				//getch();
				if(!reversed)
				cout<<endl<<"Correct";
				else
				cout<<endl<<"Reversed";
				Sleep(250);
				system("cls");
			}
		//}
		if(_kbhit())
		{
			move=getch();
			object.movement(move,reversed);
		}
	}

end:
	Sleep(2000);
	getch();

}
//
