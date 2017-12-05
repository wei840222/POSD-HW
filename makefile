hw7: struct.o list.o term.o utIterator.h iterator.h atom.h number.h variable.h
ifeq (${OS}, Windows_NT) 
	g++ -std=gnu++0x -c hw7.cpp 
	g++ -o hw7 hw7.o struct.o list.o term.o -lgtest 
else
	make utIterator.o
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

utAtom: utAtom.o term.o
	g++ -o utAtom utAtom.o term.o -lgtest -lpthread
utAtom.o: utAtom.h atom.h
	touch utAtom.cpp
	echo '#include "utAtom.h"' > utAtom.cpp
	cat utTemplate.h >> utAtom.cpp
	g++ -c utAtom.cpp

utTerm: utTerm.o term.o
	g++ -o utTerm utTerm.o term.o -lgtest -lpthread
utTerm.o: utTerm.h term.h
	touch utTerm.cpp
	echo '#include "utTerm.h"' > utTerm.cpp
	cat utTemplate.h >> utTerm.cpp
	g++ -c utTerm.cpp

utVariable: utVariable.o term.o struct.o list.o
	g++ -o utVariable utVariable.o term.o struct.o list.o -lgtest -lpthread
utVariable.o: utVariable.h term.h atom.h number.h variable.h struct.h
	touch utVariable.cpp
	echo '#include "utVariable.h"' > utVariable.cpp
	cat utTemplate.h >> utVariable.cpp
	g++ -c utVariable.cpp

utStruct: utStruct.o term.o struct.o
	g++ -o utStruct utStruct.o term.o struct.o -lgtest -lpthread
utStruct.o: utStruct.h term.h atom.h number.h variable.h struct.h
	touch utStruct.cpp
	echo '#include "utStruct.h"' > utStruct.cpp
	cat utTemplate.h >> utStruct.cpp
	g++ -c utStruct.cpp

utList: utList.o term.o struct.o list.o
	g++ -o utList utList.o term.o struct.o list.o -lgtest -lpthread
utList.o: utList.h term.h atom.h number.h variable.h struct.h list.h
	touch utList.cpp
	echo '#include "utList.h"' > utList.cpp
	cat utTemplate.h >> utList.cpp
	g++ -c utList.cpp

utScanner: utScanner.o
	g++ -o utScanner utScanner.o -lgtest -lpthread
utScanner.o: utScanner.h scanner.h
	touch utScanner.cpp
	echo '#include "utScanner.h"' > utScanner.cpp
	cat utTemplate.h >> utScanner.cpp
	g++ -c utScanner.cpp

utParser: utParser.o term.o struct.o list.o
	g++ -o utParser utParser.o term.o struct.o list.o -lgtest -lpthread
utParser.o: utParser.h parser.h scanner.h node.h term.h atom.h number.h variable.h struct.h list.h
	touch utParser.cpp
	echo '#include "utParser.h"' > utParser.cpp
	cat utTemplate.h >> utParser.cpp
	g++ -c utParser.cpp

utIterator: utIterator.o term.o struct.o list.o
	g++ -o utIterator utIterator.o term.o struct.o list.o -lgtest -lpthread
utIterator.o: utIterator.h iterator.h term.h atom.h number.h variable.h struct.h list.h
	touch utIterator.cpp
	echo '#include "utIterator.h"' > utIterator.cpp
	cat utTemplate.h >> utIterator.cpp
	g++ -c utIterator.cpp


#####Object file#####

term.o: term.cpp term.h 
	g++ -c term.cpp

struct.o: struct.cpp struct.h 
	g++ -c struct.cpp

list.o: list.cpp list.h 
	g++ -c list.cpp


clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o ut*[!.h] hw*
endif