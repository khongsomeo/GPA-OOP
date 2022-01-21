CXX=g++
CXXFLAGS=-Wall -std=c++17

main: main.o CommandLineParser.o InputHelper.o OutputHelper.o \
	Utility.o Grade.o Subject.o PersonalGPA.o PersonalExcept.o \
	PersonalSpecific.o PersonalFactory.o
	$(CXX) $(CXXFLAGS) main.o CommandLineParser.o InputHelper.o OutputHelper.o \
		Utility.o Grade.o Subject.o PersonalGPA.o PersonalExcept.o \
		PersonalSpecific.o PersonalFactory.o -o main

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o main tests/main

init_test:
	cp main tests/main

test:
	cd tests && pwd && bash test.sh
