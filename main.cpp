#include <iostream>
#include "list/single_linked_list.hpp"

using namespace list;
using namespace std;

int main() {
  SingleLinkedList<int> list;
  cout << list.size() << endl;
  return 0;
}