all: utAtom utVariable utTerm utStruct

# hw3: mainVariable.o mainStruct.o
# ifeq (${OS}, Windows_NT)
# 	g++ -o hw3 mainVariable.o mainStruct.o -lgtest
# else
# 	g++ -o hw3 mainVariable.o mainStruct.o -lgtest -lpthread
# endif

utAtom: mainAtom.o
	g++ -o utAtom mainAtom.o -lgtest -lpthread
mainAtom.o: mainAtom.cpp utAtom.h atom.h utStruct.h struct.h
	g++ -std=c++11 -c mainAtom.cpp

utVariable: mainVariable.o
		g++ -o utVariable mainVariable.o  -lgtest -lpthread
mainVariable.o: mainVariable.cpp utVariable.h variable.h
		g++ -std=c++11 -c mainVariable.cpp

utTerm: mainTerm.o
	g++ -o utTerm mainTerm.o -lgtest -lpthread
mainTerm.o: mainTerm.cpp utTerm.h atom.h number.h variable.h
	g++ -std=gnu++0x -c mainTerm.cpp

utStruct: mainStruct.o
	g++ -o utStruct mainStruct.o -lgtest -lpthread
mainStruct.o: mainStruct.cpp utStruct.h atom.h number.h variable.h struct.h
	g++ -std=gnu++0x -c mainStruct.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o utAtom utVariable utTerm utStruct
endif