#include "ConnectFourUndo.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<limits.h>
using namespace std;


namespace gtu{

ConnectFourUndo::ConnectFourUndo():ConnectFour() {/*Intentionaly leaved blank*/}
ConnectFourUndo::ConnectFourUndo(int i) : ConnectFour(i) {/*Intentionaly leaved blank*/}
ConnectFourUndo::ConnectFourUndo(int i,int k):ConnectFour(i,k) {/*Intentionaly leaved blank*/}
ConnectFourUndo::ConnectFourUndo(const ConnectFour& other):ConnectFour(other) {/*Intentionaly leaved blank*/}
ConnectFourUndo::ConnectFourUndo(string val):ConnectFour(val) {/*Intentionaly leaved blank*/}
ConnectFourUndo & ConnectFourUndo::operator =(const ConnectFourUndo & other){
	 if(this==&other)
        return *this;
    height=other.height;
    width = other.width;
    moveCounter=other.moveCounter;
    column=other.column;
    filename=other.filename;
    input=other.input;
    inputCommand=other.inputCommand;
    tempSize=other.tempSize;
    lastMove[0][0]=other.lastMove[0][0];
    lastMove[0][1]=other.lastMove[0][1];
    finished = other.finished;
    for(int i=0;i<height;++i)
        delete[] gameBoard[i];
    delete[] gameBoard;
    gameBoard = new Cell*[height];
    for(int i=0;i<height;++i)
        gameBoard[i] = new Cell[width];
    for(int i=0;i<height;++i){
        for(int j=0;j<width;++j)
            gameBoard[i][j]=other.gameBoard[i][j];
    }

}
/*Played moves added to vector at the end of add function*/
void ConnectFourUndo::addMoveToBoard(){

    int i=0;
    int k = column-'A';
    char a;
    if(moveCounter%2==0)
        a='O';
    else
        a='X';
    while(i<height){
        if(gameBoard[i][k].getValue()!='.'&&gameBoard[i][k].getValue()!=' '){
            gameBoard[i-1][k].setValue(a);
            lastMove[0][0]=i-1;
            lastMove[0][1]=k;
            i=height+1;
        }else if(i==height-1&&gameBoard[i][k].getValue()=='.'){
            gameBoard[i][k].setValue(a);
            lastMove[0][0]=i;
            lastMove[0][1]=k;
            i=height+1;
	}
	++i;
    }
    ++moveCounter;
    ++livingCell;
    
    moves.push_back(column);//Last index is last played column
   
}

/*Modify the play functions for command UNDO*/
void ConnectFourUndo::play(){
        int k=0;
	cout<<"Enter the move(If you enter SAVE board will be saved) : "<<endl;
	cin>>input;
	if(cin.eof())
		exit(0);
	if(input[0]=='U'&&input[1]=='N'&&input[2]=='D'&&input[3]=='O'){
	/*If input == UNDO looks last played move*/
	/*Changes that columns last move and pops that move from vector*/
	/*And decreases movecounter*/
	char tempMove;
	tempMove=moves[moves.size()-1];
	/*****************Removing Move**********************/
	int i=0;
    	int t = tempMove-'A';	
	while(i<height){
	/*Checks from upside to down*/
        if(gameBoard[i][t].getValue()!='.'){
	    /*If it is not '.' character than its the last played char*/
	    /*Changes that character to '.'*/
            gameBoard[i][t].setValue('.');
            i=height+1;
        }
	++i;
   	}
	/****************************************************/
	moves.pop_back();
	--moveCounter;
	
	}else{
        if(input[0]=='S'&&input[1]=='A'&&input[2]=='V'&&input[3]=='E'){

	    getline(cin,input);
	    for(int i=0;i<input.length();++i){
		if(input[i]!=' '||input[i]!='\0'){
			filename[k]=input[i];	
			++k;
			}
			
		}
	    k=0;
            write();
            cout<<"Game Succesfully SAVED. Please enter move"<<input<<endl;
	   
            cin>>input;
	    
	
        }
        else if(input[0]=='L'&&input[1]=='O'&&input[2]=='A'&&input[3]=='D'){
	    getline(cin,input);
	   
	    for(int i=0;i<input.length();++i){
		if(input[i]!=' '||input[i]!='\0'){
			filename[k]=input[i];	
			++k;
			}
		
		}
	    k=0;
            read();
            cout<<"Game Succesfully LOADED. Please enter move"<<endl;
	    
            cin>>input;	 
	    
        }
	
        column=toupper(input[0]);
        while(column<'A'||column>'A'+width){
            cout<<"You entered invalid move please enter valid move : "<<endl;
            cin>>input;
            column=toupper(input[0]);
        }
        addMoveToBoard();
        cout<<"livingCell: "<< ConnectFour::getLivingCell()<<endl;
        printGame();
	}/*End of if command!= UNDO*/
        if(isFinished()){
            cout<<"GAME OVER"<<endl;
            moveCounter=1;
        }else{

        int index=0,index2=0;
        int i = 0,j=0;
        int priorityMove;
        bool winningMove=false;
        /*Checks if cpu can finish*/
        while(i<width){
            column=i+65;
            addMoveToBoard();
            if(isFinished()&&moveCounter%2==0){
                    index=i;
                    i=width+5;
                    priorityMove=1;
                    winningMove=true;
            }

            undoMove();
        ++i;
        }
        /*Checks is user finish next move and try to prevent it*/
        ++moveCounter;
        while(j<width){
            column=j+65;
            addMoveToBoard();

            if(isFinished()&&moveCounter%2==0){
                    index2=j;
                    j=width+5;
                    priorityMove=2;
            }
        undoMove();
        ++j;

        }
        --moveCounter;
        if(priorityMove==1||winningMove){
            column = index+65;
            addMoveToBoard();
        }else if(priorityMove==2){
            column = index2+65;
            addMoveToBoard();
        }else{
        //Random move according to moveCount
        column=(moveCounter%width)+65;
        addMoveToBoard();
        }
        cout<<"livingCell: "<<ConnectFour::getLivingCell()<<endl;
        printGame();
        if(isFinished()){
        cout<<"GAME OVER"<<endl;
        moveCounter=2;
        }
        }


}

/*******End of CPU plays*********/

/*User to User Play*/
void ConnectFourUndo::play(char a){
	
	int k=0;
	cout<<"Enter the move(If you enter SAVE board will be saved) : "<<endl;
	cin>>input;
	if(cin.eof())
		exit(0);
	
	if(input[0]=='U'&&input[1]=='N'&&input[2]=='D'&&input[3]=='O'){
	/*If input == UNDO looks last played move*/
	/*Changes that columns last move and pops that move from vector*/
	/*And decreases movecounter*/
	char tempMove;
	tempMove=moves[moves.size()-1];
	/*****************Removing Move**********************/
	int i=0;
    	int t = tempMove-'A';	
	while(i<height){
	/*Checks from upside to down*/
        if(gameBoard[i][t].getValue()!='.'){
	    /*If it is not '.' character than its the last played char*/
	    /*Changes that character to '.'*/
            gameBoard[i][t].setValue('.');
            i=height+1;
        }
	++i;
   	}
	
	/****************************************************/
	moves.pop_back();
	--moveCounter;
	printGame();
	}else{
        if(input[0]=='S'&&input[1]=='A'&&input[2]=='V'&&input[3]=='E'){

	    getline(cin,input);
	    for(int i=0;i<input.length();++i){
		if(input[i]!=' '||input[i]!='\0'){
			filename[k]=input[i];	
			++k;
			}
			
		}
	    k=0;
            write();
            cout<<"Game Succesfully SAVED. Please enter move"<<input<<endl;
	   
            cin>>input;
	    
	
        }
        else if(input[0]=='L'&&input[1]=='O'&&input[2]=='A'&&input[3]=='D'){
	    getline(cin,input);
	   
	    for(int i=0;i<input.length();++i){
		if(input[i]!=' '||input[i]!='\0'){
			filename[k]=input[i];	
			++k;
			}
		
		}
	    k=0;
            read();
            cout<<"Game Succesfully LOADED. Please enter move"<<endl;
	    
            cin>>input;	
	    
	    
        }
/*******************************************************************/
   
    column=toupper(input[0]);
    addMoveToBoard();
    cout<<"livingCell: "<<ConnectFour::getLivingCell()<<endl;
    printGame();
    if(isFinished()){
            cout<<"GAME OVER"<<endl;
    }
	}/*End Of if command !=UNDO*/
}
void ConnectFourUndo::playGame(){
    if(moveCounter==0){
    cout<<"If  you want to play user vs user enter P "
        <<"If you want to play user vs cpu enter C "<<endl;
    cin>>inputCommand;
    bool inputTrue = inputCommand.size()<2||inputCommand.size()>0
          &&inputCommand[0]=='C'||inputCommand[0]=='P'||inputCommand[0]=='c'||inputCommand[0]=='p';
    while(!inputTrue){
        cerr<<"Wrong input !! Please correct your choice "<<endl;
        cin>>inputCommand;
    }
    ++moveCounter;
    }else{
    if(inputCommand[0]=='P'||inputCommand[0]=='p'&&cin.peek()!=cin.eof())
        play('p');
    else if(inputCommand[0]=='c'||inputCommand[0]=='C'&&cin.peek()!=cin.eof())
        play();
    }
}



}/*End of namespace*/
