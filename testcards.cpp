// // This file should contain unit tests for all the 
// // public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  test_constructor();
  test_append();
  test_equal();
  test_card();
  test_size();
  test_at();
  test_getCard();
  test_destructor();
  test_remove();
  test_search_remove();
}

void test_constructor(){
  START_TEST("test_constructor");
  ifstream inFile;
  inFile.open("acards.txt");
  CardList l1(inFile);
  assertEquals(10, l1.size(), "test_constructor 1");
  CardList l2;
  assertEquals(0, l2.size(), "test_constructor 2");
  END_TEST("test_constructor");
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

void test_size(){
  START_TEST("test_size");
  ifstream inFile;
  inFile.open("acards.txt");
  CardList l1(inFile), l2;
  assertEquals(10, l1.size(), "test_size 1");
  l1.append("c 9");
  assertEquals(11, l1.size(), "test_size 2");
  assertEquals(0, l2.size(), "test_size 3");
  END_TEST("test_size");
}

void test_at(){
  START_TEST("test_at");
  ifstream inFile;
  inFile.open("acards.txt");
  CardList l1(inFile), l2;
  assertEquals("c a", l1.at(2), "test_at 1");
  assertEquals("h 3", l1.at(0), "test_at 2");
  assertEquals("", l1.at(-1), "test_at 3");
  assertEquals("", l2.at(1), "test_at 4");
  END_TEST("test_at");
}

void test_getCard(){
  START_TEST("test_getCards");
  ifstream inFile;
  inFile.open("acards.txt");
  CardList l1(inFile), l2;
  assertEquals("c a", (l1.getCard(2))->data, "test_getCards 1");
  assertEquals("h 3", (l1.getCard(0))->data, "test_getCards 2");
  assertEquals(NULL, (l1.getCard(-1)), "test_getCards 3");
  assertEquals(NULL, (l2.getCard(1)), "test_getCards 4");
  END_TEST("test_getCards");
}

void test_remove(){
  START_TEST("test_remove");
  ifstream inFile;
  inFile.open("acards.txt");
  CardList l1(inFile), l2;
  l1.remove(0);
  assertEquals(9, l1.size(), "test_remove 1");
  l1.remove(4);
  assertEquals(8, l1.size(), "test_remove 2");
  l1.remove(10);
  assertEquals(8, l1.size(), "test_remove 3");
  l2.remove(0);
  assertEquals(0, l2.size(), "test_remove 4");
  END_TEST("test_remove");
}

void test_search_remove(){
  START_TEST("test_search_remove");
  ifstream inFile;
  inFile.open("acards.txt");
  CardList l1(inFile);
  Card* c = l1.getCard(2);
  bool tmp = l1.search_remove(*c);
  assertEquals(1, tmp, "test_remove bool 1");
  assertEquals(9, l1.size(), "test_remove size 1");
  c = l1.getCard(10);
  if(c){
    tmp = l1.search_remove(*c);
    assertEquals(0, tmp, "test_remove bool 2");
    assertEquals(9, l1.size(), "test_remove size 2");
  }else{
    cout<<"PASSED "<<endl;
  }
  END_TEST("test_search_remove");
}

void test_destructor(){
  START_TEST("test_destructor");
  ifstream inFile;
  inFile.open("acards.txt");
  CardList l1(inFile);
  l1.~CardList();
  assertEquals(0, l1.size(), "test_deconstructor");
  END_TEST("test_destructor");
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
  Card c1, c2, c3;
  c1.data = "c 9";
  c2.data = "c 9";
  c3.data = "h k";
  c1.next = &c3;
  c2.next = &c3;
  assertEquals(c1, c1, "test operator== with same node");
  assertEquals(c2, c1, "test operator== same data but different node");
}




