CPP = g++ -std=c++11

hw2: mainTerm

mainTerm: mainTerm.o
	${CPP} -o hw2 mainTerm.o -lgtest -lpthread

mainTerm.o: mainTerm.cpp atom.h number.h variable.h
	${CPP} -c mainTerm.cpp

clean:
	rm -f *.o hw2