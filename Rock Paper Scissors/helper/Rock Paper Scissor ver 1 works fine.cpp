//make a function that converts random number to character rock paper scissor
#include<iostream>
#include<ctime>
#include<conio.h>
#include<cstdlib>
#include<string>
using namespace std;
const int initial=10;      //probability constant for initialisation
string mystring(string oppex)
{
	if(oppex=="rock")
	return "paper";
	if(oppex=="paper")
	return "scissors";
	if(oppex=="scissors")
	return "rock";
} 
int win(string my,char opp)   //function telling result of throw
{
	if(my=="rock")
	{
		if(opp=='r')
		return 2;
		if(opp=='s')
		return 1;
		if(opp=='p')
		return 0;
	}
	if(my=="paper")
	{
		if(opp=='r')
		return 1;
		if(opp=='s')
		return 0;
		if(opp=='p')
		return 2;
	}
	if(my=="scissors")
	{
		if(opp=='r')
		return 0;
		if(opp=='s')
		return 2;
		if(opp=='p')
		return 1;
	}
}
void probabilitywon(char oppactual,int& rock,int& paper,int& scissors)
{
	if(oppactual=='r')
	paper+=20;
	else if(oppactual=='p')
	scissors+=20;
	else if(oppactual=='s')
	rock+=20;
}
void probabilitylost(char oppactual,int& rock,int& paper,int& scissors)
{
	if(oppactual=='r')
	rock+=20;
	else if(oppactual=='p')
	paper+=20;
	else if(oppactual=='s')
	scissors+=20;
}
void probabilitythrow(char oppactual,int& rock,int& paper,int& scissors,int& oppthrowrock,int& oppthrowpaper,int& oppthrowscissors)
{
	if(oppactual=='r')
	{
		oppthrowrock++;
		rock+=10*(oppthrowrock/5);
	}
	else if(oppactual=='p')
	{
		oppthrowpaper++;
		paper+=10*(oppthrowpaper/5);
	} 
	else if(oppactual=='s')
	{
		oppthrowscissors++;
		scissors+=10*(oppthrowscissors/5);
	}
}
using namespace std;
int main()
{
	srand(time(0));
	char experience,oppactual;
	string oppex,mys;//mystring  //opponent expected
	int lose=0,oppn,oppthrowrock=0,oppthrowpaper=0,oppthrowscissors=0;
	int rock=33,paper=33,scissors=33,total;
	cout<<"Are you experienced?(y/n)";
	cin>>experience;
	if(experience=='y')          //iitial probability change according to experience
	{
		scissors+=initial;
		paper-=initial/2;
		scissors-=initial/2;
	}
	else if(experience=='n')
	{
		rock+=initial;
		paper-=initial/2;
		scissors-=initial/2;
	}
	do{
		
		total=rock+paper+scissors;
		oppn=rand()%total+1;
		if(oppn<=rock)
		oppex="rock";
		else if(oppn<=rock+paper)
		oppex="paper";
		else if(oppn<=rock+paper+scissors)
		oppex="scissors";
		mys=mystring(oppex);
		cout<<endl<<"You should throw "<<mys<<endl;
		cout<<"What did the opponent throw?(r/p/s)"<<endl;
		cin>>oppactual;
		probabilitythrow(oppactual,rock,paper,scissors,oppthrowrock,oppthrowpaper,oppthrowscissors);
		if(win(mys,oppactual)==1)
		{
			lose=0;
			probabilitywon(oppactual,rock,paper,scissors);
		}
		else if(win(mys,oppactual)==0)
		{
			lose++;
			probabilitylost(oppactual,rock,paper,scissors);
		}
		cout<<endl<<"rock is "<<rock<<endl<<"paper is "<<paper<<endl<<"scissors is "<<scissors;
		_getch();
		system("cls");
		
		
	}while(1);
		
	
	
}
