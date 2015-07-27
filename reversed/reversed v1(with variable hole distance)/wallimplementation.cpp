#include<iostream>
#include"wall.h"
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
void wall::initialise(bool firsttime,int before,int difficulty)         //sets a random place where hole will occur
{
	srand(time(0));
	if(firsttime)
	x=rand()%28;
	else
	{
		again:
		x=before+rand()%(11+difficulty)-(5+difficulty/2);
		if(x>25||x<7)
		goto again;
		/*
		if(x>=19)
		x=before-abs(rand()%11-6);
		else if(x<=6)
		x=before+abs(rand()%11-6);
		else
		x=before+rand()%11-6;	*/
	}	
	y=0;
}
void wall::printwithupdate()        //if its the topmost wall, use this
{
	for(int i=0;i<y;i++)
	cout<<"\n";
	y++;
	for(int i=0;i<x;i++)
		cout<<"-";
	cout<<"      ";
	for(int i=0;i<25-x;i++)
		cout<<"-";
}
void wall::print()                 //if it is not the topmost wall, use this
{
	for(int i=0;i<y;i++)
		cout<<"\n";
	for(int i=0;i<x;i++)
		cout<<"-";
	cout<<"      ";
	for(int i=0;i<25-x;i++)
		cout<<"-";	
}
int wall::returnx()           //returns x coordinate of hole for moving through it
{
	return x;
}
int wall::returny()
{
	return y;
}
