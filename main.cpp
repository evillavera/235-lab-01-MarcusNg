#include <iostream>
#include "List.h"

int main()
{
  List l;
  std::cout << l.getDebugString();
  l.insert("one");
  l.insert("two");
  l.insert("three");
  l.insert("four");

  std::cout << "\n\n-----------Testing-----------\n\n";
  std::cout << l.getDebugString();
  std::cout << "size: " << l.size();

  std::cout << "\n\npush_back(\"five\")"")\n";
  l.push_back("five");
  std::cout << l.getDebugString() << std::endl;

  std::cout << "operator [3]\n";
  std::cout << "l[3]: " << l[3] << std::endl;
  std::cout << "\nsetting l[3] to hello\n";
  l[3] = "hello";
  std::cout << "l.at(3): " << l.at(3) << std::endl;

  std::cout << "\ninserting \"awesome\" at index 4" << std::endl;
  l.insert(4, "awesome");

  std::cout << l.getDebugString() << std::endl;

  std::cout << "removing \"two\" at index 2" << std::endl;
  l.remove(2);
  std::cout << l.getDebugString() << std::endl;

  return 0;
}
