utTerm: mainTerm.o
	g++ -o utTerm mainTerm.o -lgtest -lpthread

mainTerm.o: mainTerm.cpp utTerm.h atom.h number.h variable.h
	g++ -std=gnu++0x -c mainTerm.cpp

utStructure: mainStructure.o
	g++ -o utStructure mainStructure.o -lgtest -lpthread

mainStructure.o: mainStructure.cpp utStructure.h atom.h number.h variable.h structure.h
	g++ -std=gnu++0x -c mainStructure.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o utTerm utStructure
endif

# hw2: mainTerm.o
# ifeq (${OS}, Windows_NT)
# 	g++ -o hw2 mainTerm.o -lgtest
# else
# 	g++ -o hw2 mainTerm.o -lgtest -lpthread
# endif