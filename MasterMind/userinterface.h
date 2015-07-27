#ifndef userinterface_H
#define userinterface_H


#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<fstream>
#include "GameField.h"

#define _space cout<<"\t\t\t";
using namespace std;

class UserInterface
{
	private:
		static void printDesign(string a,int number)
		{
			for(int i=0;i<number;i++)
				cout<<a;
		}

	public:
		void WelcomeScreen();                 //Prints the WelcomeScreen
		void DifficultyLevel(int & codelength, int & maxturns);
		void AskCode(vector<int> & inputRow, int length);
		void gameOver(GameField &,int type);
		bool PlayAgain(int & gameover);
		void Instructions();
		
};

void UserInterface::WelcomeScreen()
{

	int number=25;


	int choice=0;

	while(choice!=1)
	{
		system("cls");
		printDesign("#",number);
		cout<<"  WELCOME TO MASTERMIND  ";
		printDesign("#",number);

		int choice;

		cout<<endl<<endl;

		_space

		cout<<"Enter your choice:"<<endl;

		_space

		cout<<"1. New Game"<<endl;

		_space

		cout<<"2. Instructions"<<endl<<endl;

		cout<<"Enter (1/2)"<<endl;
		cin>>choice;

		if(choice==1)
			break;
		else if(choice==2)
		{
			Instructions();
		}
		else
		{
			system("cls");
			cout<<"You pressed something else. Press Enter to go back";
			getch();
		}
	}

}

void UserInterface::DifficultyLevel(int & codelength, int & maxturns)
{
	system("cls");
	
	cout<<"Enter the length of the hidden code for the game(3,4,5,6 or above)"<<endl;
	while(1)
	{
		cin>>codelength;
		if(codelength<3)
		{
			cout<<"The number of you have entered is too small. Try again"<<endl;
		}
		else if(codelength>6)
		{
			cout<<"The number you entered is too big. Try again"<<endl;
		}
		else
			break;
	}
	system("cls");
	cout<<"You have chosen the code to be of "<<codelength<<"digits long"<<endl;
	cout<<"Enter your difficulty level(Easy-12 turns, Medium-10 turns, Hard-6 turns)"<<endl<<endl;
	cout<<"Enter the number corresponding to your choice:"<<endl;
	int a;
	cout<<"1. Easy"<<endl;
	cout<<"2. Medium"<<endl;
	cout<<"3. Hard"<<endl;
	
	while(1)
	{
		cin>>a;
		if(a>=1&&a<=3)
		{
			if(a==1)
				maxturns=12;
			else if(a==2)
				maxturns=10;
			else if(a==3)
				maxturns=6;
			else 
				continue;
			cout<<"Good Choice!"<<endl;
			cout<<"Press Any Key to start your game"<<endl;
			getch();
			
			break;
			
		}
		else
		{
			cout<<"Thats an invalid choice. Press Any Key to try again"<<endl;
			getch();
		}
	}
	
}
void UserInterface::AskCode(vector<int> & inputRow, int length)
{

	int correctinput=0;
	bool escape=1;
	while(correctinput!=1)
	{
		cout<<"Please enter what you think is the stored code"<<endl;
		cout<<"You cannot repeat any number, exceed your set Code Length, or choose a digit other than 1-8"<<endl;
		cout<<endl;
		string input;

		cin>>input;

		vector<bool> num(10);
		for(int i=0;i<10;i++)
			num[i]=0;
		escape=1;
		for(int i=0;i<input.length()&&escape;i++)
		{
				if(input.length()==length)
				{
					int temp=input[i]-'0';
					if(temp>=1&&temp<=8)
					{
						if(num[temp]==0)
							num[temp]=1;
						else
						{
							cout<<endl<<endl<<"You cannot repeat a digit!!"<<endl<<"You repeated "<<temp<<endl;
							cout<<"Press Enter to try again"<<endl<<endl;
							getch();
							escape=0;
						}
					}
					else
					{
						cout<<endl<<endl<<"You can only choose digits from 1 to 8!!";
						cout<<endl<<"Press Enter to try again"<<endl<<endl;
						getch();
						escape=0;
					}
				}
				else
				{
					cout<<endl<<endl<<"Enter a code "<<length<<"digit";
					if(length>1)
						cout<<"s";
					cout<<" long!!"<<endl;
	
					cout<<"Press Enter to try again"<<endl<<endl;
					getch();
					escape=0;
				}
			
		}
		if(escape==1)
		{
			for(int i=0;i<length;i++)
				inputRow[i]=input[i]-'0';
	
			correctinput=1;
		}
	}

}

void UserInterface::gameOver(GameField & game, int type)
{
	system("cls");

	if(type==1)
	{
		printDesign("#",25);
		cout<<"  CONGRATULATIONS  ";
		printDesign("#",25);

		cout<<endl<<endl;

		cout<<"You correctly guessed the code:";
	}
	else
	{
		printDesign("*",25);
		cout<<"  YOU LOST  ";
		printDesign("*",32);

		cout<<endl<<endl;

		cout<<"The code was:";
	}
	game.printCode();

}

bool UserInterface::PlayAgain(int & gameover)
{
	cout<<endl<<endl;

	char choice;
	while(1)
	{
		cout<<"Would you like to Play Again? Press \"y\" to go to Main Menu, \"n\" to exit"<<endl<<endl;
		cin>>choice;
		if(choice=='y')
		{
			gameover=0;
			return 1;
		}
		else if(choice=='n')
			return 0;
		else
		{
			system("cls");
			cout<<"You entered wrong choice, try again"<<endl<<endl;
		}
	}
}

void UserInterface::Instructions()
{
	system("cls");
	//cout<<"hola";
	ifstream rules;
	rules.open("rules.txt");
	string input;
	while(rules)
	{
		getline(rules,input);
		cout<<input;	
		cout<<endl;
	}
	cout<<endl<<"Press Any Key to go back";
	getch();
}


#endif // userinterface_H
