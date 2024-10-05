#include "Deque.h"
#include <vector>

using std::vector;

int main() {
  vector<int> arr = {1, 2, 23, 87, -1, 100};

  Deque<int> dque;
  for (const auto element : arr) {
    dque.pushBack(element);
  }
  dque.print();

  dque.reverse();
  dque.print();

  dque.popFront();
  dque.popBack();
  dque.pushFront(99);
  dque.pushBack(-99);
  dque.print();

  return EXIT_SUCCESS;
}