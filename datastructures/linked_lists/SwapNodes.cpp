#include "LinkedList.h"

#include <vector>
using std::vector;

void getNode(SharedPtr<Node<int>> &p, SharedPtr<Node<int>> &c,
             SharedPtr<Node<int>> &prev, SharedPtr<Node<int>> &current,
             uint64_t &index, const uint64_t i) {
  while (current && (index <= i)) {
    if (index == i) {
      c = current;
      p = prev;
      break;
    }
    prev = current;
    current = current->next();
    index++;
  }
}

void swapNodes(LinkedList<int> &list, uint64_t i, uint64_t j) {
  if (i == j) {
    return;
  } else if (i > j) {
    auto temp = i;
    i = j;
    j = temp;
  }

  SharedPtr<Node<int>> p1 = nullptr;
  SharedPtr<Node<int>> c1 = list.head();

  SharedPtr<Node<int>> p2 = nullptr;
  SharedPtr<Node<int>> c2 = list.head();

  SharedPtr<Node<int>> prev = nullptr;
  SharedPtr<Node<int>> current = list.head();

  uint64_t index = 0;
  getNode(p1, c1, prev, current, index, i);
  getNode(p2, c2, prev, current, index, j);

  auto temp = c2->next();
  if (p1) {
    p1->next(c2);
  } else {
    list.head(c2);
  }

  if (c1->next() == c2) {
    c2->next(c1);
  } else {
    c2->next(c1->next());
  }

  if (p2 != c1) {
    p2->next(c1);
  }
  c1->next(temp);
}

int main() {
  vector<int> arr = {3, 4, 5, 2, 6, 1, 9};
  uint64_t i = 0, j = 5;
  LinkedList<int> lst(arr.cbegin(), arr.cend());
  lst.print();
  swapNodes(lst, i, j);
  lst.print();
}