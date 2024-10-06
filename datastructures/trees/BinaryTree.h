#pragma once

#include "BinaryTreeNode.h"
#include <vector>

using std::vector;

namespace binary_tree {
template <typename DataType> class BinaryTree {
public:
  BinaryTree();
  BinaryTree(const DataType &data);

  virtual ~BinaryTree();
  SharedPtr<binary_tree::Node<DataType>> root() { return root_; }

  virtual void insert(const DataType &data);
  virtual void remove(const DataType &data);

  virtual vector<DataType> path(const DataType &data) const;
  virtual void print() const;

protected:
  SharedPtr<binary_tree::Node<DataType>> root_;
};
} // namespace binary_tree

//////////////////////////////////////////////////////

template <typename DataType>
binary_tree::BinaryTree<DataType>::BinaryTree() = default;

//////////////////////////////////////////////////////

template <typename DataType>
binary_tree::BinaryTree<DataType>::BinaryTree(const DataType &data) {
  root_ = MakeShared<binary_tree::Node<DataType>>(data);
}

//////////////////////////////////////////////////////

template <typename DataType>
binary_tree::BinaryTree<DataType>::~BinaryTree() = default;

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::BinaryTree<DataType>::insert(const DataType &data) {}

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::BinaryTree<DataType>::remove(const DataType &data) {}

//////////////////////////////////////////////////////

template <typename DataType>
vector<DataType>
binary_tree::BinaryTree<DataType>::path(const DataType &data) const {}

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::BinaryTree<DataType>::print() const {}

//////////////////////////////////////////////////////