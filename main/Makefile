# Makefile
all: testcards cards

testcards: testcards.o cards.o
	g++ testcards.o cards.o -o testcards 

cards: cards.o main.o
	g++ cards.o main.o -o cards 
  
testcards.o: testcards.cpp
	g++ -c testcards.cpp

cards.o: cards.cpp
	g++ -c cards.cpp

main.o: main.cpp
	g++ -c main.cpp
  
clean:
	rm *.o testcards cards
