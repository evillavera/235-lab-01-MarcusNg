#include <iostream>

#include <string>
#include "List.h"

List::List(){
  head = nullptr;
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
   if (head != nullptr){
     Node *tmp,*t;
     tmp = head;
     t = new Node(data);
     
     while (tmp->getNext() != nullptr) {
       tmp = tmp->getNext();
     }
     
     tmp->setNext(t);
   }
}

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

std::string & List::at(int i) {
  Node * tmp = head;

  if (i < size()) {
    for (int j = 0; j < i; j++) {
      tmp = tmp->getNext();
    }
  }
    
  //return tmp->getData();
}

std::string List::insert(int index,std::string data) {
  Node *tmp,*t;
  tmp = head;
  t = new Node(data);
  if (index < size()) {
    for (int i = 0; i < index; i++) {
      tmp = tmp->getNext();
    }
  }
  return data;
}

void List::remove(int i) {
  return;
}

//std::string & List::operator[](int) {
//
//}
