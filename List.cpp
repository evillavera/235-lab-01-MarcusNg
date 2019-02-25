#include <iostream>

#include <string>
#include "List.h"

List::List(){
  dummy = new Node("dummy", nullptr);
  head = dummy;
  size = 0;
}

List::~List(){
  std::cout << "In the destructor\n";
  if (dummy != nullptr){
    Node *t,*t2;
    t=dummy->getNext();
    while (t!=nullptr){
      t2=t;
      t=t->getNext();
      delete t2;
    }
    size = 0;
  }
}

void List::insert(std::string data){
  Node *t = new Node(data,nullptr);
  t->setNext(dummy->getNext());
  dummy->setNext(t);
  size++;
}

std::string List::getDebugString(){
  std::string s = "";
  Node *t = dummy->getNext();
  while (t != nullptr){
    s = s + t->getData()+"->";
    t=t->getNext();
  }
  s=s+" NULL\n";
  return s;
}

void List::push_back(std::string data) {
  Node *tmp,*t;
  tmp = dummy->getNext();
  t = new Node(data);
  while (tmp->getNext() != nullptr) {
    tmp = tmp->getNext();
  }
  tmp->setNext(t);
  size++;
}

int List::getSize() {
  return size;
}

/*
int List::size() {
  int s = 0;
  Node *tmp;
  tmp = head;
  while (tmp != nullptr) {
    tmp = tmp->getNext();
    s++;
  }
  return s;
}
*/

std::string & List::at(int i) {
  Node *tmp = dummy->getNext();
  int ctr = 0;
  while (ctr < i) {
    tmp = tmp->getNext();
    ctr++;
  }
  return tmp->getRefData();
}

std::string List::insert(int i,std::string data) {
  Node *tmp,*t;
  t = dummy->getNext();
  tmp = t->getNext();
  int ctr = 0;
  while (ctr < i - 1) {
    t = tmp;
    tmp = t->getNext();
    ctr++;
  }
  t->setNext(new Node(data, tmp));
  size++;
  return tmp->getData();
}

void List::remove(int i) {
  Node *tmp,*t;
  t = dummy->getNext();
  tmp = t->getNext();
  int ctr = 0;
  while (ctr < i - 1) {
    t = tmp;
    tmp = t->getNext();
    ctr++;
  }
  t->setNext(tmp->getNext());
  size--;
  delete tmp;
}

std::string & List::operator[](int i) {
  return at(i);
}
