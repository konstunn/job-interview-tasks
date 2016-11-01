
main: main.cpp
	g++ -x c++ -std=c++11 -O2 -Wl,-zstack-size=67108864 main.cpp

check: main.cpp
	g++ -x c++ -fsyntax-only -std=c++11 main.cpp

clean:
	rm -f *.exe *.out *.o
