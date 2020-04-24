//cards.h
//Authors: Chase Alcorn, Andy Wu
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <string>

using namespace std;

struct Card
{
	Card* next;
	string data;

  Card(string c = "", Card* n = nullptr): data(c), next(n) {}

  bool operator==(Card c) const;
};

class Player {
	Player();

  void turn(Player p);


private:
	string name;
  CardList cards;

};


class CardList {
	CardList();


  ~CardList();

  //mutators functions
  void append(const string c); //adds card c to end of list
  void remove(const int n);     //removes card at index n
  void clear();                //completely empties a list

  //accessor functions
  friend ostream operator<<(CardList list) const; //output remaining cards in list
  bool is_empty() const;          //returns true if empty, false if not empty
  string at(const int n) const;   //returns card at index n
  int size() const;               //returns size of list

private:
	Card* head;
  int size;

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
