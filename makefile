CPP = g++ -std=c++11 -c
INC = ./include

hw2: mainTerm.o
	g++ -o hw2 mainTerm.o -lgtest -lpthread

mainTerm.o: utTerm.h mainTerm.cpp
	${CPP} mainTerm.cpp

clean:
	rm -f *.o hw2