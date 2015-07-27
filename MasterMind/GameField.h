#ifndef GameField_H
#define GameField_H


#include<iostream>
#include<vector>
#include<string>
using namespace std;

class GameField
{
	private:
		int maxturns;

		int currentTurn;

		int codeLength;

		GameRow Code;
		vector<GameRow> currentGame;

		void printdesign(string des,int length)
		{
			cout<<" ";
			for(int i=0;i<length;i++)
				cout<<des;
			cout<<endl;
		}
		void printside(int length)
		{
			cout<<"|";
			for(int i=0;i<length/8;i++)
				cout<<"\t";
			cout<<"|"<<endl;
		}

	public:
		//Turn functions
		int setMaxTurns(int val=12);
		int getMaxTurns();

		void incrementTurn();
		int getCurrentTurn();
		int getTurnsLeft();

		//CodeLength functions
		int getCodeLength();
		int setCodeLength(int val=-1,int def=5); //-1 is a token to interpret that user didnt pass a length value
		//CodeRow Functions
		void setCode(vector<int>& val);
		void setCodeRandom();
		void printCode();
		// CurrentRowFunctions

		void setRow(vector<int> & val);
		const vector<int>& getRW(int pos=-1);
		void printRW(int i=0);

		// printGame function
		void printGame();

		// Initialiser functions

		GameField(int maxturns=12,int codeLength=5);

        // Check game function
        int checkGame();
};
/************************ Turn Functions  ***************************/
int GameField::setMaxTurns(int val)
{
    this->maxturns=val;
}

int GameField::getMaxTurns()
{
    return this->maxturns;
}

void GameField::incrementTurn()
{
    (this->currentTurn)++;
}

int GameField::getCurrentTurn()
{
    return this->currentTurn;
}

int GameField::getTurnsLeft()
{
    return this->maxturns-this->currentTurn;
}

int GameField::getCodeLength()
{
    return this->codeLength;
}

int GameField::setCodeLength(int val,int def)
{
    if(val!=-1)
        this->codeLength=val;
    else
        this->codeLength=5;

    Code.setLength(this->codeLength);
}

void GameField::setCode(vector<int> & val)
{
    Code.setArray(val);
}

void GameField::setCodeRandom()
{
    Code=GameRow(this->codeLength);
    Code.setArrayRandom();
}

void GameField::printCode()
{
    for(int i=0;i<Code.getLength();i++)
    {
        cout<<Code.getValue(i)<<" ";
    }
}

void GameField::setRow(vector<int> & val)
{
    GameRow* temp ;
    temp=new GameRow(this->getCodeLength());
    (*temp).setArray(val);

    currentGame.push_back(*temp);

    currentTurn++;
}

const vector<int>& GameField::getRW(int pos)
{
	if(pos==-1)
		pos=currentGame.size()-1;

    if(pos<currentGame.size())
    {
        vector<int>* temp;
        temp = new vector<int>(2);


        for(int i=0;i<Code.getLength();i++)
        {
            for(int j=0;j<currentGame[pos].getLength();j++)
            {
                if(Code.getValue(i)==currentGame[pos].getValue(j))
                {
                    if(i==j)
                        (*temp)[0]++;
                    else
                        (*temp)[1]++;
                    break;
                }
            }
        }

        return *temp;
    }
    else
    {
        cout<<"Currentgame array out of bounds";
    }
}

void GameField::printRW(int pos)
{
    vector<int> temp=getRW(pos);

    for(int i=0;i<2;i++)
        for(int j=0;j<temp[i];j++)
    {
        if(i==0)
            cout<<"R";
        else
            cout<<"W";
    }
}

void GameField::printGame()
{
    string rw="Result(R,W)";
    string yourmove="Your Move";

	int toplength=32;

	if(Code.getLength()>4)
		toplength+=2*(Code.getLength()-4);

	printdesign("-",toplength);

    cout<<"|"<<rw<<"\t\t"<<yourmove;

    if(Code.getLength()>4)
    	for(int i=0;i<2*(Code.getLength()-4);i++)
    		cout<<" ";

    cout<<"|"<<endl;

	printdesign("-",toplength);
    for(int i=0;i<currentGame.size();i++)
    {
		cout<<"|";
        printRW(i);
        cout<<"\t\t\t ";
        currentGame[i].printRow();
        cout<<"|"<<endl;
        if(i==currentGame.size()-1)
        	printdesign("-",toplength);
    }
    
    cout<<endl<<endl;
    cout<<"You have "<<this->getTurnsLeft()<<" turns left!"<<endl;
    
}

GameField::GameField(int maxturns, int codelength)
{
    this->maxturns=maxturns;
    this->codeLength=codelength;
    this->currentTurn=0;
}

int GameField::checkGame()
{
    if(getRW(currentGame.size()-1)[0]==Code.getLength())
        return 1;
    else if (getTurnsLeft()<=0)
    	return -1;
    else
    	return 0;
}

#endif // GameField_H
