#include "ConnectFour.h"
#include "ConnectFourDiag.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<limits.h>
using namespace std;


namespace gtu{

ConnectFourDiag::ConnectFourDiag():ConnectFour() {/*Intentionaly leaved blank*/}
ConnectFourDiag::ConnectFourDiag(int i) : ConnectFour(i) {/*Intentionaly leaved blank*/}
ConnectFourDiag::ConnectFourDiag(int i,int k):ConnectFour(i,k) {/*Intentionaly leaved blank*/}
ConnectFourDiag::ConnectFourDiag(const ConnectFour& other):ConnectFour(other) {/*Intentionaly leaved blank*/}
ConnectFourDiag::ConnectFourDiag(string val):ConnectFour(val) {/*Intentionaly leaved blank*/}
ConnectFourDiag & ConnectFourDiag::operator =(const ConnectFourDiag & other){
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
bool ConnectFourDiag::isFinished() const{
	for(int i=0;i<height-3;++i){
        for(int j=0;j<width-3;++j){
            if(gameBoard[i][j].getValue()=='X'&&gameBoard[i+1][j+1].getValue()=='X'
                &&gameBoard[i+2][j+2].getValue()=='X'&&gameBoard[i+3][j+3].getValue()=='X'){
                    //cout<<"PLAYER 1 WON"<<endl;
                    return true;
                    }
            else if(gameBoard[i][j].getValue()=='O'&&gameBoard[i+1][j+1].getValue()=='O'
                    &&gameBoard[i+2][j+2].getValue()=='O'&&gameBoard[i+3][j+3].getValue()=='O'){
                        //cout<<"PLAYER 2 WON"<<endl;
                        return true;
                        }
            }
        }

    for(int i=0;i<height-3;++i){
        for(int j=3;j<width;++j){
            if(gameBoard[i][j].getValue()=='X'&&gameBoard[i+1][j-1].getValue()=='X'
                &&gameBoard[i+2][j-2].getValue()=='X'&&gameBoard[i+3][j-3].getValue()=='X'){
                    //cout<<"PLAYER 1 WON"<<endl;
                    return true;
                    }
            else if(gameBoard[i][j].getValue()=='O'&&gameBoard[i+1][j-1].getValue()=='O'
                    &&gameBoard[i+2][j-2].getValue()=='O'&&gameBoard[i+3][j-3].getValue()=='O'){
                        //cout<<"PLAYER 2 WON"<<endl;
                        return true;
                        }
            }
        }

    return false;


}

}
