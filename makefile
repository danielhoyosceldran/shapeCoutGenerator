# makefile per al coutGenerator
coutGenerator: main.o coutGenerator.o
	g++ -o coutGenerator main.o coutGenerator.o

main.o: main.cpp coutGenerator.h
	g++ -c main.cpp

coutGenerator.o: coutGenerator.cpp coutGenerator.h
	g++ -c coutGenerator.cpp

clean:
	del coutGenerator.exe *.o