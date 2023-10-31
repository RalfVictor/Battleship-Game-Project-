#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<stdio.h>

using namespace std;

void ClearScreen()
{	
  COORD cursorPosition;	    cursorPosition.X = 0;	cursorPosition.Y = 0;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

class Battleship{
	public:
	void display2();
};

class Level1:public Battleship{
	private:
		int Matrix[4][4] = {{'0','1','1','0'},
							{'1','0','0','0'},
							{'1','0','0','0'},
							{'1','0','1','1'}};
		char Matrixgame[4][4]={{' ',' ',' ',' '},
							{' ',' ',' ',' '},
							{' ',' ',' ',' '},
							{' ',' ',' ',' '}};
		int count = 7;
		int attempts = 9;
		int attemptno = 0;
	public:
		void display(){
		cout<<"Attempt "<<attemptno+1<<endl;
		cout<<"  ROW ";
		for(int i=0;i<4;i++){
			cout<<i+1<<" ";
		}
		cout<<endl<<"COL"<<endl;
		for(int i=0;i<4;i++){
			cout<<"   "<<i+1<<"  ";
			for(int j=0;j<4;j++){
				cout<<Matrixgame[i][j]<<" ";
			}cout<<endl;
		}attemptno++;
	}
	char updatematrix(){
		int row,col;
		cout<<"Give Value of Row:";
		cin>>row;
		cout<<"Give Value of Column:";
		cin>>col;
		Matrixgame[row-1][col-1]=Matrix[row-1][col-1];
		system("cls");
		return Matrixgame[row-1][col-1]; 
	}
	int getcount(){
		return count;
	}
	int gettotattempt(){
		return attempts;
	}
	int getcurrentattempt(){
		return attemptno;
	}
};

int main(){
	int LevelNo;
	cout<<"Level 1 (4x4)"<<endl<<"Level 2 (5x5)"<<endl<<"Level 3 (6x6)"<<endl<<"Give Level No:"<<endl;
	cin>>LevelNo;
	system("cls");
	switch(LevelNo){
		case 1: Level1 lev1;
			int coun = 0;
			int Oricoun = lev1.getcount();
			Level1con:
			lev1.display();
			if(lev1.getcurrentattempt()<lev1.gettotattempt()){
			if(coun<Oricoun){
				char Obtained = lev1.updatematrix();
				if(Obtained=='1'){
					coun++;
				}
				goto Level1con;
			}
			else{
				cout<<"You Win"<<endl;
			}
		}
		else{
			cout<<"Try Again."<<endl;
		}
	}
	return 0;
}
