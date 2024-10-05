#include "LinkedList.h"

#include <vector>

using std::vector;

LinkedList<int> evenAfterOdd(const LinkedList<int> &list) {
  if (list.empty()) {
    return LinkedList<int>();
  }

  SharedPtr<Node<int>> even_head = nullptr;
  SharedPtr<Node<int>> even_tail = nullptr;

  SharedPtr<Node<int>> odd_head = nullptr;
  SharedPtr<Node<int>> odd_tail = nullptr;

  auto current = list.head();

  while (current) {
    auto next_node = current->next();

    if (current->data() % 2 == 0) {
      if (!even_head) {
        even_head = current;
        even_tail = even_head;
      } else {
        even_tail->next(current);
        even_tail = even_tail->next();
      }
    } else {
      if (!odd_head) {
        odd_head = current;
        odd_tail = odd_head;
      } else {
        odd_tail->next(current);
        odd_tail = odd_tail->next();
      }
    }
    current->next(nullptr);
    current = next_node;
  }

  if (!odd_head) {
    return LinkedList<int>(even_head);
  }
  odd_tail->next(even_head);
  return LinkedList<int>(odd_head);
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  LinkedList<int> lst(arr.cbegin(), arr.cend());
  lst.print();
  auto sorted_list = evenAfterOdd(lst);
  sorted_list.print();
}