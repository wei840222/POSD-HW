hw2: mainTerm

mainTerm: mainTerm.o
	g++ -o hw2 mainTerm.o -lgtest -lpthread

mainTerm.o: mainTerm.cpp include/Atom.h include/Number.h include/Variable.h
	g++ -std=c++11 -c mainTerm.cpp

clean:
	rm -f *.o hw2
stat:
	wc *.h *.cpp