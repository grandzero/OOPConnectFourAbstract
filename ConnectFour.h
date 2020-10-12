#ifndef connectFour
#define connectFour
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<limits.h>
#include "Cell.h"

using namespace std;


namespace gtu{


class ConnectFour{

     protected:
       
        static int livingCell;
        int height;
        int width;
        int moveCounter=0;
        char column;
        string filename;
        string input;
        string inputCommand;
        int tempSize;
        int lastMove[1][2];
        bool finished=false;
        /**Checker functions**/
       bool checkColumn() const;
        bool checkRow() const;
        bool isSizeLegal(const int height,const int width) const{return (height<=0||width<=0);}
        /***End of checkers***/
        /**Play Funcitons**/
        void addMoveToBoard();
        void play();
        void play(char choice);
        void undoMove();
        void transformBoard();
        /**End of Play Functions**/
        /**Save And Read Functions**/
        void read();
        void write() const;
        Cell ** gameBoard;
        /*********************/
	/*Checks the if input file ended*/
	
    public:

        ConnectFour();
        ConnectFour(int);
        ConnectFour(int,int);
        ConnectFour(const ConnectFour&);
        ConnectFour(string);
        ~ConnectFour(){for(int i=0;i<height;++i)delete[] gameBoard[i];delete[] gameBoard;}
        ConnectFour & operator =(const ConnectFour &);
        bool isFinished() const;//++
        void setGameCells();//++
        void printGame() const;//++
        void playGame();
        int getCurrentHeight() const {return height;}
        int getCurrentWidth() const {return width;}
        bool getFinished() const {return finished;}
        int getMoveCounter() const {return moveCounter;}
        static int getLivingCell();
       bool compare(const ConnectFour&) const;

};


}




#endif
