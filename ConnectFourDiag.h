#ifndef connectFourDiag
#define connectFourDiag
#include "ConnectFour.h"



namespace gtu{

	class ConnectFourDiag : public ConnectFour{

	public:
		ConnectFourDiag();
        	ConnectFourDiag(int);
        	ConnectFourDiag(int,int);
       	 	ConnectFourDiag(const ConnectFour&);
        	ConnectFourDiag(string);
        	ConnectFourDiag & operator =(const ConnectFourDiag &);
		bool isFinished() const;

	};
}


#endif
