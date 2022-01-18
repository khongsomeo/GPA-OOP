output: main.o
	g++ main.o -o main

main.o: src/main.cpp
	g++ -c src/main.cpp

clean:
	rm *.o main tests/main

init_test:
	cp main tests/main

test:
	cd tests && pwd && bash test.sh
