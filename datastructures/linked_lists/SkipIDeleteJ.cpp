#include "LinkedList.h"

#include <vector>

using std::vector;

LinkedList<int> skipIDeleteJ(const LinkedList<int> &list, const uint64_t i,
                             const uint64_t j) {
  if ((i == 0) || (list.empty())) {
    return LinkedList<int>();
  } else if (j == 0) {
    return LinkedList<int>(list.head());
  }

  SharedPtr<Node<int>> current = list.head();
  SharedPtr<Node<int>> prev = nullptr;

  while (current) {
    for (int i_skip = 0; i_skip < i; i_skip++) {
      if (!current) {
        break;
      }
      prev = current;
      current = current->next();
    }
    for (int j_delete = 0; j_delete < j; j_delete++) {
      if (!current) {
        break;
      }
      current = current->next();
    }
    prev->next(current);
  }
  return LinkedList<int>(list);
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  uint64_t i = 2, j = 3;
  LinkedList<int> lst(arr.cbegin(), arr.cend());
  lst.print();
  auto new_list = skipIDeleteJ(lst, i, j);
  new_list.print();
}