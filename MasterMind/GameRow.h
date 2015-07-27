#ifndef GameRow_H
#define GameRow_H


#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<list>
using namespace std;

class GameRow
{
	protected:
		static const int maxlength=5;               //maxlength of row
		static const int maxvariety=8;				 //maxvalue of a piece
	private:
		int length;
		vector<int> array;
	public:
							//Initialisers
		GameRow(int length=maxlength);
							//length related functions
		int getLength();
		int setLength(int length);
							//Array related functions
		int getValue(int pos=0);
		const vector<int>& getArray();
		int setValue(int pos=0,int val=1);
		void setArray(vector<int> & val);
		void setArrayRandom();
		void printRow();
};

GameRow::GameRow(int length)
{
	if(length>=1&&length<=maxlength)
		this->length=length;
	else
		this->length=maxlength;
	this->array.resize(length);
}

int GameRow::getLength()
{
	return this->length;
}

int GameRow::setLength(int length=maxlength)
{
	if(length>=1&&length<=maxlength)
		this->length=length;
	else
		this->length=maxlength;
}

int GameRow::getValue(int pos)
{
	if(pos<length)
	return (this->array)[pos];
	else
	return -1;
}

const vector<int>& GameRow::getArray()
{
	return this->array;
}

int GameRow::setValue(int pos,int val)
{
	if(pos>=0&&pos<this->length&&val>=1&&val<maxvariety)
	{
		(this->array)[pos]=val;
	}
	return val;
}

void GameRow::setArray(vector<int> & val)
{
    if(array.size()>=val.size())
        if(val.size()<=maxlength)
        {
            for(int i=0;i<val.size();i++)
                this->array[i]=val[i];
        }

}

void GameRow::setArrayRandom()
{
	vector<int> randomList(maxvariety);
	for(int i=0;i<=maxvariety;i++)
		randomList[i]=i+1;

    srand(time(0));

    array.resize(this->getLength());

    for(int i=0;i<array.size();i++)
    {
		int temp=rand()%randomList.size();
        array[i]=randomList[temp];

        randomList.erase(randomList.begin()+temp,randomList.begin()+temp+1);
    }
}

void GameRow::printRow()
{
    for(int i=0;i<array.size();i++)
    {
        cout<<array[i]<<" ";
    }
}

#endif // GameRow_H
