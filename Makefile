CXX=g++
CXXFLAGS=-Wall -std=c++17

main: main.o CommandLineParser.o InputHelper.o OutputHelper.o \
	Utility.o Grade.o Subject.o PersonalGPA.o PersonalExcept.o \
	PersonalSpecific.o PersonalFactory.o
	$(CXX) $(CXXFLAGS) main.o CommandLineParser.o InputHelper.o OutputHelper.o \
		Utility.o Grade.o Subject.o PersonalGPA.o PersonalExcept.o \
		PersonalSpecific.o PersonalFactory.o -o main

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp

CommandLineParser.o: src/CommandLineParser.cpp
	$(CXX) $(CXXFLAGS) -c src/CommandLineParser.cpp

InputHelper.o: src/InputHelper.cpp
	$(CXX) $(CXXFLAGS) -c src/InputHelper.cpp

OutputHelper.o: src/OutputHelper.cpp
	$(CXX) $(CXXFLAGS) -c src/OutputHelper.cpp

Utility.o: src/Utility.cpp
	$(CXX) $(CXXFLAGS) -c src/Utility.cpp

Grade.o: src/Grade.cpp
	$(CXX) $(CXXFLAGS) -c src/Grade.cpp

Subject.o: src/Subject.cpp
	$(CXX) $(CXXFLAGS) -c src/Subject.cpp

PersonalGPA.o: src/PersonalGPA.cpp
	$(CXX) $(CXXFLAGS) -c src/PersonalGPA.cpp

PersonalSpecific.o: src/PersonalSpecific.cpp
	$(CXX) $(CXXFLAGS) -c src/PersonalSpecific.cpp

PersonalExcept.o: src/PersonalExcept.cpp
	$(CXX) $(CXXFLAGS) -c src/PersonalExcept.cpp

PersonalFactory.o: src/PersonalFactory.cpp
	$(CXX) $(CXXFLAGS) -c src/PersonalFactory.cpp

clean:
	rm -f *.o main tests/main

init_test:
	cp main tests/main

test:
	cd tests && pwd && bash test.sh
