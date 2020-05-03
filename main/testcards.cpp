// // This file should contain unit tests for all the 
// // public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  test_append();
  test_equal();
  test_card();
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  test_equal_single_element_list();
  END_TEST("test_equal");
}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  END_TEST("test_card");
}


void test_append_empty_list(){ 
  // A test case for append single card node to LinkedList
  CardList a1;
  a1.append("c 9");
  assertEquals(1, a1.size(), "test append to empty list");
}

void test_append_single_element_list(){ 
  // Tests cases should be independent,
  // small, fast, orthogonal (test for different cases)
  CardList a1;
  assertEquals(0, a1.size(), "test append list 1");
  a1.append("c 9");
  assertEquals(1, a1.size(), "test append list 2");
  a1.append("h k");
  assertEquals(2, a1.size(), "test append list 3");
}

void test_equal_empty_list(){ 
  string testname = "case 0: [], []";
  CardList l1, l2;
  assertEquals(l1.getCard(0),l2.getCard(0), testname);
}

void test_equal_single_element_list(){
  CardList l1, l2;
  l1.append("c k");
  l1.append("h 5");
  l1.append("s 6");
  l2.append("c k");
  l2.append("h 5");
  l2.append("s 6");
  for(int i = 0; i < 3; i++){
    assertEquals(l1.at(i), l2.at(i), "test equal given list");
  }
}

void test_card_operator_double_equal(){
  // Test to check if == is overloaded for card
  CardList l1, l2;
  l1.append("c 9");
  assertEquals(l1.getCard(0), l1.getCard(0), "test operator== with same node");
  l2.append("c 9");
  assertEquals(l1.getCard(0), l2.getCard(0), "test operator== same data but different CardList");
  if(l1.getCard(0) == l2.getCard(0))
	  cout<<"good"<<endl;
  else
	  cout<<"no"<<endl;
  Card a1, a2, a3, a4;
  a1.data = "c 9";
  //a1.next = l1.getCard(0);
  a2.data = "c 9";
  //a2.next = l2.getCard(0);
  if(a1 == a2)
	  cout<<"yep"<<endl;
  else
	  cout<<"nop"<<endl;
  a3.data = l1.getCard(0)->data;
  a3.next = l1.getCard(0)->next;
  a4.data = l2.getCard(0)->data;
  a4.next = l2.getCard(0)->next;
  if(a3 == a4)
	  cout<<"ok"<<endl;
  else
	  cout<<"lol no"<<endl;
}




