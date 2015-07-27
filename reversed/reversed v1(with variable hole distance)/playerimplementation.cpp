#include<iostream>
#include"player.h"
using namespace std;
player::player()
{
	x=15;
}
void player::print(int a)
{
	for(int i=0;i<50-a;i++)
	cout<<endl;
	for(int i=0;i<x;i++)
	cout<<" ";
	cout<<"**";
	for(int i=0;i<29-x;i++)
	cout<<" ";
}
int player::returnx()
{
	return x;
}
void player::movement(char a,bool reversed)
{
	switch(a)
	{
		case 'a':
			{
				if(x>0&&reversed==0)
				x--;
				if(x<30&&reversed==1)
				x++;
				break;
			}
		case 'd':
			{
				if(x<30&&reversed==0)
				x++;
				if(x>0&&reversed==1)
				x--;
				break;
			}
	}
}
