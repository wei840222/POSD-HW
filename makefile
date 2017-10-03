hw2: mainTerm

mainTerm: mainTerm.o
	g++ -o hw2 mainTerm.o -lgtest -lpthread

mainTerm.o: mainTerm.cpp include/atom.h include/number.h include/variable.h
	g++ -std=c++11 -c mainTerm.cpp

clean:
	rm -f *.o hw2
stat:
	wc *.h *.cpp