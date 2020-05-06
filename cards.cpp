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

CardList::CardList(){
    head = nullptr;
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
  append(head, c);

  //Card* currObj = head;
  //
  //while(currObj->next){
  //  currObj = currObj->next;
  //}

  //currObj->next = new Card(c);
}

void CardList::append(Card* c, const string s) {
    if (!c->next) {
        c->next = new Card(s);
        return;
    }
    append(c->next, s);
}


void CardList::remove(const int n){
  if(n>=size()){
    cout << "REMOVE() OUT OF RANGE, " << n << " LARGER THAN " << size() << endl;
    return;
  }

  if (remove(head, n)) {
      Card* tmp = head->next;
      delete head;
      head = tmp;
  }

  //Card* currObj = head;
  //for(int i=0;i<n-1;i++){
  //  currObj = currObj->next;
  //}
  //Card* temp = currObj->next->next;
  //delete currObj->next;
  //currObj->next = temp;
}

bool CardList::remove(Card* c, const int n) {
    if (n == 0) {
        return true;
    }
    if (remove(c->next, n - 1)) {
        Card* temp = c->next->next;
        delete c->next;
        c->next = temp;
    }
    return false;
}

//MAKES USE OF CARD CLASS == OPERATOR
bool CardList::search_remove(const Card c){
  Card* cur = head;
  string output;
  if(!head){
    return false;
  }
  if(*head == c){
    delete head;
    head = 0;
    return true;
  }
  while(cur->next){
    if(*(cur->next) == c){
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
    if(n>=size()){
        cout << "AT() OUT OF RANGE, " << n << " LARGER THAN " << size() << endl;
        return "";
    }
    return at(head, n);

  //Card* currObj = head;
  //for(int i=0;i<n;i++){
  //  currObj = currObj->next;
  //}

  //return currObj->data;
}

string CardList::at(Card* c, const int n) const {
    if (n == 0) {
        return c->data;
    }
    if(n < 0){
	cout<<"AT() OUT OF RANGE, INDEX CANNOT BE LESS THAN 0"<<endl;
	return "";
    }
    return at(c->next, n - 1);
}

Card* CardList::getCard(const int n) const{
    if(n >= size()){
        cout<<"GETCARD() OUT OF RANGE, "<<n<<" LARGER THAN "<<size()<<endl;
        return NULL;
    }
    return getCard(head, n);
  //Card* currObj = head;
  //for(int i = 0; i < n; i++){
  //  currObj = currObj->next;
  //}
  //return currObj;
}

Card* CardList::getCard(Card* c, const int n) const {
    if (n == 0) {
        return c;
    }
    if(n < 0){
	cout<<"GETCARD() OUT OF RANGE< INDEX CANNOT BE LESS THAN 0"<<endl;
	return NULL;
    }
    return getCard(c->next, n - 1);
}

int CardList::size() const{
    return size(head);

  /*Card* currObj = head;
  int count=0;
  while(currObj){
    count++;
    currObj=currObj->next;
  }
  return count;*/
}

int CardList::size(Card* c) const {
    if (!c) {
        return 0;
    }
    return size(c->next) + 1;
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
    while (currCard < cards.size()) {
        if (p.cards.search_remove(*cards.getCard(currCard))) {
            cout << name << " picked matching card " << cards.at(currCard) << endl;
            cards.remove(currCard);
            return true;
        }
        currCard++;
    }
    return false;
}


