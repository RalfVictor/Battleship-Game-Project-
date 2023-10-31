#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<stdio.h>
#include<dos.h>
#include<MMsystem.h>

using namespace std;

class Battleship{
	private:
		int count,attempts,attemptno = 0;
	public:
	Battleship(int count,int attempts){
		this->count=count;
		this->attempts=attempts;
	}
	int getcount(){
		return count;
	}
	int gettotattempt(){
		return attempts;
	}
	void updateattempt(){
		attemptno++;
	}
	int getcurrentattempt(){
		return attemptno;
	}
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
	public:
		Level1():Battleship(7,9){
		}
		void display(){
		cout<<"Attempt - "<<getcurrentattempt()+1<<"         "<<"Total Attempts - "<<gettotattempt()<<endl;
		updateattempt();
		cout<<"  COL ";
		for(int i=0;i<4;i++){
			cout<<i+1<<" ";
		}
		cout<<endl<<"ROW"<<endl;
		for(int i=0;i<4;i++){
			cout<<"   "<<i+1<<"  ";
			for(int j=0;j<4;j++){
				cout<<Matrixgame[i][j]<<" ";
			}cout<<endl;
		}
	}
	char updatematrix(){
		int row,col;
		cout<<"Give Value of Row:";
		cin>>row;
		cout<<"Give Value of Column:";
		cin>>col;
		Matrixgame[row-1][col-1]=Matrix[row-1][col-1];
		if(Matrixgame[row-1][col-1]=='1'){
			cout<<"You Scored a Hit!!"<<endl;
		}
		else{
			cout<<"You Missed!!"<<endl;
		}
		Sleep(2000);
		system("cls");
		return Matrixgame[row-1][col-1]; 
	}
};

class Level2:public Battleship{
	private:
		int Matrix[5][5] = {{'0','1','1','0','1'},
							{'1','0','0','0','1'},
							{'1','0','0','0','0'},
							{'1','0','1','1','0'},
							{'0','1','1','0','0'}};
		char Matrixgame[5][5]={{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '}};
	public:
		Level2():Battleship(11,15){
		}
		void display(){
		cout<<"Attempt - "<<getcurrentattempt()+1<<"         "<<"Total Attempts - "<<gettotattempt()<<endl;
		updateattempt();
		cout<<"  COL ";
		for(int i=0;i<5;i++){
			cout<<i+1<<" ";
		}
		cout<<endl<<"ROW"<<endl;
		for(int i=0;i<5;i++){
			cout<<"   "<<i+1<<"  ";
			for(int j=0;j<5;j++){
				cout<<Matrixgame[i][j]<<" ";
			}cout<<endl;
		}
	}
	char updatematrix(){
		int row,col;
		cout<<"Give Value of Row:";
		cin>>row;
		cout<<"Give Value of Column:";
		cin>>col;
		Matrixgame[row-1][col-1]=Matrix[row-1][col-1];
		if(Matrixgame[row-1][col-1]=='1'){
			cout<<"You Scored a Hit!!"<<endl;
		}
		else{
			cout<<"You Missed!!"<<endl;
		}
		Sleep(2000);
		system("cls");
		return Matrixgame[row-1][col-1]; 
	}
};

class Level3:public Battleship{
	private:
		char Matrix[6][6]=
						  {{'1','1','1','1','0','0'},
						   {'0','0','0','0','1','0'},
						   {'1','0','0','1','0','1'},
						   {'1','0','1','0','0','1'},
						   {'1','0','0','0','0','1'},
						   {'0','1','1','1','0','1'}};
		char Matrixgame[6][6]=
						  {{' ',' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' ',' '}};
	public:
		Level3():Battleship(17,30){
		}	
		void display(){
		cout<<"Attempt - "<<getcurrentattempt()+1<<"         "<<"Total Attempts - "<<gettotattempt()<<endl;
		updateattempt();
		cout<<"  COL ";
		for(int i=0;i<6;i++){
			cout<<i+1<<" ";
		}
		cout<<endl<<"ROW"<<endl;
		for(int i=0;i<6;i++){
			cout<<"   "<<i+1<<"  ";
			for(int j=0;j<6;j++){
				cout<<Matrixgame[i][j]<<" ";
			}cout<<endl;
		}
	
	}
	char updatematrix(){
		int row,col;
		cout<<"Give Value of Row:";
		cin>>row;
		cout<<"Give Value of Column:";
		cin>>col;
		Matrixgame[row-1][col-1]=Matrix[row-1][col-1];
		if(Matrixgame[row-1][col-1]=='1'){
			cout<<"You Scored a Hit!!"<<endl;
		}
		else{
			cout<<"You Missed!!"<<endl;
		}
		Sleep(2000);
		system("cls");
		return Matrixgame[row-1][col-1]; 
	}	
};

int main(){
	Start:
	int LevelNo;
	cout<<"Level 1 (4x4)"<<endl<<"Level 2 (5x5)"<<endl<<"Level 3 (6x6)"<<endl<<"Give Level No:"<<endl;
	cin>>LevelNo;
	system("cls");
	switch(LevelNo){
		case 1: {
			Level1 lev1;
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
				cout<<lev1.getcurrentattempt()<<endl<<lev1.getcount();
				cout<<lev1.gettotattempt();
				cout<<"Try Again."<<endl;
			}int command;
			commandprompt1:
			cout<<"If You Want to Continue(1)  OR  To Exit(0)"<<endl;
			cin>>command;
			if(command==1){
				system("cls");
				goto Start;}
				else if(command!=0){
				cout<<"Invalid Command. Try Again"<<endl;
				goto commandprompt1;
			}
			break;}
		case 2:{Level2 lev2;
			int coun = 0;
			int Oricoun = lev2.getcount();
			Level2con:
			lev2.display();
			
			if(lev2.getcurrentattempt()<lev2.gettotattempt()){
			if(coun<Oricoun){
				char Obtained = lev2.updatematrix();
				if(Obtained=='1'){
					coun++;
				}
				goto Level2con;
			}
			else{
				cout<<"You Win"<<endl;
			}
			}
			else{
				cout<<lev2.getcurrentattempt()<<endl<<lev2.getcount();
				cout<<lev2.gettotattempt();
				cout<<"Try Again."<<endl;
			}int command;
			commandprompt2:
			cout<<"If You Want to Continue(1)  OR  To Exit(0)"<<endl;
			cin>>command;
			if(command==1){
				goto Start;
			}else if(command!=0){
				cout<<"Invalid Command. Try Again"<<endl;
				goto commandprompt2;
			}
			break;}
		case 3:{
			Level3 lev3;
			int coun = 0;
			int Oricoun = lev3.getcount();
			Level3con:
			lev3.display();
			
			if(lev3.getcurrentattempt()<lev3.gettotattempt()){
			if(coun<Oricoun){
				char Obtained = lev3.updatematrix();
				if(Obtained=='1'){
					coun++;
				}
				goto Level3con;
			}
			else{
				cout<<"You Win"<<endl;
			}
			}
			else{
				cout<<lev3.getcurrentattempt()<<endl<<lev3.getcount();
				cout<<lev3.gettotattempt();
				cout<<"Try Again."<<endl;
			}int command;
			commandprompt3:
			cout<<"If You Want to Continue(1)  OR  To Exit(0)"<<endl;
			cin>>command;
			if(command==1){
				goto Start;
			}else if(command!=0){
				cout<<"Invalid Command. Try Again"<<endl;
				goto commandprompt3;
			}
			break;
		}	
}
	return 0;
}
