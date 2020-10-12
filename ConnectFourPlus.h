#ifndef connectFourPlus
#define connectFourPlus
#include "ConnectFour.h"



namespace gtu{

	class ConnectFourPlus : public ConnectFour{

	public:
		ConnectFourPlus();
        	ConnectFourPlus(int);
        	ConnectFourPlus(int,int);
       	 	ConnectFourPlus(const ConnectFour&);
        	ConnectFourPlus(string);
        	ConnectFourPlus & operator =(const ConnectFourPlus &);
		bool isFinished() const;

	};
}


#endif
