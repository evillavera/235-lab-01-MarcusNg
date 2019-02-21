#include <iostream>

#include <string>
#include "Node.h"

class List{
private:
  Node *head;
  int size;
public:
  List();
  ~List();
  void insert(std::string data);
  std::string getDebugString();
  void push_back(std::string); // inserts at the end of the vector
  int getSize(); // returns the size
  std::string & at(int i); // returns the element at a location
  std::string insert(int i, std::string); // inserts string at location
  void remove(int i); // removes the element at location i
  std::string & operator[](int); // overloaded square brackets
};
