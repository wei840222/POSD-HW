allTest: utAtom utTerm utVariable utStruct utList
	./utAtom
	./utTerm
	./utVariable
	./utStruct
	./utList

utAtom: mainAtom.o
	g++ -o utAtom mainAtom.o -lgtest -lpthread
mainAtom.o: mainAtom.cpp utAtom.h atom.h utStruct.h struct.h
	g++ -std=c++11 -c mainAtom.cpp

utTerm: mainTerm.o
	g++ -o utTerm mainTerm.o -lgtest -lpthread
mainTerm.o: mainTerm.cpp utTerm.h atom.h number.h variable.h
	g++ -std=gnu++0x -c mainTerm.cpp

utVariable: mainVariable.o
		g++ -o utVariable mainVariable.o  -lgtest -lpthread
mainVariable.o: mainVariable.cpp utVariable.h variable.h
		g++ -std=c++11 -c mainVariable.cpp

utStruct: mainStruct.o
	g++ -o utStruct mainStruct.o -lgtest -lpthread
mainStruct.o: mainStruct.cpp utStruct.h atom.h number.h variable.h struct.h
	g++ -std=gnu++0x -c mainStruct.cpp

utList: mainList.o
	g++ -o utList mainList.o -lgtest -lpthread
mainList.o: mainList.cpp utList.h atom.h number.h variable.h struct.h
	g++ -std=gnu++0x -c mainList.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o utAtom utTerm utVariable utStruct utList
endif

# hw3: mainVarAndStruct.o
# ifeq (${OS}, Windows_NT)
# 	g++ -o hw3 mainVarAndStruct.o -lgtest
# else
# 	g++ -o hw3 mainVarAndStruct.o -lgtest -lpthread
# endif