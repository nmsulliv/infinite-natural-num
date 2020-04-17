output: main.o longint.o
	g++ main.o longint.o -o output

main.o: main.cpp
	g++ -c main.cpp

longint.o: longint.cpp longint.h
	g++ -c longint.cpp

clean:
	rm *.0 output