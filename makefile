hw6: mainParser.o
ifeq (${OS}, Windows_NT)
	g++ -o hw6 mainParser.o -lgtest
else
	g++ -o hw6 mainParser.o -lgtest -lpthread
endif

allTest: utAtom utTerm utVariable utStruct utList utScanner utParser
	./utAtom
	./utTerm
	./utVariable
	./utStruct
	./utList
	./utScanner
	./utParser

utAtom: mainAtom.o
	g++ -o utAtom mainAtom.o -lgtest -lpthread
mainAtom.o: mainAtom.cpp utAtom.h atom.h
	g++ -std=c++11 -c mainAtom.cpp

utTerm: mainTerm.o
	g++ -o utTerm mainTerm.o -lgtest -lpthread
mainTerm.o: mainTerm.cpp utTerm.h term.h atom.h number.h variable.h
	g++ -std=gnu++0x -c mainTerm.cpp

utVariable: mainVariable.o
		g++ -o utVariable mainVariable.o  -lgtest -lpthread
mainVariable.o: mainVariable.cpp utVariable.h term.h atom.h number.h variable.h struct.h
		g++ -std=c++11 -c mainVariable.cpp

utStruct: mainStruct.o
	g++ -o utStruct mainStruct.o -lgtest -lpthread
mainStruct.o: mainStruct.cpp utStruct.h term.h atom.h number.h variable.h struct.h
	g++ -std=gnu++0x -c mainStruct.cpp

utList: mainList.o
	g++ -o utList mainList.o -lgtest -lpthread
mainList.o: mainList.cpp utList.h term.h atom.h number.h variable.h struct.h list.h
	g++ -std=gnu++0x -c mainList.cpp

utScanner: mainScanner.o
	g++ -o utScanner mainScanner.o -lgtest -lpthread
mainScanner.o: mainScanner.cpp utScanner.h scanner.h
	g++ -std=gnu++0x -c mainScanner.cpp

utParser: mainParser.o
	g++ -o utParser mainParser.o -lgtest -lpthread
mainParser.o: mainParser.cpp utParser.h parser.h scanner.h term.h atom.h number.h variable.h struct.h list.h
	g++ -std=gnu++0x -c mainParser.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o ut*[!.h] hw*
endif