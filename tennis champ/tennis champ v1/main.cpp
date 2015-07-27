#include<iostream>
#include<string>
#include<conio.h>
#include<cstdlib>
using namespace std;
class player{
	public:
		void getthrows();                    //inputs points and verifies whether it can be inputted
		void pointsupdate();                //updates points
		void initialise();
		string name;
			int points;
	int throws;
};
const int spaces=3;
void ball(int ballpos)
{
	for(int i=1;i<=ballpos;i++)
	cout<<" ";
	cout<<"  *  "<<endl;
		for(int i=1;i<=ballpos;i++)
	cout<<" ";
	cout<<" *** "<<endl;
		for(int i=1;i<=ballpos;i++)
	cout<<" ";
	cout<<"*****"<<endl;
		for(int i=1;i<=ballpos;i++)
	cout<<" ";
	cout<<"*****"<<endl;
		for(int i=1;i<=ballpos;i++)
	cout<<" ";
	cout<<" *** "<<endl;
		for(int i=1;i<=ballpos;i++)
	cout<<" ";
	cout<<"  *  "<<endl;
}
void currentgame(int ballpos)
{
	cout<<"\t\t\t\t\t\tNet"<<endl;
	for(int i=0;i<spaces;i++)                 //sets upper part of field                         //
	{
		cout<<"\t\t|\t\t|\t\t|\t\t|\t\t|"<<endl;
	}
	ball(ballpos);
	for(int i=0;i<spaces;i++)                 //sets lower part of field                         //
	{
		cout<<"\t\t|\t\t|\t\t|\t\t|\t\t|"<<endl;
	}
}
player pone,ptwo;
int main()
{
	pone.initialise();
	ptwo.initialise();
	int atnet=1;
	int ballpos=48-2;            //initiates number of spaces required for initial position of ball,ALWAYS SUBTRACT 2
	cout<<"Enter name of player 1\n";
	cin>>pone.name;
	cout<<"Enter name of player 2\n";
	cin>>ptwo.name;
	while((pone.points>0||ptwo.points>0)&&(ballpos>14&&ballpos<78))
	{
		system("cls");
		cout<<pone.name<<"\t\t\t\t\t\t\t\t\t\t"<<ptwo.name<<endl;
		currentgame(ballpos);
		cout<<endl<<pone.name<<" has "<<pone.points<<" points"<<endl;
		cout<<endl<<ptwo.name<<" has "<<ptwo.points<<" points"<<endl;
		cout<<pone.name<<" enter your throw"<<endl;
		pone.getthrows();
		system("cls");
		cout<<pone.name<<"\t\t\t\t\t\t\t\t\t\t"<<ptwo.name<<endl;
		currentgame(ballpos);
		cout<<endl<<pone.name<<" has "<<pone.points<<" points"<<endl;
		cout<<endl<<ptwo.name<<" has "<<ptwo.points<<" points"<<endl;
		cout<<ptwo.name<<" enter your throw"<<endl;
		ptwo.getthrows();
		system("cls");
		cout<<pone.name<<"\t\t\t\t\t\t\t\t\t\t"<<ptwo.name<<endl;
		currentgame(ballpos);
		pone.pointsupdate();
		ptwo.pointsupdate();
		system("cls");
		if(pone.throws>ptwo.throws)
			{	if(atnet)
				{
					
					atnet=0;
					ballpos-=8;
				}
				cout<<endl<<pone.name<<" won this round"<<endl;
				ballpos+=16;
			}
		else if(ptwo.throws>pone.throws)
			{	if(atnet)
				{
					
					atnet=0;
					ballpos+=8;
				}
				cout<<endl<<ptwo.name<<" won this round"<<endl;
				ballpos-=16;
			} 
		else
		cout<<"You both entered the same number of points, the ball didnt move";
		cout<<pone.name<<"\t\t\t\t\t\t\t\t\t\t"<<ptwo.name<<endl;
		currentgame(ballpos);        //print field
		if(pone.points==0&&ptwo.points==0)
		{
			if(ballpos==46)
			{
				cout<<"Its a tie!!";
				goto end;
			}
		}
		if(ballpos<14)
		{
			cout<<ptwo.name<<" won!!!!!";
		}
		else if(ballpos>78)
		{
			cout<<pone.name<<" won!!!!!";
		}
		if(pone.points<=0&&ptwo.points<=0)
		{
			if(ballpos>14&&ballpos<46)
			cout<<ptwo.name<<" won!!!!!";
			else if(ballpos>46&&ballpos<78)
			cout<<pone.name<<" won!!!!!";
		}
		cout<<endl<<"Press Enter";
		_getch();
	}
	end:
		;
}
void player::getthrows()
{
	do{
		cin>>throws;
		if(throws>points)
		cout<<"Fucking move, you don't have that many points, try again\n";
	}
	while(throws>points);
}
void player::pointsupdate()
{
	points-=throws;
}
void player::initialise()
{
	points=50;
}

