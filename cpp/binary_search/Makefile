
default: main.o 
	g++ main.o -o a.out

main.o: main.cpp array.hpp
	g++ -Wall -c -x c++ -std=c++11 -O3 main.cpp -o main.o

debug: main.o-debug 
	g++ main.o-debug -o a.out-debug

main.o-debug: main.cpp 
	g++ -Wall -c -x c++ -std=c++11 -g main.cpp -o main.o-debug

clean:
	rm -f *.o *.out *.exe *-debug 
