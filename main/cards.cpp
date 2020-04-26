//cards.cpp
//Chase Alcorn, Andy Wu
//Implementation of the classes defined in cards.h

#include <iostream>
#include <fstream>
#include "cards.h"


using namespace std;
//ALL CARD MEMBER FUNCTIONS

bool Card::operator==(Card c) const{
  return data == c.data;
}

//ALL CARDLIST MEMBER FUNCTIONS


CardList::CardList(ifstream& file) {
    head = nullptr;

    string line;
    while (getline(file, line)) {
        append(line);
    }
}


CardList::~CardList(){
  Card* tmp;
  while(head){
    tmp = head->next;
    delete head;
    head = tmp;
  }
}


void CardList::append(string c){
  if(!head){
    head = new Card(c);
    return;
  }
  recursive_append(head, c);

  //Card* currObj = head;
  //
  //while(currObj->next){
  //  currObj = currObj->next;
  //}

  //currObj->next = new Card(c);
}

void CardList::recursive_append(Card* c, const string s) {
    if (!c->next) {
        c->next = new Card(s);
        return;
    }
    recursive_append(c->next, s);
}


void CardList::remove(const int n){
  if(n>size()){
    cout << "REMOVE() OUT OF RANGE, " << n << " LARGER THAN " << size() << endl;
    return;
  }

  Card* currObj = head;
  for(int i=0;i<n-1;i++){
    currObj = currObj->next;
  }
  Card* temp = currObj->next->next;
  delete currObj->next;
  currObj->next = temp;

}


bool CardList::search_remove(const string c){
  Card* cur = head;
  string output;
  if(!head){
    return false;
  }
  if(head->data == c){
    delete head;
    head = 0;
    return true;
  }
  while(cur->next){
    if(cur->next->data == c){
      Card* tmp = cur->next->next;
      delete cur->next;
      cur->next = tmp;
      return true;
    }
    cur = cur->next;
  }
  return false;
}



string CardList::at(const int n) const{
  if(n>size()){
    cout << "AT() OUT OF RANGE, " << n << " LARGER THAN " << size() << endl;
    return "";
  }

  Card* currObj = head;
  for(int i=0;i<n;i++){
    currObj = currObj->next;
  }

  return currObj->data;
}

int CardList::size() const{
    return recursive_size(head);

  /*Card* currObj = head;
  int count=0;
  while(currObj){
    count++;
    currObj=currObj->next;
  }
  return count;*/
}

int CardList::recursive_size(Card* c) const {
    if (!c) {
        return 0;
    }
    return recursive_size(c->next) + 1;
}


ostream& operator<<(ostream& out, CardList& list){
  for(int i=0;i<list.size();i++){
    out << list.at(i) << endl;
  }
  return out;
}

//ALL PLAYER MEMBER FUNCTIONS

Player::Player(string n, ifstream& file): name(n), cards(file), currCard(0){}

ostream& operator<<(ostream& out, Player& p){
    out << p.name << "'s cards:" << endl << p.cards;
    return out;
}

bool Player::turn(Player& p) {

    for (currCard; currCard < cards.size(); currCard++) {
        if (p.cards.search_remove(cards.at(currCard))) {
            cout << name << " picked matching card " << cards.at(currCard) << endl;
            cards.remove(currCard);
            return true;
        }
    }
    return false;
}


