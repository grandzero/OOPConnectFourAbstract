#ifndef connectFourUndo
#define connectFourUndo
#include "ConnectFour.h"



namespace gtu{

	class ConnectFourUndo : public ConnectFour{

	public:
		ConnectFourUndo();
        	ConnectFourUndo(int);
        	ConnectFourUndo(int,int);
       	 	ConnectFourUndo(const ConnectFour&);
        	ConnectFourUndo(string);
        	ConnectFourUndo & operator =(const ConnectFourUndo &);
		void playGame();
	protected:
		void play();
       	        void play(char choice);
		vector<char> moves;
		void addMoveToBoard();

	};
}


#endif
