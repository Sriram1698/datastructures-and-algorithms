#include "LinkedList.h"

#include <vector>

using std::vector;

int main() {
  vector<int> arr = {9, 0, 0, 1, 4, 4, 3, 9, 2, 2, 0};
  LinkedList<int> linked_list(arr.begin(), arr.end());
  linked_list.print();
  linked_list.sort();
  linked_list.print();
  return EXIT_SUCCESS;
}