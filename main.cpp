#include <iostream>
#include "list/single_linked_list.hpp"

using namespace list;

int main() {
  SingleLinkedList<int> list;
  std::cout << list.size() << std::endl;
  list.add(1);
  list.add(2);
  std::cout << list << std::endl;
  list.filter([](int x) { return x & 1; });
  std::cout << list << std::endl;
  return 0;
}
