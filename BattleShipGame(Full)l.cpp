#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>
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
				cout<<" "<<Matrixgame[i][j]<<" |";
			}cout<<endl<<"     ";
			for(int j=0;j<4;j++){
				if(i<3){
				cout<<"|---";
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
		}
	}
	char updatematrix(){
		InvalidLev2:
		int row,col;
		cout<<"Give Value of Row:";
		cin>>row;
		cout<<"Give Value of Column:";
		cin>>col;
		if(row>4 || row<1 || col>4 || col<1){
			cout<<"Invalid Row or Column Input."<<endl;
			Sleep(500);
			system("cls");
			display();
			goto InvalidLev2;
		}
		else{
		Matrixgame[row-1][col-1]=Matrix[row-1][col-1];
		updateattempt();
		if(Matrixgame[row-1][col-1]=='1'){
			PlaySound("C:\\mrinank\\Learning C\\Battleship\\hit.wav",NULL,SND_ASYNC);
			cout<<"You Scored a Hit!!"<<endl;
		}
		else{
			PlaySound("C:\\Users\\mrina\\Downloads\\miss.wav",NULL,SND_ASYNC);
			cout<<"You Missed!!"<<endl;
		}
		Sleep(1000);
		system("cls");
		return Matrixgame[row-1][col-1]; 
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
		cout<<"Attempt - "<<getcurrentattempt()+1<<"         "<<"Total Attempts - "<<gettotattempt()<<endl;
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
				cout<<" "<<Matrixgame[i][j]<<" |";
			}cout<<endl<<"     ";
			for(int j=0;j<5;j++){
				if(i<4){
				cout<<"|---";
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
		}
	}
	char updatematrix(){
		InvalidLev2:
		int row,col;
		cout<<"Give Value of Row:";
		cin>>row;
		cout<<"Give Value of Column:";
		cin>>col;
		if(row>5 || row<1 || col>5 || col<1){
			cout<<"Invalid Row or Column Input."<<endl;
			Sleep(500);
			system("cls");
			display();
			goto InvalidLev2;
		}
		else{
		Matrixgame[row-1][col-1]=Matrix[row-1][col-1];
		updateattempt();
		if(Matrixgame[row-1][col-1]=='1'){
			PlaySound("C:\\mrinank\\Learning C\\Battleship\\hit.wav",NULL,SND_ASYNC);
			cout<<"You Scored a Hit!!"<<endl;
		}
		else{
			PlaySound("C:\\Users\\mrina\\Downloads\\miss.wav",NULL,SND_ASYNC);
			cout<<"You Missed!!"<<endl;
		}
		Sleep(1000);
		system("cls");
		return Matrixgame[row-1][col-1];
		} 
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
		Level3():Battleship(17,24){
		}	
	void display(){
		cout<<"Attempt - "<<getcurrentattempt()+1<<"         "<<"Total Attempts - "<<gettotattempt()<<endl;
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
				cout<<" "<<Matrixgame[i][j]<<" |";
			}cout<<endl<<"     ";
			for(int j=0;j<6;j++){
				if(i<5){
				cout<<"|---";
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
		}
	}
	char updatematrix(){
		Invalidlev3:
		int row,col;
		cout<<"Give Value of Row:";
		cin>>row;
		cout<<"Give Value of Column:";
		cin>>col;
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
			PlaySound("C:\\mrinank\\Learning C\\Battleship\\hit.wav",NULL,SND_ASYNC);
			cout<<"You Scored a Hit!!"<<endl;
		}
		else{
			PlaySound("C:\\Users\\mrina\\Downloads\\miss.wav",NULL,SND_ASYNC);
			cout<<"You Missed!!"<<endl;
		}
		Sleep(1000);
		system("cls");
		return Matrixgame[row-1][col-1];
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
		<<"          Press 0 to Go to Main Menu."
		<<"\n\n"<<"Give Level No:";
	cin>>LevelCom;
	Sleep(500);
	system("cls");
	return LevelCom;
}

int HelpSec(){
	int HelpCom;
	cout<<"-----------------Help--------------"<<endl<<endl<<"1.Battleship is a war-themed board game for two players in which the opponents try to guess the location of their opponent's warships and sink them."<<endl
	<<"2.Player take turns firing shots (by calling out a grid coordinate) to attempt to hit the opponent's enemy ships."<<
	endl<<"3.If Target hits, 1 is Registered, else 0 is registered."<<endl
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
	PlaySound("C:\\Users\\mrina\\Downloads\\we-live-we-love-we-lie.wav",NULL,SND_ASYNC);
	Sleep(1500);
	cout<<"\n\n\n\n\n\n\n\n"                                                                                  
          "   .   ..   ..    .....           .       .     .     .    .....                \n"
          "  -@=  @@-  @+    @%++=          @      .@   .@#   %%    %@+++                \n" 
          "   #@ +%#% =@.    @%==.          @      .@    =@- =@.    %@==:                \n"
          "   :@=@-:@=@+     @#..           @      .@     #@:@=     %%...                \n"
          "    @%  #@@      @%+          *@##   .@+     .@@#      %@*                \n";                                                                              
       Sleep(1000);
       system("cls");
       cout<<"\n\n\n\n\n\n\n\n"                                                                                                                                                                   
            ":+   +=   +:   :++++.         :+        -+++-     +:   -=    ++++-            \n"           
            ".@+ =@@- +@    =@-..          =@:     .@. :%%    *@. .@=    @..             \n"            
            " @ %+#% @=    =@#+          =@:     =@:   @.    @ ##     @%**.            \n"           
            " .@#@ :@#@     =@-..          =@-..   :@. :@#     -@@.     @*..             \n"            
            "  -+-  =+:     :++++.         :++++    .=+++:       =+-      ++++-            \n";           
    	Sleep(1000);
       	system("cls");
		   cout<<"\n\n\n\n\n\n\n\n"                                                                        
                ":-   :-.  .-.    -----           --       --     -----                    \n"                    
                ":@+  %@#  *@    .@#---           @@       %@     @%---                    \n"                   
                " #@ =@+@-.@=    .@%*-           @@       %@     @@*=                    \n"                    
                " :@+@+ %%+%     .@*              @@       %@     @%                       \n"                      
                "  #@@. -@@=     .@%##*           %@##*    %@     @@###.                   \n"    ; 
		Sleep(500);
		system("cls");                                                                             
	cout<<"                                  .:::::.   \n"<<                                
          "                                .----------.\n"                                   
          "                              .---==--------:\n"                                  
          "                              :-=======-------:\n"                                 
          "                            -========---------.\n"                                
          "                            ---========---------.\n"                               
          "                          .-----========---------:\n"                              
          "                        .--------------------------.\n"                            
          "                      .:----------------------------:.\n"                          
          "                    .:---------------------------------.\n"                        
          "                 .:-------====+++++++**++++++++====------.\n"                      
          "                --===++*#####%%%%%%%%%%%%%%%%%##%###*++-.                  *  -#:    -###+.    .#-   #+       *  .##   #-    #+    -#*.  #=     @%\n"                    
          "              .-=+#%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%##=                 :@:@=    =@=  .%@    .@+   @       =@- @@= +@.    @    =@#@: @+     %%\n"                   
          "             .+#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%##-                 :@@=     #@    +@:   .@+   @        %#.@-#% @+     @*    =@.*@:@+     %#\n"                  
          "             :#%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%#:                  #@      =@..-@#     @%:.=@=        -@%% :@#@      @*    =@  +@@+     ++\n"                  
          "              +#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@%%##*+-                    -+       .=++=:       =++=:          =+:  =+-      +-    :+   -+:     ==\n"                    
          "               :+#%@@@@@@@@@@@@@@@@@@@@@@@@@%####%@@@*:.\n"                        
          "                 .##%%@@%%%%%%%%%%@@%%%%%%%%==+#%%*.\n"                          
          "            .     .=*#%%%%%%%%%%%%%###+##*=--=+-\n"                            
          "            .+#+.  .-+*######%%###++=#%###=.\n"                            
          "            .+%#-         :+*#########*%%%#*+\n"                             
          "             +%%=:- .       .-+**##########+:\n"                             
          "             =%%=.++--        =######**+-:.\n"                               
          "          .=+#%%+  .=#+=-==###*##%%#=\n"                                         
          "         :++##%#%=    %%%%#*#%######+-.\n"                                       
          "         +#%%%%%%+   =%%%++*###**++---\n"                                      
          "         +#%%%%@@@#. +%#+*#%##**++++==--=.\n"                                    
          "          +#%@@@@@#..+*+-@@%%#++++=-=+-.\n"                                  
          "           :=##=.:+#-   +%@@%%##+++++:.=+-.\n"                               
          "                  :+=     *#%%%###+===+=  :++-.\n"                             
          "              .:=+#:    :+########++++=.   -===-:.\n"                          
          "           .-+*#%#.    =+*######**+++++.  .++=+++=-.\n"                        
          "           -###%%:  :--==++++++*+++++=.  :=  .**==\n"                        
          "          .=#%#=.    .------=====++++++===.   --   .#+.\n"                       
          "           -++-         -=-------========-.          ##:\n"                        
          "                    :---=======---=++++=.            .:\n"                         
          "                  .==+++++++++====--=+-\n"                                         
          "                 .=++*+-=++++=+==--.\n"                                          
          "                .=++++++=.  :-=======.\n"                                          
          "                -=++++++=--.   ......\n"                                           
          "                +*+++++=-.     .::--:.::---:.\n"                                  ;
          Sleep(4000);
}
int main(){
	int LevelNo;
	int le1,le2,le3;
	Start:
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
				}
				goto Level1con;
			}
			else{cout<<"You Win"<<endl;
			le1=1;
				if(le1==1&&le2==1&&le3==1){
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
				}
				goto Level2con;
			}
			else{cout<<"You Win"<<endl;
			le2=1;
				if(le1==1&&le2==1&&le3==1){
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
				}
				goto Level3con;
			}
			else{cout<<"You Win"<<endl;
			le3=1;
				if(le1==1&&le2==1&&le3==1){
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
