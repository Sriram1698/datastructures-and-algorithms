#include "../stacks/Stack.h"
#include "BinaryTree.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

template <typename DataType> binary_tree::BinaryTree<DataType> createATree() {
  // Create a binary tree with a root node
  binary_tree::BinaryTree<DataType> b_tree("apple");
  auto root = b_tree.root();
  root->left(MakeShared<binary_tree::Node<DataType>>("banana"));
  root->right(MakeShared<binary_tree::Node<DataType>>("cherry"));

  root->left()->left(MakeShared<binary_tree::Node<DataType>>("dates"));
  return b_tree;
}

template <typename DataType>
void preOrderTraversal(SharedPtr<binary_tree::Node<DataType>> node) {
  if (!node) {
    return;
  }
  std::cout << node->data() << std::endl;
  preOrderTraversal(node->left());
  preOrderTraversal(node->right());
}

template <typename DataType>
void inOrderTraversal(SharedPtr<binary_tree::Node<DataType>> node) {
  if (!node) {
    return;
  }
  inOrderTraversal(node->left());
  std::cout << node->data() << std::endl;
  inOrderTraversal(node->right());
}

template <typename DataType>
void postOrderTraversal(SharedPtr<binary_tree::Node<DataType>> node) {
  if (!node) {
    return;
  }
  postOrderTraversal(node->left());
  postOrderTraversal(node->right());
  std::cout << node->data() << std::endl;
}

int main() {
  auto tree = createATree<string>();
  std::cout << "\nPre-order Traversal: " << std::endl;
  preOrderTraversal<string>(tree.root());

  std::cout << "\nInorder Traversal: " << std::endl;
  inOrderTraversal<string>(tree.root());

  std::cout << "\nPost-order Traversal: " << std::endl;
  postOrderTraversal<string>(tree.root());
  return EXIT_SUCCESS;
}