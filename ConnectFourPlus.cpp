#include "ConnectFour.h"
#include "ConnectFourPlus.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<limits.h>
using namespace std;


namespace gtu{

ConnectFourPlus::ConnectFourPlus():ConnectFour() {/*Intentionaly leaved blank*/}
ConnectFourPlus::ConnectFourPlus(int i) : ConnectFour(i) {/*Intentionaly leaved blank*/}
ConnectFourPlus::ConnectFourPlus(int i,int k):ConnectFour(i,k) {/*Intentionaly leaved blank*/}
ConnectFourPlus::ConnectFourPlus(const ConnectFour& other):ConnectFour(other) {/*Intentionaly leaved blank*/}
ConnectFourPlus::ConnectFourPlus(string val):ConnectFour(val) {/*Intentionaly leaved blank*/}
ConnectFourPlus & ConnectFourPlus::operator =(const ConnectFourPlus & other){
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
bool ConnectFourPlus::isFinished() const{
	if(moveCounter==height*width)
        return true;

    if(checkRow()||checkColumn())
        return true;

    return false;


}

}
