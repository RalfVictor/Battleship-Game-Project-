#include<iostream>
#include<windows.h>
#include<MMsystem.h>


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void blue(){
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);  
}
void black(){
	SetConsoleTextAttribute(hConsole, 0 | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
}
void bgmmusic(){
		PlaySound("Puzzle-Dreams-3.wav",NULL,SND_ASYNC| SND_LOOP);
}
void hit(){
	PlaySound("hit.wav",NULL,SND_ASYNC); //add your own directory for the files
}
void miss(){
	PlaySound("miss.wav",NULL,SND_ASYNC);//add your own directory for the files
}
void error(){
	PlaySound("erro.wav",NULL,SND_ASYNC);//add your own directory for the files
}

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
		bgmmusic();
		cout<<"Attempt - "<<getcurrentattempt()+1<<"         "<<"Total Attempts - "<<gettotattempt()<<endl;
		cout<<"No. of Ships of Length 2 -> 2 \nNo. of Ships of Length 3 -> 1 "<<endl;
		cout<<"  COL ";
		for(int i=0;i<4;i++){
			cout<<" "<<i+1<<"  ";
		}
		cout<<endl<<"ROW  ";
		for(int j=0;j<4;j++){
				cout<<" ---";
			}cout<<endl;
		for(int i=0;i<4;i++){
			cout<<"   "<<i+1<<" |";
			for(int j=0;j<4;j++){
				blue();  
				cout<<" "<<Matrixgame[i][j]<<" ";
				black();  
				cout<<"|";
			}cout<<endl<<"     ";
			for(int j=0;j<4;j++){
				if(i<3){
				cout<<"|";
				blue();
				cout<<"---";
				black(); 
				}
				else{
					cout<<" ---";
				}
				
			}if(i<3){
				cout<<"|"<<endl;
				}
				else{
					cout<<endl;
				}
		}cout<<"Input both Row and Column as 0 To go To Main Menu."<<endl;
	}
	char updatematrix(){
		Invalidlev1:
		int row,col;
		cout<<"Give Value of Row:";
		cin>>row;
		cout<<"Give Value of Column:";
		cin>>col;
		if(row==0 && col==0){
			return 'x';
		}
		if(Matrixgame[row-1][col-1]==Matrix[row-1][col-1]){
			cout<<"Row and Column Already Hit."<<endl;
			error();
			Sleep(500);
			system("cls");
			display();
			goto Invalidlev1;
		}
		else{
		if(row>4 || row<1 || col>4 || col<1){
			cout<<"Invalid Row or Column Input."<<endl;
			error();
			Sleep(500);
			system("cls");
			display();
			goto Invalidlev1;
		}
		else{Matrixgame[row-1][col-1]=Matrix[row-1][col-1];
		updateattempt();
		if(Matrixgame[row-1][col-1]=='1'){
			hit();
			cout<<"You Scored a Hit!!"<<endl;
		}
		else{
			miss();
			cout<<"You Missed!!"<<endl;
		}
		Sleep(1000);
		system("cls");
		return Matrixgame[row-1][col-1];}
	}
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
		Level2():Battleship(11,17){
		}
		void display(){
		bgmmusic();
		cout<<"Attempt - "<<getcurrentattempt()+1<<"         "<<"Total Attempts - "<<gettotattempt()<<endl;
		cout<<"No. of Ships of Length 2 -> 4 \nNo. of Ships of Length 3 -> 1 "<<endl;
		cout<<"  COL  ";
		for(int i=0;i<5;i++){
			cout<<" "<<i+1<<"  ";
		}
		cout<<endl<<"ROW  ";
		for(int j=0;j<5;j++){
				cout<<" ---";
			}cout<<endl;
		for(int i=0;i<5;i++){
			cout<<"   "<<i+1<<" |";
			for(int j=0;j<5;j++){
				blue();  
				cout<<" "<<Matrixgame[i][j]<<" ";
				black();  
				cout<<"|";
			}cout<<endl<<"     ";
			for(int j=0;j<5;j++){
				if(i<4){
				cout<<"|";
				blue();
				cout<<"---";
				black(); 
				}
				else{
					cout<<" ---";
				}
				
			}if(i<4){
				cout<<"|"<<endl;
				}
				else{
					cout<<endl;
				}
		}cout<<"Input both Row and Column as 0 To go To Main Menu."<<endl;
	}
	char updatematrix(){
		Invalidlev2:
		int row,col;
		cout<<"Give Value of Row:";
		cin>>row;
		cout<<"Give Value of Column:";
		cin>>col;
		if(row==0 && col==0){
			return 'x';
		}
		if(Matrixgame[row-1][col-1]==Matrix[row-1][col-1]){
			cout<<"Row and Column Already Hit."<<endl;
			error();
			Sleep(500);
			system("cls");
			display();
			goto Invalidlev2;
		}
		else{
		if(row>5 || row<1 || col>5 || col<1){
			cout<<"Invalid Row or Column Input."<<endl;
			error();
			Sleep(500);
			system("cls");
			display();
			goto Invalidlev2;
		}
		else{Matrixgame[row-1][col-1]=Matrix[row-1][col-1];
		updateattempt();
		if(Matrixgame[row-1][col-1]=='1'){
			hit();
			cout<<"You Scored a Hit!!"<<endl;
		}
		else{
			miss();
			cout<<"You Missed!!"<<endl;
		}
		Sleep(1000);
		system("cls");
		return Matrixgame[row-1][col-1];}
	} 
	}
};

class Level3:public Battleship{
	private:
		char Matrix[6][6]=
						  {{'1','1','1','1','0','0'},
						   {'0','0','0','0','1','0'},
						   {'1','0','1','0','1','1'},
						   {'1','0','1','0','1','1'},
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
		Level3():Battleship(19,26){
		}	
	void display(){
		bgmmusic();
		cout<<"Attempt - "<<getcurrentattempt()+1<<"         "<<"Total Attempts - "<<gettotattempt()<<endl;
		cout<<"No. of Ships of Length 2 -> 1 \nNo. of Ships of Length 3 -> 3 \nNo. of Ships of Length 4 -> 2"<<endl;
		cout<<"  COL ";
		for(int i=0;i<6;i++){
			cout<<" "<<i+1<<"  ";
		}
		cout<<endl<<"ROW  ";
		for(int j=0;j<6;j++){
				cout<<" ---";
			}cout<<endl;
		for(int i=0;i<6;i++){
			cout<<"   "<<i+1<<" |";
			for(int j=0;j<6;j++){
				blue();  
				cout<<" "<<Matrixgame[i][j]<<" ";
				black();  
				cout<<"|";
			}cout<<endl<<"     ";
			for(int j=0;j<6;j++){
				if(i<5){
				cout<<"|";
				blue();
				cout<<"---";
				black(); 
				}
				else{
					cout<<" ---";
				}
				
			}if(i<5){
				cout<<"|"<<endl;
				}
				else{
					cout<<endl;
				}
		}cout<<"Input both Row and Column as 0 To go To Main Menu."<<endl;
	}
	char updatematrix(){
		Invalidlev3:
		int row,col;
		cout<<"Give Value of Row:";
		cin>>row;
		cout<<"Give Value of Column:";
		cin>>col;
		if(row==0 && col==0){
			return 'x';
		}
		if(Matrixgame[row-1][col-1]==Matrix[row-1][col-1]){
			cout<<"Row and Column Already Hit."<<endl;
			error();
			Sleep(1000);
			system("cls");
			display();
			goto Invalidlev3;
		}
		else{
		if(row>6 || row<1 || col>6 || col<1){
			cout<<"Invalid Row or Column Input."<<endl;
			Sleep(500);
			system("cls");
			display();
			goto Invalidlev3;
		}
		else{Matrixgame[row-1][col-1]=Matrix[row-1][col-1];
		updateattempt();
		if(Matrixgame[row-1][col-1]=='1'){
			hit();
			cout<<"You Scored a Hit!!"<<endl;
		}
		else{
			miss();
			cout<<"You Missed!!"<<endl;
		}
		Sleep(1000);
		system("cls");
		return Matrixgame[row-1][col-1];}
	}
	}	
};

class Level4:public Battleship{
	private:
		char Matrix[7][7]=
						  {{'1','1','0','1','1','0','0'},
						   {'0','0','1','0','0','0','1'},
						   {'1','0','1','0','1','0','1'},
						   {'1','0','0','0','1','0','1'},
						   {'1','1','1','0','1','0','1'},
						   {'1','0','0','0','0','1','1'},
						   {'0','1','1','1','0','1','0'}};
		char Matrixgame[7][7]=
						  {{' ',' ',' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' ',' ',' '},
						   {' ',' ',' ',' ',' ',' ',' '}};
	public:
		Level4():Battleship(25,38){
		}	
	void display(){
		bgmmusic();
		cout<<"Attempt - "<<getcurrentattempt()+1<<"         "<<"Total Attempts - "<<gettotattempt()<<endl;
		cout<<"No. of Ships of Length 2 -> 5 \nNo. of Ships of Length 3 -> 2\nNo. of Ships of Length 4 -> 1\nNo. of Ships of Length 5 -> 1 "<<endl;
		cout<<"  COL ";
		for(int i=0;i<7;i++){
			cout<<" "<<i+1<<"  ";
		}
		cout<<endl<<"ROW  ";
		for(int j=0;j<7;j++){
				cout<<" ---";
			}cout<<endl;
		for(int i=0;i<7;i++){
			cout<<"   "<<i+1<<" |";
			for(int j=0;j<7;j++){
				blue();  
				cout<<" "<<Matrixgame[i][j]<<" ";
				black();  
				cout<<"|";
			}cout<<endl<<"     ";
			for(int j=0;j<7;j++){
				if(i<6){
				cout<<"|";
				blue();
				cout<<"---";
				black(); 
				}
				else{
					cout<<" ---";
				}
				
			}if(i<6){
				cout<<"|"<<endl;
				}
				else{
					cout<<endl;
				}
		}
		cout<<"Input both Row and Column as 0 To go To Main Menu."<<endl;
	}
	char updatematrix(){
		Invalidlev4:
		int row,col;
		cout<<"Give Value of Row:";
		cin>>row;
		cout<<"Give Value of Column:";
		cin>>col;
		if(row==0 && col==0){
			return 'x';
		}
		if(Matrixgame[row-1][col-1]==Matrix[row-1][col-1]){
			cout<<"Row and Column Already Hit."<<endl;
			error();
			Sleep(1000);
			system("cls");
			display();
			goto Invalidlev4;
		}
		else{
		if(row>7 || row<1 || col>7 || col<1){
			cout<<"Invalid Row or Column Input."<<endl;
			Sleep(500);
			system("cls");
			display();
			goto Invalidlev4;
		}
		else{Matrixgame[row-1][col-1]=Matrix[row-1][col-1];
		updateattempt();
		if(Matrixgame[row-1][col-1]=='1'){
			hit();
			cout<<"You Scored a Hit!!"<<endl;
		}
		else{
			miss();
			cout<<"You Missed!!"<<endl;
		}
		Sleep(1000);
		system("cls");
		return Matrixgame[row-1][col-1];}
	}
	}	
};

int StartMenu(){
	int MenuCom;
	cout<<"----------------BattleShip-----------------"<<endl;
	cout<<endl<<endl;
	cout<<"                 1.Play                    "<<endl;
	cout<<"                 2.Help                    "<<endl;
	cout<<"                 3.Exit                    "<<endl;
	cin>>MenuCom;
	return MenuCom;
}

int LevelSelect(){
	int LevelCom;
	cout<<"--------------Level Select---------------"<<"\n\n"
		<<"              Level 1 (4x4)"<<endl
		<<"              Level 2 (5x5)"<<endl
		<<"              Level 3 (6x6)"<<endl
		<<"              Level 4 (7x7)"<<endl
		<<"          Press 0 to Go to Main Menu."
		<<"\n\n"<<"Give Level No:";
	cin>>LevelCom;
	Sleep(500);
	system("cls");
	return LevelCom;
}

int HelpSec(){
	int HelpCom;
	cout<<"----------------Help---------------"<<endl<<endl<<"1.Battleship is a war-themed board\n game for two players in which the\n opponents try to guess the location\n of their opponent's warships \nand sink them."<<endl
	<<"\n2.Player take turns firing shots\n (by calling out a grid coordinate)\n to attempt to hit the opponent's\n enemy ships."<<
	endl<<"\n3.If Target hits, 1 is Registered,\n else 0 is registered."<<endl
	<<"Hit all The 1's in the Grid To win."<<endl<<endl<<"Press 0 to Go back to Main Menu."<<endl;
	cin>>HelpCom;
	Sleep(500);
	system("cls");
	return HelpCom;
}

void ExitScreen(){
	cout<<"----------Exit Screen---------"<<endl<<endl<<
	"Thank You For Playing"<<endl<<endl<<
	"Developers\nRalf Paul Victor - 22BEC1222\nMrinank Gaur - 22BEC1258";
}

void Secret(){
	PlaySound("we-live-we-love-we-lie.wav",NULL,SND_ASYNC);//add your own directory for the files
	Sleep(1500);
	cout<<"                                                                                                                                                                 \n"
 "                                                                                                                                                                          \n"  
 " :???????^          !??????7         .7?????7.  .7????????????????!                 ~??????^              .7?????7   :???????.             7??????^   !????????????????7. \n"    
 " .B@@@@@@P         ~@@@@@@@@~        !@@@@@@5   :&@@@@@@@@@@@@@@@@B                 Y@@@@@@?              :@@@@@@#.  .B@@@@@@5            7@@@@@@#.   B@@@@@@@@@@@@@@@@&. \n"    
 "  !@@@@@@@^        G@@@@@@@@G        G@@@@@&:   :&@@@@@@@@@@@@@@@@G                 Y@@@@@@?              :&@@@@@#.   ^&@@@@@@!          .#@@@@@&^    B@@@@@@@@@@@@@@@@&. \n"    
 "   P@@@@@@Y       7@@@@@@@@@@!      ~@@@@@@J    :&@@@@@&!~~~~~~~~!^                 Y@@@@@@?              :&@@@@@#.    7@@@@@@B.         5@@@@@@?     B@@@@@@?~~~~~~~~!~  \n"    
 "   ^@@@@@@&:     .#@@@@B@@@@@G      5@@@@@#.    :&@@@@@#                            Y@@@@@@?              :&@@@@@#.     5@@@@@@Y        ~@@@@@@5      B@@@@@@^            \n"    
 "    5@@@@@@J     J@@@@&~#@@@@@!    :&@@@@@7     :&@@@@@#                            Y@@@@@@?              :&@@@@@#.     .B@@@@@@^      .B@@@@@#.      B@@@@@@^            \n"    
 "    :&@@@@@#.   ^&@@@@5 J@@@@@B    J@@@@@G      :&@@@@@&YJJJJJJJYJ.                 Y@@@@@@?              :&@@@@@#.      ~@@@@@@G      J@@@@@@~       B@@@@@@5JJJJJJJYJ:  \n"    
 "     J@@@@@@7   P@@@@&: .#@@@@@7  .#@@@@@~      :&@@@@@@@@@@@@@@@&.                 Y@@@@@@?              :&@@@@@#.       J@@@@@@?    ^&@@@@@J        B@@@@@@@@@@@@@@@@~  \n"    
 "     .#@@@@@G  ~@@@@@J   7@@@@@B  7@@@@@P       :&@@@@@@@@@@@@@@@#.                 Y@@@@@@?              :&@@@@@#.        P@@@@@&:   G@@@@@P         B@@@@@@@@@@@@@@@@~  \n"    
 "      7@@@@@@~ B@@@@#.    B@@@@@7 B@@@@&^       :&@@@@@#~^^^^^^^^^                  Y@@@@@@?              :&@@@@@#.        :#@@@@@P  7@@@@@#:         B@@@@@@!^^^^^^^^^.  \n"    
 "       G@@@@@57@@@@@7     !@@@@@B!@@@@@Y        :&@@@@@#.                           Y@@@@@@?              :&@@@@@#.         !@@@@@@!.&@@@@@!          B@@@@@@^            \n"    
 "       ~@@@@@#B@@@@G       P@@@@@B@@@@#:        :&@@@@@#                            Y@@@@@@?              :&@@@@@#.          Y@@@@@B5@@@@@Y           B@@@@@@^            \n"    
 "        P@@@@@@@@@@~       ^@@@@@@@@@@?         :&@@@@@&YYYYYYYYYYY~                Y@@@@@@GJYYYYYYYYY?   :&@@@@@#.          .B@@@@@@@@@@G            B@@@@@@5JYYYYYYYYY7 \n"    
 "        ^@@@@@@@@@P         5@@@@@@@@B.         :&@@@@@@@@@@@@@@@@@J                Y@@@@@@@@@@@@@@@@@B   :&@@@@@#.           ^&@@@@@@@@&^            B@@@@@@@@@@@@@@@@@G \n"    
 "         Y@@@@@@@&^         :&@@@@@@@!          :#@@@@@@@@@@@@@@@@@?                J@@@@@@@@@@@@@@@@@G   :&@@@@@B.            ?@@@@@@@@7             G@@@@@@@@@@@@@@@@@P \n"    
  "        .^:::::^:           :^::::::            :::::::::::::::::^.                .^:::::::::::::::^:    :::::^:              ::::::^:              :^:::::::::::::::^: \n";                                                                            
       Sleep(1000);
       system("cls");
       cout<<"                                                                                                                                                                \n"
"                                                                                                                                                                             \n"  
"YPPPPPP:         YPPPPPP!        ~PPPPPP:  .5PPPPPPPPPPPPPPP!               .5PPPPP!                 .^7YPGBB#BBG5J!:       .5PPPPP5.           ~PPPPPG!  .5PPPPPPPPPPPPPPP? \n"  
" ?@@@@@@Y        ?@@@@@@@B        G@@@@@P   :@@@@@@@@@@@@@@@@J               :@@@@@@?               ~5#@@@@@@@@@@@@@@&G?.     ?@@@@@@J          .B@@@@@B.  .&@@@@@@@@@@@@@@@5\n"  
"  G@@@@@&:      :&@@@@@@@@7      ^@@@@@&:   :&@@@@@BPGGGGGGGG7               :&@@@@@?             ^G@@@@@@@BGP5PG&@@@@@@#7     5@@@@@@^         J@@@@@&:   .#@@@@@#PPGGGGGGG?\n"  
"  ~@@@@@@J      5@@@@&@@@@#.     5@@@@@J    :&@@@@@?                         :&@@@@@?            !&@@@@@&J^      .7B@@@@@@Y    .B@@@@@G        ~@@@@@@!    .#@@@@@J          \n"  
"   5@@@@@#.    ~@@@@#?@@@@@J    :&@@@@#.    :&@@@@@7                         :&@@@@@?           ^@@@@@@B:           P@@@@@@?    ^&@@@@@?       B@@@@@J     .#@@@@@J          \n"  
"   :&@@@@@?    G@@@@J B@@@@&:   Y@@@@@7     :&@@@@@P7777777?!                :&@@@@@?           P@@@@@@^            :&@@@@@B.    ?@@@@@&^     J@@@@@G      .#@@@@@G7777777?7 \n"  
"    J@@@@@B.  ?@@@@#. !@@@@@Y  .#@@@@G      :&@@@@@@@@@@@@@@G                :&@@@@@?          .#@@@@@B              G@@@@@&:     5@@@@@G    ^@@@@@#:      .#@@@@@@@@@@@@@@&.\n"  
"    .#@@@@@7 :#@@@@7   P@@@@&: ?@@@@@^      :&@@@@@&&&&&&&&&P                :&@@@@@?          .#@@@@@#.             G@@@@@&.     .B@@@@@?   G@@@@@~       .#@@@@@&&&&&&&&&B.\n"  
"     !@@@@@G Y@@@@G    ^@@@@@5 B@@@@Y       :&@@@@@J.........                :&@@@@@?           5@@@@@@7            ^@@@@@@P       ^&@@@@&^ ?@@@@@J        .#@@@@@Y......... \n"  
"      G@@@@@?&@@@@^     Y@@@@&?@@@@&:       :&@@@@@?                         :&@@@@@?           ^&@@@@@&7          ^#@@@@@&^        ?@@@@@P^&@@@@P         .#@@@@@J          \n"  
"      ^@@@@@&@@@@Y      :&@@@@&@@@@?        :&@@@@@J.:::::::::               :&@@@@@J.::::::::.  ~#@@@@@@G?^:..:^7P@@@@@@#^          5@@@@&B@@@@#.         .#@@@@@Y.:::::::::\n"  
"       Y@@@@@@@@&:       ?@@@@@@@@B         :&@@@@@&&&&&&&&&&&^              :&@@@@@&&&&&&&&&&#.  .J&@@@@@@@&&&&@@@@@@@#J.           .B@@@@@@@@@~          .#@@@@@@&&&&&&&&&&\n" 
"       :&@@@@@@@?        .B@@@@@@@!         :@@@@@@@@@@@@@@@@@^              :@@@@@@@@@@@@@@@@@.    .7P#@@@@@@@@@@@@#P7.              ^&@@@@@@@?           .&@@@@@@@@@@@@@@@@\n" 
"        ^777777!.         ^777777!          .!7777777777777777.              .!777777777777777!        .^!?JYYYYJ7!^.                  ~777777!             !7777777777777777\n";              
    	Sleep(1000);
       	system("cls");
		   cout<<"                                                                                                                                                                       \n"
"                                                                                                                                                                             \n"  
" .........              .........             .........    .......................                      ........                    ........         ......................  \n" 
" :B#######&!            7&#######&7           ~#######&7    ?&###################&Y                     !&#######!                  7&#######~       :######################:\n"  
"  Y@@@@@@@@G           .#@@@@@@@@@B.          P@@@@@@@#.    J@@@@@@@@@@@@@@@@@@@@@5                     7@@@@@@@@!                  ?@@@@@@@@!       :@@@@@@@@@@@@@@@@@@@@@&:\n"  
"  .#@@@@@@@@~          Y@@@@@@@@@@@?         ^&@@@@@@@7     J@@@@@@@@@@@@@@@@@@@@@P                     7@@@@@@@@!                  ?@@@@@@@@!       :&@@@@@@@@@@@@@@@@@@@@@:\n"  
"   ?@@@@@@@@P         ^&@@@@@@@@@@@#.        Y@@@@@@@G      J@@@@@@@@Y7???????????~                     7@@@@@@@@!                  ?@@@@@@@@!       :&@@@@@@@G7???????????7.\n"  
"   .B@@@@@@@&^        P@@@@@&@@@@@@@?       .#@@@@@@@~      J@@@@@@@@^                                  7@@@@@@@@!                  ?@@@@@@@@!       :&@@@@@@@Y              \n"  
"    !@@@@@@@@Y       ~@@@@@@5P@@@@@@#.      ?@@@@@@@P       J@@@@@@@@^                                  7@@@@@@@@!                  ?@@@@@@@@!       :&@@@@@@@5              \n"  
"     G@@@@@@@#.      B@@@@@@~7@@@@@@@?      B@@@@@@&^       J@@@@@@@@^                                  7@@@@@@@@!                  ?@@@@@@@@!       :&@@@@@@@Y              \n"  
"     ~@@@@@@@@?     7@@@@@@P .B@@@@@@#.    !@@@@@@@Y        J@@@@@@@@PYYYYYYYYYY57                      7@@@@@@@@!                  ?@@@@@@@@!       :&@@@@@@@BYYYYYYYYYYYY. \n"  
"      5@@@@@@@B.   .#@@@@@@^  !@@@@@@@J    P@@@@@@&:        J@@@@@@@@@@@@@@@@@@@@P                      7@@@@@@@@!                  ?@@@@@@@@!       :&@@@@@@@@@@@@@@@@@@@@^ \n"  
"      ^&@@@@@@@!   Y@@@@@@Y    G@@@@@@#.  ^@@@@@@@?         J@@@@@@@@@@@@@@@@@@@@P                      7@@@@@@@@!                  ?@@@@@@@@!       :&@@@@@@@@@@@@@@@@@@@@^ \n"  
"       Y@@@@@@@G  ^&@@@@@&:    ~@@@@@@@J  Y@@@@@@B.         J@@@@@@@@BGBBBBBBBBBBJ                      7@@@@@@@@!                  ?@@@@@@@@!       :&@@@@@@@&GBBBBBBBBBBG: \n"  
"       :#@@@@@@@~ P@@@@@@J      P@@@@@@&..&@@@@@@7          J@@@@@@@@^                                  7@@@@@@@@!                  ?@@@@@@@@!       :&@@@@@@@5              \n"  
"        ?@@@@@@@5~@@@@@@#.      ^@@@@@@@?7@@@@@@G           J@@@@@@@@^                                  7@@@@@@@@!                  ?@@@@@@@@!       :&@@@@@@@5              \n"  
"        .B@@@@@@BP@@@@@@7        5@@@@@@BG@@@@@@~           J@@@@@@@@^                                  7@@@@@@@@!                  ?@@@@@@@@!       :&@@@@@@@Y              \n"  
"         7@@@@@@@@@@@@@G         :&@@@@@@@@@@@@P            J@@@@@@@@!.::::::::::::.                    7@@@@@@@@7.::::::::::::.    ?@@@@@@@@!       :&@@@@@@@5.:::::::::::::\n"  
"          G@@@@@@@@@@@@!          J@@@@@@@@@@@&^            J@@@@@@@@&&&&&&&&&&&&&@J                    7@@@@@@@@@&&&&&&&&&&&&@?    ?@@@@@@@@!       :&@@@@@@@@&&&&&&&&&&&&@B\n" 
"          ~@@@@@@@@@@@P           .#@@@@@@@@@@Y             J@@@@@@@@@@@@@@@@@@@@@@J                    7@@@@@@@@@@@@@@@@@@@@@@?    ?@@@@@@@@!       :&@@@@@@@@@@@@@@@@@@@@@#\n" 
"           P@@@@@@@@@@^            ?@@@@@@@@@&:             J@@@@@@@@@@@@@@@@@@@@@@J                    7@@@@@@@@@@@@@@@@@@@@@@J    ?@@@@@@@@!       :@@@@@@@@@@@@@@@@@@@@@@&\n" 
"           .!~~~~~~~!^             .~~~~~~~~!^              :!~~~~~~~~~~~~~~~~~~~~!:                    :!~~~~~~~~~~~~~~~~~~~~!:    :!~~~~~~~.       .~~~~~~~~~~~~~~~~~~~~~~~\n"; 
		Sleep(500);
		system("cls");                                                                             
	cout<<"                                                                                                                                                                         \n"
 "                             ....                                                                                                            ...                              \n"
 "                         :^~!!!!!~:                                                                                                       :~!!!!!~^:                          \n"
 "                       :!7777777777!.                                                                                                   .!7777777777!:                        \n"
 "                     .~777??777777!7!.                                                                                                 .!7!777777??777~.                      \n"
 "                    :!???????77777777!.                                                                                                !777777777??????7:                     \n"
 "                   :777??????77777!!!7~.                                                                                              ~7!!!77777??????777^                    \n"
 "                  ^77777??????777!!!!!7!:                                                                                           :!7!!!!!777??????77777~.                  \n"
 "               .^!7777!7777777777!!!!!!!7~.                          :~~~~~^::::::::::::::::::~~~~~^:                             .~77!!!!!!!777777777!7777!~.                \n"
 "             .^!7!!!!7!!!77!!!!!!!!!!!!!!7!~:                      .!!:.. .~~~~~~~~~~~~~~~~~~~:  ..^7~                          .~!7!!!!!!!!!!!!!!!7!!!!!!!!7!~.              \n"
 "          .:~!77777777777777??77777777!!!!!7!~:                    ~7. ~!~~!~~~~~~~~^~~~~~~~~~~~~~. ^?:                       :~!7!!!!!!77777777?777777777777!7!~:.           \n"
 "        .~7777???JYY55PPGPPPGGGPPPPPP55YYYJ????!:                  ~7.  ....~~~~~~::.:~~~~~~~:...   !7.                     :!7???JJYYY5PPPPPPPGPPPPPP55YYYJ???7777~.         \n"
 "       :7?JY5GBB###&&&&&&&&&&&&&&&########BBGGPPY?:                .7!.     ^~~~~~~^.:~~~~~~~     .!7:                    :7YPPGGBB#########&&&&&&&&&&&&#####BBGPYJ?7^        \n"
 "      ^JYPB#&&@@&@@&@@@&@@@&@@&&&&&&&&&&&&&&###BBG5:                .~!^.   .~~~~~~^.:~~~~~~:   .~7~.                    ^5GBB###&&&&&&&&&&&&&&@@@@@@&@@@&@@&@@&&&BGYJ!       \n"
 "      JBB&&&@&&&&&&&&@@&&&@@&@@@@@&&&@&&&&&&&&&#BG5:                  :~!~:. :~~~~~~^^~~~~~^ .^!!^.                      ^5GB#&&&&&&&&&@&&&@@@@@&@@@&&@@&&&&&&&&@&&&#B5:      \n"
 "      !P#&&&&&&&&&&&&&&&&&&@&&&&@@&&&&&&&&&&#BBPY7:                     .:~~~~!~~~~~~~~~~~!~!~^.                          :75GBB#&&&&&&&&&&@@&&&&@&&&&&&&&&&&&&&&&&&&BJ       \n"
 "       :7P#&&&&&&&&&&&&&&@@@&@@&&&&#BBB#&&@G!^:.                            .:::^~~~~~~~~::.                                 .:~!G@&&#BBB#&&@&@@&@@@&&&&&&&&&&&&&&#BJ~.       \n"
 "         .?GGB#&&#####&&###&&######B5??PB#P^                                     .:~~!^:.                                        ~G#BP??5B######&&&###&&#&##&&#BBG5:          \n"
 "     ^:^:  !Y5PB###B########BBG5Y5GGPJ??J?.                                        ~77.                                           .?J??J5GB5Y5GBB############BG55?: .:::.     \n"
 "     !YGB?  .^7?JJJ5GBBBBBBBBGP5YYPB##BG5~                                         ^7~                                             ~5GBB#BPYY5PGBBBBBBBBBPYYJJ?~.  ^PG5J.     \n"
 "     ^YG#5:        :7YPGGGGGGBGGGGGG##BG5^                                      .:^^~~^:.                                          ^5GB##GGGGGGBGGGGGGP5J^         ?BB57      \n"
 "     :YG#5~J7~~       ~PGGGGGGGGGBBBP5J7:                                     ~!?JJ???JJ?7!.                                        ^7Y5GBBBBGGGGGGGGP!.      :!^J!?BB5!      \n"
 "   .!?YG#P:.7?5!:::^7YJPGB##B5^^!!7!:                                         JP?????????55:                                            :!77!~~YB##BGGJJ?^:.:^JJ?^ J#B5J!^    \n"
 "  ^?YPGGBP:  .G#BBGGPG#BGBBBBY^.                                              JPJ????????55:                                                  :JBBBBGB#GPGGGBBB~   J#GGP5J~   \n"
 " .YPBBB#BP^  ~###G55PGGGBGGPPY??~                                             ~!!!!!!!!!!!!.                                                ^7?YPPGGBGGGP55P#&&?   JB##BBP5~  \n"
 " .5B######G~ ?#BPPGBBBGGPP55YJ?7?7.                                                                                                       .!?7?JY555PPPGBBGPPG#5 :Y######BG~  \n"
 "  :YB#&&&@#!:YPP5J7B@&#BGP55555J7JY!:.                                                                                                  .~YY7J55555PGB#&&#?J5PP5^:G@@&&##P7   \n"
 "    ^?YYY7:^YGP!.  P&&&##BGP5YY5Y~^JPJ~.                                                                                             .~?5J~^J5YY5PGBB#&&&B: .^5G5~:7Y55Y!:    \n"
 "          ~5P!.   !GB##BBGGP5YJJ5?  ~J5?~:.                                                                                        :~?5J!  75JJY5PPGBB##BB7    ~5P!.          \n"
 "     .~?J5G#7   .75BBBBBBGGPP5YYY5:  ^YJJJ7~:.                                                                                  :~7?JJY:  .YYYY55PGGBBBBBBP?:   :GB5J7~.      \n"
 "   .?5GGG##G^ ..^JYY5PPGGGGPP5YYYJ.  J5!~?55?7  ?YJ.  :YY~  ~J5PPY!.  .JY~   :YY^     7YY:  .JYJ.  ~YY::YY^ .JYJ:   :YY: .YY~  !?55?!!5J  .JYYY55PGGGGPP55YY~..  5##BGGPJ^    \n"
 "   ^JPB#B5!.  !Y?7???JJJJY55555YJ?.  !P^  ~G5Y^ ~&@P .B@P ^B@#Y?JB@#! :@@J   ~@@7     !@@J  J@@@?  G@G ~@@7 :@@@&!  ~@@~ :@@J ^Y5G~  :P7  .?YY555P55YJJJJ??77Y?   ~YB#BGY!    \n"
 "   :?PP?:      :77777777?JJ??JJ??~.   .    5#?.  ^#@5G@Y  B@B.    G@&.:@@J   ~@@7      P@# :&&J@#.^@@^ ~@@7 :&@YB@Y ^@@~ .&@7 .J#5    :    ~?JJJJ?JJ??777777?^      :75GY~    \n"
 "    ~^.     :~~^7J????7777JJJJ?~:          ~J:    :B@@J  .&@G     5@@::@@J   ^@@7      ^&@75@J B@?Y@5  ~@@7 :&@7 Y@G7@@~  B@~  :J~          :~?JJJJ?777????J?^^^:      :~:    \n"
 "           !?JJJJYYYJJ???77?J?^                    J@@:   ?@@5~^~Y@@J  G@#!^~P@&:       Y@&@#. !@&@&:  ~@@7 :@@7  !&@@@~  ?Y^                 :?J?777??JJJYJJJJJ?7.           \n"
 "         .!JY555Y7?YYYJJJ?77!.                     ?BG:    ^YB###BY^   .JG###BY:        .GBB!   5BB?   ^BB! .GB!   :PBB^ :G#?                   ~77?JJJJYYJ7J555YY?.          \n"
 "         !YJYYYY?^.:~7??????^                                  .           .                                                                    :????J??!^.:7YYYYJY?.         \n"
 "        :JYYYJJJ?7!.  .::::^:     .                                                                                                             .~^::^:   ~77JJJYYYJ~         \n"
 "        ~PGG5555Y?7.    ^~!77!!!!777!~:.           .:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::            .:^!!7!!!~~!7!~^     !?JYYY5PGG?         \n"
 "         ^!?Y55YJ7:    .?J??J??J?JJ?JJ??^        :?!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~?~         :7????JJ?J??J????.    :!JY555J7~.         \n"
 "                        7JJYYYYY55PPGPY7.        ?7                                                                      :5         .75PPPP5YYYYYJJJ?.       ...              \n"
 "                       .?5YYYYYYYJ7!~:.          ?!                ...        .    .                ...       ..    .    :5           .^~7?Y555YYYY5J.                        \n"
 "                        .:...                    ?7      GP  .B5 ^5G5PG! 7#~ :GP ^#J   ^B#Y  ~##? ~PP5GP~ YB: ~#Y 7#!    :5                   ....:^:                         \n"
 "                                                 ?7      #&??J@P.##.  5@^?@!  ~&P#5    ^@P@7.#P@J^@P  .B&.P@:  7@5&?     :5                                                   \n"
 "                                                 ?7      #&!!7@P #&^..P@^?@7.. ~@G     ^@7?&GP^@J:@G:.:##.P@^.. ?@J      :5                                                   \n"
 "                                                 ?7      55  .PJ :YP5P5^ !G55Y..G?     :G! 5G.:G7 ^5P5PY: JG55J ~B!      :5                                                   \n"
 "                                                 ?7                                                                      :5                                                   \n"
 "                                                 ?!                                                                      .5                                                   \n"
 "                                                 7?                                                                      ~Y                                                   \n"
 "                                                  !7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!?5!!75!!!!!!!!!!!!!!!!!!.                                                   \n"
 "                                                                               .^~~^:::::~!~^.     ?J  Y?                                                                     \n"
 "                                                                             .?5YJYJ~~~~!JJJY57.    57 .G.                                                                    \n"
 "                                                                           :!77~::::     .:::~77!:.7Y. ?Y                                                                     \n"
 "                                                                         ^77~:..   :~...^^....:^!7J? ~Y7                                                                      \n"
 "                                                                       .!?7^~!^^!J7:~^.^~:?Y7~~??!77J?.                                                                       \n"
 "                                                                      .7?7^7PJYPGBB5~!:~~5BBGBGJ5P!?7!.                                                                       \n"
 "                                                                      !?77:5G?5@PG#5!!:!~5G#5&#?JP~7??!                                                                       \n"
 "                                                                     :?77?^~JJP##B5!^!:~^^JP##B5J!^?77?:                                                                      \n"
 "                                                                     !?7!77~^~!!!~:.~^:^~..:~~~^^~77!7?!                                                                      \n"
 "                                                                     !?77!~~~~~^^^^^^::::^^::^^~!!!!77?!                                                                      \n"
 "                                                                     ^J77!!~~~~^^^^^~!!!^::^^^~~~~!!77J^                                                                      \n"
 "                                                                      7?77!!~~~~^^?G&@@@&G7:^^~~~!!77?7                                                                       \n"
 "                                                                      :??777!!~~~J@@@@@@@@&?^~~!!777??:                                                                       \n"
 "                                                                       :?J?777!!~P@&&&&&&@@Y~!!777?J7:                                                                        \n"
 "                                                                        .~???7777?G&#####&G7777????~                                                                          \n"
 "                                                                          .~7????77J55PP5J77????7~.                                                                           \n"
 "                                                                             :~7??J?????????7!^.                                                                              \n"
 "                                                                                ..:^~~~~^^:.                                                                                  \n"
 "                                                                                                                                                                              \n";
          Sleep(4000);
}

int main(){
	int LevelNo;
	int le1,le2,le3,le4;
	Start:
	bgmmusic();
	int MenuOut=StartMenu();
	if(MenuOut==1){
	Sleep(500);
	system("cls");
	LevelNo=LevelSelect();
	switch(LevelNo){
		case 0:{
			goto Start;
			break;
		}
		case 1: {
			Level1Re:
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
				}else if(Obtained=='x'){
					Sleep(1000);
					system("cls");
					goto Start;
				}
				goto Level1con;
			}
			else{cout<<"You Win"<<endl;
			le1=1;
				if(le1==1&&le2==1&&le3==1&&le4==1){
			goto secretending;
			}
			else{
				goto commandprompt1;
			}
			}
			}
			else{
				cout<<"You lost."<<endl;
			}int command;
			commandprompt1:
			cout<<"If You Want to Continue(1)  OR  To Exit(0)  OR  Try again (2)"<<endl;
			cin>>command;
			if(command==1){
				system("cls");
				goto Start;
				}
				else if(command == 2){
					Sleep(500);
					system("cls");
				goto Level1Re;
			}
			else if(command==0){
				goto Exit;
			}
			else{
				cout<<"Invalid Command. Try Again"<<endl;
				Sleep(500);
				system("cls");
				goto commandprompt1;
			}
			
			break;}
		case 2:{
			Level2Re:
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
				}else if(Obtained=='x'){
					Sleep(1000);
					system("cls");
					goto Start;
				}
				goto Level2con;
			}
			else{cout<<"You Win"<<endl;
			le2=1;
				if(le1==1&&le2==1&&le3==1&&le4==1){
			goto secretending;
			}
			else{
				goto commandprompt2;
			}
			}
			}
			else{
				cout<<"Try Again."<<endl;
			}int command;
			commandprompt2:
			cout<<"If You Want to Continue(1)  OR  To Exit(0)  OR  Try again (2)"<<endl;
			cin>>command;
			if(command==1){
				Sleep(500);
				system("cls");
				goto Start;
			}
			else if(command == 2){
				Sleep(500);
				system("cls");
				goto Level2Re;
			}
			else if(command!=0){
				cout<<"Invalid Command. Try Again"<<endl;
				Sleep(500);
				system("cls");
				goto commandprompt2;
			}
			else if(command==0){
				goto Exit;
			}
			break;}
		case 3:{
			Level3Re:
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
				}else if(Obtained=='x'){
					Sleep(1000);
					system("cls");
					goto Start;
				}
				goto Level3con;
			}
			else{cout<<"You Win"<<endl;
			le3=1;
				if(le1==1&&le2==1&&le3==1&&le4==1){
			goto secretending;
			}
			else{
				goto commandprompt3;
			}
			}
			}
			else{
				cout<<"Try Again."<<endl;
			}
			commandprompt3:
			int command;
			cout<<"If You Want to Continue(1)  OR  To Exit(0)  OR  Try again (2)"<<endl;
			cin>>command;
			if(command==1){
				Sleep(500);
				system("cls");
				goto Start;
			}
			else if(command==2){
				Sleep(500);
				system("cls");
				goto Level3Re;
			}
			else if(command!=0){
				cout<<"Invalid Command. Try Again"<<endl;
				Sleep(500);
				system("cls");
				goto commandprompt3;
			}
			else if(command==0){
				goto Exit;
			}
			break;
			}
		case 4:{
			Level4Re:
			Level4 lev4;
			int coun = 0;
			int Oricoun = lev4.getcount();
			Level4con:
			lev4.display();
			
			if(lev4.getcurrentattempt()<lev4.gettotattempt()){
			if(coun<Oricoun){
				char Obtained = lev4.updatematrix();
				if(Obtained=='1'){
					coun++;
				}else if(Obtained=='x'){
					Sleep(1000);
					system("cls");
					goto Start;
				}
				goto Level4con;
			}
			else{cout<<"You Win"<<endl;
			le4=1;
				if(le1==1&&le2==1&&le3==1&&le4==1){
			goto secretending;
			}
			else{
				goto commandprompt4;
			}
			}
			}
			else{
				cout<<"Try Again."<<endl;
			}
			commandprompt4:
			int command;
			cout<<"If You Want to Continue(1)  OR  To Exit(0)  OR  Try again (2)"<<endl;
			cin>>command;
			if(command==1){
				Sleep(500);
				system("cls");
				goto Start;
			}
			else if(command==2){
				Sleep(500);
				system("cls");
				goto Level4Re;
			}
			else if(command!=0){
				cout<<"Invalid Command. Try Again"<<endl;
				Sleep(500);
				system("cls");
				goto commandprompt4;
			}
			else if(command==0){
				goto Exit;
			}
			break;
			}
		}
	}
	else if(MenuOut==2){
		Sleep(500);
		system("cls");
		Help:
		int HelpOut=HelpSec();
		if(HelpOut!=0){
			goto Help;
		}
		else{
			goto Start;
		}
	}
	else if(MenuOut==16248){
		secretending:
		Sleep(500);
		system("cls");
		Secret();
	}	
	else if(MenuOut==3){
		Sleep(500);
		system("cls");
		Exit:
		system("cls");
		ExitScreen();
	}
	else{
		cout<<"Invalid Command"<<endl;
		Sleep(500);
		system("cls");
		goto Start;
	}
	return 0;
}
