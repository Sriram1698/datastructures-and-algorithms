#include "Stack.h"
#include <vector>

using std::vector;

int main() {
  vector<int> arr = {1, 2, 23, 87, -1, 100};

  Stack<int> stk;
  for (const auto element : arr) {
    stk.push(element);
  }
  stk.print();
  stk.reverse();
  stk.print();
  uint16_t pop_k_elements = 3;
  for (uint16_t i = 0; i < pop_k_elements; i++) {
    stk.pop();
  }
  stk.print();
  return EXIT_SUCCESS;
}