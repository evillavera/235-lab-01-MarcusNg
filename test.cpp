#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "List.h"

TEST_CASE("Testing Linked List"){
  List l;
  l.insert("one");
  l.insert("two");
  l.insert("three");
  l.insert("four");

  CHECK(l.getSize() == 4);
  CHECK(l[2] == "two");
  l.push_back("five");
  CHECK(l.at(4) == "five");
  l.insert(4, "awesome");
  CHECK(l.at(4) == "awesome");
  l.remove(2);
  CHECK(l[2] == "one");
  
}
