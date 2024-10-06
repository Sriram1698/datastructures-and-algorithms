#pragma once

#include "BinaryTree.h"
#include <algorithm>
#include <tuple>

using std::max;
using std::tuple;

namespace binary_tree {
template <typename DataType>
class BinarySearchTree : public BinaryTree<DataType> {
public:
  BinarySearchTree();
  BinarySearchTree(const DataType &data);
  ~BinarySearchTree();

  void insert(const DataType &data) override;
  void remove(const DataType &data) override;
  bool search(const DataType &data) override;

  size_t diameter() const override;
  vector<DataType> path(const DataType &data) const override;
  void print() const override;

private:
  void recursiveInsertion(SharedPtr<binary_tree::Node<DataType>> node,
                          const DataType &data);
  bool recursiveSearch(SharedPtr<binary_tree::Node<DataType>> node,
                       const DataType &data);

  SharedPtr<binary_tree::Node<DataType>> getNode(const DataType &data);
  SharedPtr<binary_tree::Node<DataType>>
  getNodeByRecursion(SharedPtr<binary_tree::Node<DataType>> node,
                     const DataType &data);

  SharedPtr<binary_tree::Node<DataType>> getNodeWithLargestValueFromSubBranch(
      SharedPtr<binary_tree::Node<DataType>> node);

  tuple<size_t, size_t>
  getDiameterOfTree(const SharedPtr<binary_tree::Node<DataType>> node) const;
  vector<DataType> getPathInternal(SharedPtr<binary_tree::Node<DataType>> node,
                                   const DataType &data) const;

  void printInternal(SharedPtr<binary_tree::Node<DataType>> node) const;
};
} // namespace binary_tree

//////////////////////////////////////////////////////

template <typename DataType>
binary_tree::BinarySearchTree<DataType>::BinarySearchTree()
    : BinaryTree<DataType>() {}

//////////////////////////////////////////////////////

template <typename DataType>
binary_tree::BinarySearchTree<DataType>::BinarySearchTree(const DataType &data)
    : BinaryTree<DataType>(data) {}

//////////////////////////////////////////////////////

template <typename DataType>
binary_tree::BinarySearchTree<DataType>::~BinarySearchTree() = default;

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::BinarySearchTree<DataType>::insert(const DataType &data) {
  recursiveInsertion(this->root_, data);
}

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::BinarySearchTree<DataType>::remove(const DataType &data) {
  auto node = getNode(data);
  if (!node) {
    return;
  }

  auto parent = node->parent();
  if (node->isLeafNode()) {
    return (node->data() < parent->data()) ? parent->left(nullptr)
                                           : parent->right(nullptr);
  } else if (!node->hasTwoChildren()) {
    auto carry_node = (node->hasLeft()) ? node->left() : node->right();
    carry_node->parent(parent);
    if (!parent) {
      this->root_ = carry_node;
    } else {
      if (parent->isLeftChild(node)) {
        parent->left(carry_node);
      } else {
        parent->right(carry_node);
      }
    }
    return;
  }

  auto largest_node = getNodeWithLargestValueFromSubBranch(node->left());
  if (largest_node) {
    auto right_node = node->right();
    largest_node->right(right_node);
    right_node->parent(largest_node);

    if (!node->isChild(largest_node)) {
      auto parent_of_largest_node = largest_node->parent();
      parent_of_largest_node->right(nullptr);
      auto left_node = node->left();
      largest_node->left(left_node);
      left_node->parent(largest_node);
    }
    if (!parent) {
      largest_node->parent(nullptr);
      this->root_ = largest_node;
    } else {
      parent->isLeftChild(largest_node) ? parent->left(largest_node)
                                        : parent->right(largest_node);
    }
  }
}

//////////////////////////////////////////////////////

template <typename DataType>
bool binary_tree::BinarySearchTree<DataType>::search(const DataType &data) {
  return recursiveSearch(this->root_, data);
}

//////////////////////////////////////////////////////

template <typename DataType>
vector<DataType>
binary_tree::BinarySearchTree<DataType>::path(const DataType &data) const {
  auto path = getPathInternal(this->root_, data);
  std::reverse(path.begin(), path.end());
  return path;
}

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::BinarySearchTree<DataType>::recursiveInsertion(
    SharedPtr<binary_tree::Node<DataType>> node, const DataType &data) {
  if ((!node) || (node && (data == node->data()))) {
    return;
  }
  if (data < node->data()) {
    (node->left()) ? recursiveInsertion(node->left(), data)
                   : node->insertLeft(data);
  } else {
    (node->right()) ? recursiveInsertion(node->right(), data)
                    : node->insertRight(data);
  }
}

//////////////////////////////////////////////////////

template <typename DataType>
bool binary_tree::BinarySearchTree<DataType>::recursiveSearch(
    SharedPtr<binary_tree::Node<DataType>> node, const DataType &data) {
  if (!node) {
    return false;
  } else if (node && (data == node->data())) {
    return true;
  }
  return (data < node->data()) ? recursiveSearch(node->left(), data)
                               : recursiveSearch(node->right(), data);
}

//////////////////////////////////////////////////////

template <typename DataType>
SharedPtr<binary_tree::Node<DataType>>
binary_tree::BinarySearchTree<DataType>::getNode(const DataType &data) {
  return getNodeByRecursion(this->root_, data);
}

//////////////////////////////////////////////////////

template <typename DataType>
SharedPtr<binary_tree::Node<DataType>>
binary_tree::BinarySearchTree<DataType>::getNodeByRecursion(
    SharedPtr<binary_tree::Node<DataType>> node, const DataType &data) {
  if (!node) {
    return nullptr;
  } else if (data == node->data()) {
    return node;
  }
  return (data < node->data()) ? getNodeByRecursion(node->left(), data)
                               : getNodeByRecursion(node->right(), data);
}

//////////////////////////////////////////////////////

template <typename DataType>
SharedPtr<binary_tree::Node<DataType>>
binary_tree::BinarySearchTree<DataType>::getNodeWithLargestValueFromSubBranch(
    SharedPtr<binary_tree::Node<DataType>> node) {
  if (node && node->right()) {
    return getNodeWithLargestValueFromSubBranch(node->right());
  }
  return node;
}

//////////////////////////////////////////////////////

template <typename DataType>
size_t binary_tree::BinarySearchTree<DataType>::diameter() const {
  const auto [tree_height, tree_diameter] = getDiameterOfTree(this->root_);
  return tree_diameter;
}

//////////////////////////////////////////////////////

template <typename DataType>
tuple<size_t, size_t>
binary_tree::BinarySearchTree<DataType>::getDiameterOfTree(
    const SharedPtr<binary_tree::Node<DataType>> node) const {
  if (!node) {
    return std::make_tuple(0, 0);
  }

  const auto [left_height, left_diameter] = getDiameterOfTree(node->left());
  const auto [right_height, right_diameter] = getDiameterOfTree(node->right());

  const auto current_height = max(left_height, right_height) + 1;
  const auto height_diameter = left_height + right_height;

  const auto current_diameter =
      max(height_diameter, max(left_diameter, right_diameter));

  return std::make_tuple(current_height, current_diameter);
}

//////////////////////////////////////////////////////

template <typename DataType>
vector<DataType> binary_tree::BinarySearchTree<DataType>::getPathInternal(
    SharedPtr<binary_tree::Node<DataType>> node, const DataType &data) const {
  if (!node) {
    return {};
  } else if (node->data() == data) {
    return {data};
  }
  auto left_vec = getPathInternal(node->left(), data);
  if (!left_vec.empty()) {
    left_vec.push_back(node->data());
    return left_vec;
  }
  auto right_vec = getPathInternal(node->right(), data);
  if (!right_vec.empty()) {
    right_vec.push_back(node->data());
    return right_vec;
  }
  return {};
}

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::BinarySearchTree<DataType>::print() const {
  std::cout << "[";
  printInternal(this->root_);
  std::cout << "]" << std::endl;
}

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::BinarySearchTree<DataType>::printInternal(
    SharedPtr<binary_tree::Node<DataType>> node) const {
  if (!node) {
    return;
  }
  printInternal(node->left());
  std::cout << node->data() << ", ";
  printInternal(node->right());
}