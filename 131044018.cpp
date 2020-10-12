#include<iostream>
#include <stdlib.h>
#include "Cell.h"
#include "ConnectFour.h"
#include "ConnectFourPlus.h"
#include "ConnectFourDiag.h"
#include "ConnectFourUndo.h"
using namespace std;
using namespace gtu;
void checkEnd();//checks if input file is ended
int main(){
    //{ConnectFourPlus b(5,5);}
    int obj=0;
    int i = 0;
    string gameMode;
    bool isGameEnd = false;
    cout<<"WELCOME TO CONNECTFOUR GAME !!! "<<endl;
    cout<<"Please choose the Object(Plus or Diag or Undo)"<<endl;
    getline(cin,gameMode);
    bool exp=gameMode.size()==1&&gameMode[0]=='P'||gameMode[0]=='D'||gameMode[0]=='p'||gameMode[0]=='d'
				||gameMode[0]=='U'||gameMode[0]=='u';
    while(!exp){
        cout<<"Wrong input please enter correct input.You must choose S(single) or M(multi): "<<endl;
        getline(cin,gameMode);
        exp=gameMode.size()==1&&gameMode[0]=='P'||gameMode[0]=='D'||gameMode[0]=='p'||gameMode[0]=='d'
				||gameMode[0]=='U'||gameMode[0]=='u';
    }
    if(gameMode[0]=='p'||gameMode[0]=='P'){
        int wid,he;
	checkEnd();
        cin>>wid;
	checkEnd();
	cin>>he;
        ConnectFourPlus single(he,wid);
        single.printGame();
	
        while(!isGameEnd){
	    checkEnd();
            single.playGame();
            checkEnd();
	    isGameEnd=single.isFinished();
		}
        if(single.getMoveCounter()%2==1)
            cout<<"WINNER IS PLAYER 2"<<endl;
        else
            cout<<"WINNER IS PLAYER 1"<<endl;
    }else if(gameMode[0]=='d'||gameMode[0]=='D'){
    	 int wid,he;
	checkEnd();
        cin>>wid;
	checkEnd();
	cin>>he;
        ConnectFourDiag single(he,wid);
        single.printGame();

        while(!isGameEnd){
    	    checkEnd();
            single.playGame();
            checkEnd();
	    isGameEnd=single.isFinished();
	}
        if(single.getMoveCounter()%2==1)
            cout<<"WINNER IS PLAYER 2"<<endl;
        else
            cout<<"WINNER IS PLAYER 1"<<endl;
    }else{
	int wid,he;
	checkEnd();
        cin>>wid;
	checkEnd();
	cin>>he;
        ConnectFourUndo single(he,wid);
	
        single.printGame();

        while(!isGameEnd){
    	    checkEnd();
            single.playGame();	
            checkEnd();
	    isGameEnd=single.isFinished();
	}
        if(single.getMoveCounter()%2==1)
            cout<<"WINNER IS PLAYER 2"<<endl;
        else
            cout<<"WINNER IS PLAYER 1"<<endl;
	}	
    return 0;

}
/*This function checks if input file ended.*/
void checkEnd(){
	if(cin.eof())
		exit(0);
	if(cin.peek()==EOF||cin.peek()==-1)
		exit(0);
}

