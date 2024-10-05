#include "Deque.h"
#include <vector>

using std::vector;

int main() {
  vector<int> arr = {1, 2, 23, 87, -1, 100};

  Deque<int> dque;
  for (const auto element : arr) {
    dque.push_back(element);
  }
  dque.print();

  dque.reverse();
  dque.print();

  dque.pop_front();
  dque.pop_back();
  dque.push_front(99);
  dque.push_back(-99);
  dque.print();
  
  return EXIT_SUCCESS;
}