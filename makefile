hw7: term.o struct.o list.o utIterator.h iterator.h atom.h number.h variable.h
ifeq (${OS}, Windows_NT) 
	g++ -c -std=gnu++0x hw.cpp 
	g++ -o hw7 hw.o term.o struct.o list.o -lgtest 
else
	make utIterator.o
	g++ -o hw7 utIterator.o term.o struct.o list.o -lgtest -lpthread
	./hw7
	make clean
endif

#######UnitTest#######
allTestRunAndClean: utAtom utTerm utVariable utStruct utList utScanner utParser utIterator utExp utShell
	./utAtom && ./utTerm && ./utVariable && ./utStruct && ./utList && ./utScanner && ./utParser && ./utIterator && ./utExp && ./utShell
	make clean

utAtom: utAtom.o term.o
	g++ -o $@ $^ -lgtest -lpthread
utAtom.o: utAtom.h atom.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c -std=gnu++0x $*.cpp

utTerm: utTerm.o term.o
	g++ -o $@ $^ -lgtest -lpthread
utTerm.o: utTerm.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c -std=gnu++0x $*.cpp

utVariable: utVariable.o term.o struct.o list.o
	g++ -o $@ $^ -lgtest -lpthread
utVariable.o: utVariable.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c -std=gnu++0x $*.cpp

utStruct: utStruct.o term.o struct.o
	g++ -o $@ $^ -lgtest -lpthread
utStruct.o: utStruct.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c -std=gnu++0x $*.cpp

utList: utList.o term.o struct.o list.o
	g++ -o $@ $^ -lgtest -lpthread
utList.o: utList.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c -std=gnu++0x $*.cpp

utScanner: utScanner.o
	g++ -o $@ $^ -lgtest -lpthread
utScanner.o: utScanner.h scanner.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c -std=gnu++0x $*.cpp

utParser: utParser.o term.o struct.o list.o
	g++ -o $@ $^ -lgtest -lpthread
utParser.o: utParser.h parser.h scanner.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c -std=gnu++0x $*.cpp

utIterator: utIterator.o term.o struct.o list.o
	g++ -o $@ $^ -lgtest -lpthread
utIterator.o: utIterator.h iterator.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c -std=gnu++0x $*.cpp

utExp: utExp.o term.o struct.o list.o
	g++ -o $@ $^ -lgtest -lpthread
utExp.o: utExp.h parser.h scanner.h exp.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c -std=gnu++0x $*.cpp

utShell: utShell.o term.o struct.o list.o
	g++ -o $@ $^ -lgtest -lpthread
utShell.o: expression.h exception.h parser.h scanner.h exp.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"expression.h\"" > $*.cpp && echo "#include \"exception.h\"" >> $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c -std=gnu++0x $*.cpp


#####Object file#####
term.o: term.h
	g++ -c -std=gnu++0x $*.cpp
struct.o: struct.h
	g++ -c -std=gnu++0x $*.cpp
list.o: list.h
	g++ -c -std=gnu++0x $*.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o ut*[!.h] hw*[!.cpp]
endif