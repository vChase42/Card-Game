//cards.h
//Authors: Chase Alcorn, Andy Wu
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <ostream>

using namespace std;

//struct for node Card
struct Card
{
    Card* next;
	string data;
    
    Card(string c = ""): data(c), next(nullptr) {}

    bool operator==(Card c) const; //boolean operator to compare data of card to a given card value
};

class CardList {
public:
    //Constructors
	CardList(); //Empty List constructor
    CardList(ifstream& file); //creates linkedlist given file

  
    ~CardList(); //Destructor

    //mutators functions
    void append(const string c); //adds card c to end of list
    void remove(const int n);     //removes card at index n
    bool search_remove(const string c);   //removes first card that matches the given string, returns true if successful

    //accessor functions
    friend ostream& operator<<(ostream& out, CardList& list); //output remaining cards in list
    bool empty() const;          //returns true if empty, false if not empty
    string at(const int n) const;   //returns card at index n
    int size() const;               //returns size of list

private:
	Card* head;

};


class Player {
public:
	Player(string n, ifstream& file); //constructor, pass in a name string and a file to initialize CardList

    //mutator member function
    bool turn(Player& p); //executes code for a player's turn, returns false if no more cards left


    //accessor member function
    void print(); //print name and current cards


private:
	string name;
    CardList cards;
    int currCard;
};





#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
