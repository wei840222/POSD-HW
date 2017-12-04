hw7: utIterator.o struct.o list.o term.o
ifeq (${OS}, Windows_NT)
	g++ -o hw7 utIterator.o struct.o list.o term.o -lgtest
else
	g++ -o hw7 utIterator.o struct.o list.o term.o -lgtest -lpthread
	./hw7
	make clean
endif


#######UnitTest#######

allTestAndClean: utAtom utTerm utVariable utStruct utList utScanner utParser utIterator
	./utAtom
	./utTerm
	./utVariable
	./utStruct
	./utList
	./utScanner
	./utParser
	./utIterator
	make clean

utAtom: utAtom.o
	g++ -o utAtom utAtom.o -lgtest -lpthread
utAtom.o: utAtom.h atom.h
	touch utAtom.cpp
	echo '#include "utAtom.h"' >> utAtom.cpp
	cat uniTestTemplate.cpp >> utAtom.cpp
	g++ -std=c++11 -c utAtom.cpp

utTerm: utTerm.o
	g++ -o utTerm utTerm.o -lgtest -lpthread
utTerm.o: utTerm.h term.h
	touch utTerm.cpp
	echo '#include "utTerm.h"' >> utTerm.cpp
	cat uniTestTemplate.cpp >> utTerm.cpp
	g++ -std=c++11 -c utTerm.cpp

utVariable: utVariable.o
	g++ -o utVariable utVariable.o -lgtest -lpthread
utVariable.o: utVariable.h term.h atom.h number.h variable.h struct.h
	touch utVariable.cpp
	echo '#include "utVariable.h"' >> utVariable.cpp
	cat uniTestTemplate.cpp >> utVariable.cpp
	g++ -std=c++11 -c utVariable.cpp

utStruct: utStruct.o
	g++ -o utStruct utStruct.o -lgtest -lpthread
utStruct.o: utStruct.h term.h atom.h number.h variable.h struct.h
	touch utStruct.cpp
	echo '#include "utStruct.h"' >> utStruct.cpp
	cat uniTestTemplate.cpp >> utStruct.cpp
	g++ -std=c++11 -c utStruct.cpp

utList: utList.o
	g++ -o utList utList.o -lgtest -lpthread
utList.o: utList.h term.h atom.h number.h variable.h struct.h list.h
	touch utList.cpp
	echo '#include "utList.h"' >> utList.cpp
	cat uniTestTemplate.cpp >> utList.cpp
	g++ -std=c++11 -c utList.cpp

utScanner: utScanner.o
	g++ -o utScanner utScanner.o -lgtest -lpthread
utScanner.o: utScanner.h scanner.h
	touch utScanner.cpp
	echo '#include "utScanner.h"' >> utScanner.cpp
	cat uniTestTemplate.cpp >> utScanner.cpp
	g++ -std=c++11 -c utScanner.cpp

utParser: utParser.o
	g++ -o utParser utParser.o -lgtest -lpthread
utParser.o: utParser.h parser.h scanner.h node.h term.h atom.h number.h variable.h struct.h list.h
	touch utParser.cpp
	echo '#include "utParser.h"' >> utParser.cpp
	cat uniTestTemplate.cpp >> utParser.cpp
	g++ -std=c++11 -c utParser.cpp

utIterator: utIterator.o term.o struct.o list.o
	g++ -o utIterator utIterator.o term.o struct.o list.o -lgtest -lpthread
utIterator.o: utIterator.h iterator.h term.h atom.h number.h variable.h struct.h list.h
	touch utIterator.cpp
	echo '#include "utIterator.h"' >> utIterator.cpp
	cat uniTestTemplate.cpp >> utIterator.cpp
	g++ -std=c++11 -c utIterator.cpp


#####Object file#####

term.o: term.cpp term.h 
	g++ -std=gnu++0x -c term.cpp

struct.o: struct.cpp struct.h 
	g++ -std=gnu++0x -c struct.cpp

list.o: list.cpp list.h 
	g++ -std=gnu++0x -c list.cpp


clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o ut*[!.h] hw*
endif