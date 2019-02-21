#include <iostream>

#include <string>
#include "List.h"

List::List(){
  head = nullptr;
  size = 0;
}

List::~List(){
  std::cout << "In the destructor\n";
  if (head != nullptr){
    Node *t,*t2;
    
    t=head->getNext();
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
  if (head==nullptr)
    head=t;
  else{
    t->setNext(head);
    head = t;
  }
  size++;
}

std::string List::getDebugString(){
  std::string s = "";
  Node *t = head;
  while (t != nullptr){
    s = s + t->getData()+"->";
    t=t->getNext();
  }
  s=s+" NULL\n";
  return s;
}

void List::push_back(std::string data) {
  Node *tmp,*t;
  tmp = head;
  t = new Node(data);
  if (head != nullptr){
    while (tmp->getNext() != nullptr) {
      tmp = tmp->getNext();
    }
    tmp->setNext(t);
  } else {
    head = t;
  }
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
  Node *tmp = head;
  int ctr = 0;
  while (ctr < i) {
    tmp = tmp->getNext();
    ctr++;
  }
  return tmp->getRefData();
}

std::string List::insert(int i,std::string data) {
  Node *tmp,*t;
  t = head;
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
  t = head;
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
