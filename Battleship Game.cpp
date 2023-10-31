#include<iostream>
#include<cstdlib>
//#include<time.h>
#include<windows.h>

using namespace std;

//void ClearScreen()
//{	
//  COORD cursorPosition;	    cursorPosition.X = 0;	cursorPosition.Y = 0;
//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
//}

class Battleship{
	public:
	void display2();
};

class Level1:public Battleship{
	private:
		char Matrix[4][4] = {{'0','1','1','0'},
							{'1','0','0','0'},
							{'1','0','0','0'},
							{'1','0','1','1'}};
		char Matrixgame[4][4]=
						   {{' ',' ',' ',' '},
							{' ',' ',' ',' '},
							{' ',' ',' ',' '},
							{' ',' ',' ',' '}};
		int count = 7;
		int attempts = 9;
		int attemptno = 0;
	public:
		void display(){
		cout<<"Attempt "<<attemptno+1<<endl;
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
		}attemptno++;
	}
	char updatematrix(){
		int row,col;
		cout<<"Give Value of Column:";
		cin>>col;
		cout<<"Give Value of Row:";
		cin>>row;
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
class Level2: public Battleship{
	private:
		char Matrix[5][5]=
						  {{'1','1','1','0','0'},
						   {'0','0','0','1','0'},
						   {'1','0','1','0','0'},
						   {'1','1','0','0','0'},
						   {'1','0','1','1','1'}};
		char Matrixgame[5][5]=
						  {{' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' '}};
		int count = 12;
		int attempts = 20;
		int attemptno=0;
	public:
		void display(){
			cout<<"Attempt "<<attemptno+1<<endl;
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
		}attemptno++;
			
		}
	char updatematrix(){
		int row,col;
		cout<<"Give Value of Column:";
		cin>>col;
		cout<<"Give Value of Row:";
		cin>>row;
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

class Level3: public Battleship{
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
		int count = 17;
		int attempts = 30;
		int attemptno=0;
	public:
		void display(){
			cout<<"Attempt "<<attemptno+1<<endl;
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
		}attemptno++;
			
		}
	char updatematrix(){
		int row,col;
		cout<<"Give Value of Column:";
		cin>>col;
		cout<<"Give Value of Row:";
		cin>>row;
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
				cout<<"Try Again."<<endl;
			}
			break;}
		case 2: {
			Level2 lev2;
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
				cout<<"Try Again."<<endl;
			}
			break;}
		case 3: {
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
				cout<<"Try Again."<<endl;
			}
			break;}
	}
	return 0;
}
