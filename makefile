C=g++ -std=gnu++0x
INC_DIR = include

all: hw1

hw1: main.o Media.o Shapes.o Sort.o
ifeq (${OS}, Windows_NT)
	$C -o hw1 main.o Media.o Shapes.o Sort.o -lgtest
else
	$C -o hw1 main.o Media.o Shapes.o Sort.o -lgtest -lpthread
endif

main.o: main.cpp utSort.h
	$C -c main.cpp
Media.o: Media.cpp $(INC_DIR)/Media.h
	$C -c Media.cpp
Shapes.o: Shapes.cpp $(INC_DIR)/Shapes.h
	$C -c Shapes.cpp
Sort.o: Sort.cpp $(INC_DIR)/Sort.h
	$C -c Sort.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw1
endif

