#include "../queues/Queue.h"
#include "BinaryTree.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

template <typename DataType> binary_tree::BinaryTree<DataType> createATree() {
  binary_tree::BinaryTree<DataType> b_tree("A");
  auto root = b_tree.root();
  root->left(MakeShared<binary_tree::Node<DataType>>("B"));
  root->right(MakeShared<binary_tree::Node<DataType>>("C"));

  root->left()->left(MakeShared<binary_tree::Node<DataType>>("D"));
  root->left()->right(MakeShared<binary_tree::Node<DataType>>("E"));

  root->right()->left(MakeShared<binary_tree::Node<DataType>>("F"));
  root->right()->right(MakeShared<binary_tree::Node<DataType>>("G"));

  return b_tree;
}

template <typename DataType>
void bfs(SharedPtr<binary_tree::Node<DataType>> node) {
  if (!node) {
    return;
  }

  Queue<SharedPtr<binary_tree::Node<DataType>>> que;
  que.push(node);
  while (!que.empty()) {
    node = que.front();
    que.pop();
    std::cout << node->data() << std::endl;
    (node->left()) ? que.push(node->left()) : void(0);
    (node->right()) ? que.push(node->right()) : void(0);
  }
}

int main() {
  auto tree = createATree<string>();
  bfs<string>(tree.root());
  return EXIT_SUCCESS;
}