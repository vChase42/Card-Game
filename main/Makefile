# Makefile

testcards: testcards.o cards.o
	g++ testcards.o cards.o -o testcards 
testcards.o: testcards.cpp
	g++ -c testcards.cpp

cards.o: cards.cpp
	g++ -c cards.cpp

clean:
	rm *.o testcards
