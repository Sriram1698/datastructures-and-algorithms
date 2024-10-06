#include "../queues/Queue.h"
#include "BinarySearchTree.h"
#include <vector>

using std::vector;

template <typename DataType>
binary_tree::BinarySearchTree<DataType>
createBSTree(const vector<DataType> &arr) {
  if (arr.size() < 1) {
    binary_tree::BinarySearchTree<DataType>();
  }
  binary_tree::BinarySearchTree<DataType> bs_tree(arr[0]);
  for (int i = 1; i < arr.size(); i++) {
    bs_tree.insert(arr[i]);
  }
  return bs_tree;
}

int main() {
  vector<int> arr = {3, 2, 5, 6, 1, 5, 0, 17, 8, 11};

  binary_tree::BinarySearchTree<int> tree = createBSTree<int>(arr);
  tree.print();
  tree.remove(0);
  tree.print();
  tree.remove(3);
  tree.print();
  tree.remove(2);
  tree.print();
  tree.insert(12);
  tree.print();
  tree.remove(8);
  tree.print();
  tree.remove(1);
  tree.print();
  return EXIT_SUCCESS;
}