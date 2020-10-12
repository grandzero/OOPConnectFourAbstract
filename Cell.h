#ifndef Cel
#define Cel
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<limits.h>
using namespace std;

namespace gtu{

 class Cell{
            public:
                Cell();
                void setCell(char newCell){ cell=newCell;}
                void setRow(int newRow){ row=newRow;}
                void setValue(char newValue) {value=newValue;}
                char getValue() const {return value;}
                char getCell() const {return cell;}
                int getRow() const {return row;}
                
		bool operator ==(const Cell &) const;
		
            private:
                char cell;
                int row;
                char value;/*Value can be "X","O"(if game ended it may be lover case) or '.'*/


        };


}

#endif
