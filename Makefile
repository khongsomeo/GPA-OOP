CXX=g++
CXXFLAGS=-Wall -std=c++17

main: main.o
	$(CXX) $(CXXFLAGS) main.o -o main

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp

clean:
	rm *.o main tests/main

init_test:
	cp main tests/main

test:
	cd tests && pwd && bash test.sh
