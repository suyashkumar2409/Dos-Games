#include<iostream>
#include"list.h"
pointer::pointer()
{
	first=NULL;
	last=NULL;
	current=NULL;
	count=0;
}
void pointer::initialise()              //initialises pointer
{
	count=0;
	while(first!=NULL)
	{
		current=first;
		first=first->link;
		delete current;
	}
	first=NULL;
	last=NULL;
	current=NULL;
}
wall* pointer::returnwall(int index)       //acts like an array for wall
{
	current=first;
	for(int i=0;i<index;i++)
	current=current->link;
	return& current->info;
}
void pointer::newwall(wall a)             //links new wall to linked list
{
	list *temp;
	temp=new list;
	temp->info=a;
	count++;
	if(first==NULL)
	{
		first=temp;
		last=temp;
		current=first;	
	}
	else
	{
		last->link=temp;
		last=last->link;
	}
	temp=NULL;
}
void pointer::deletewall()          //removes wall after job is done
{
	if(first!=NULL)
	{
		count--;
		current=first;
		first=first->link;
		delete current;
		current=NULL;
	}
}
int pointer::returncount()        //tells how many walls are currently there
{
	return count;
}
pointer::~pointer()
{
	list*temp;
	while(first!=last)
	{
		temp=first;
		first=first->link;
		delete temp;
	}
	temp=NULL;
	delete first;
	first=NULL;
	last=NULL;
	current=NULL;
}
