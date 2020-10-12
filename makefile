all:131044018

131044018:131044018.o
	g++ -o exe 131044018.o ConnectFour.o Cell.o ConnectFourPlus.o ConnectFourDiag.o ConnectFourUndo.o
131044018.o:131044018.cpp
	g++ -c -std=gnu++14 131044018.cpp ConnectFour.cpp ConnectFourPlus.cpp ConnectFourDiag.cpp ConnectFourUndo.cpp Cell.cpp

clean : 
	rm *.o exe

run:
	./exe
