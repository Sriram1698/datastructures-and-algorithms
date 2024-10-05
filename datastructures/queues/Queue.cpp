#include "Queue.h"
#include <vector>

using std::vector;

int main() {
  vector<int> arr = {1, 2, 23, 87, -1, 100};

  Queue<int> que;
  for (const auto element : arr) {
    que.push(element);
  }
  que.print();
  que.reverse();
  que.print();
  uint16_t pop_k_elements = 3;
  for (uint16_t i = 0; i < pop_k_elements; i++) {
    que.pop();
  }
  que.print();
  return EXIT_SUCCESS;
}