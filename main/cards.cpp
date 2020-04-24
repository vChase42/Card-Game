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
  if(empty()){
    head = new Card(c);
    return;
  }

  Card* currObj = head;
  
  while(currObj->next){
    currObj = currObj->next;
  }

  currObj->next = new Card(c);

}



void CardList::remove(const int n){
  if(n>size()){
    cout << "REMOVE() OUT OF RANGE, " << n << " LARGER THAN " << size() << endl;
  }

  Card* currObj = head;
  for(int i=0;i<n-1;i++){
    currObj = currObj->next;
  }
  Card* temp = currObj->next->next;
  delete currObj->next;
  currObj->next = temp;

}

string CardList::search_remove(const string c){
  Card* cur = head;
  string output;
  if(!head){
    return "CARDLIST CONTAINS NO CARDS";
  }
  if(head->data == c){
    delete head;
    head = 0;
    return c;
  }
  while(cur->next){
    if(cur->next->data == c){
      Card* tmp = cur->next->next;
      delete cur->next;
      cur->next = tmp;
      return c;
    }
    cur = cur->next;
  }
  return "NO MATCHING CARDS";
}

bool CardList::empty() const{
  return head==nullptr;
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
  if(empty()){
    return 0;
  }
  Card* currObj = head;
  int count=0;
  while(currObj){
    count++;
    currObj=currObj->next;
  }
  return count;
}

ostream& operator<<(ostream& out, CardList& list){
  for(int i=0;i<list.size();i++){
    out << list.at(i) << endl;
  }
}
