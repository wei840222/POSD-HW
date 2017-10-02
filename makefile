CPP = g++ -std=c++11
INC = ./include/

hw2: mainTerm.o
	${CPP} -o hw2 mainTerm.o -lgtest -lpthread

mainTerm.o: mainTerm.cpp
	${CPP} -c mainTerm.cpp

clean:
	rm -f *.o hw2