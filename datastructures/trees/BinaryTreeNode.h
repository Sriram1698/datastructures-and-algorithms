#pragma once
#include "../memory/Memory.h"

namespace binary_tree {
template <typename DataType>
class Node : public EnableSharedFromThis<Node<DataType>> {
public:
  Node(const DataType &data);
  ~Node();

  void insertLeft(const DataType &data);
  void insertRight(const DataType &data);

  void parent(const SharedPtr<Node<DataType>> &node);
  void left(const SharedPtr<Node<DataType>> &node);
  void right(const SharedPtr<Node<DataType>> &node);

  const DataType &data() const;
  SharedPtr<Node<DataType>> &parent();
  SharedPtr<Node<DataType>> &left();
  SharedPtr<Node<DataType>> &right();

  bool isChild(const SharedPtr<Node<DataType>> &node);
  bool isLeftChild(const SharedPtr<Node<DataType>> &node);
  bool isRightChild(const SharedPtr<Node<DataType>> &node);

  bool hasLeft() const;
  bool hasRight() const;
  bool hasTwoChildren() const;
  bool isLeafNode() const;

private:
  DataType data_;
  SharedPtr<Node<DataType>> parent_;
  SharedPtr<Node<DataType>> left_;
  SharedPtr<Node<DataType>> right_;
};
} // namespace binary_tree

//////////////////////////////////////////////////////

template <typename DataType>
binary_tree::Node<DataType>::Node(const DataType &data) : data_(data) {}

//////////////////////////////////////////////////////

template <typename DataType> binary_tree::Node<DataType>::~Node() = default;

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::Node<DataType>::insertLeft(const DataType &data) {
  left_ = MakeShared<Node<DataType>>(data);
  left_->parent(this->shared_from_this());
}

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::Node<DataType>::insertRight(const DataType &data) {
  right_ = MakeShared<Node<DataType>>(data);
  right_->parent(this->shared_from_this());
}

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::Node<DataType>::parent(
    const SharedPtr<binary_tree::Node<DataType>> &node) {
  parent_ = node;
}

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::Node<DataType>::left(
    const SharedPtr<binary_tree::Node<DataType>> &node) {
  left_ = node;
}

//////////////////////////////////////////////////////

template <typename DataType>
void binary_tree::Node<DataType>::right(
    const SharedPtr<binary_tree::Node<DataType>> &node) {
  right_ = node;
}

//////////////////////////////////////////////////////

template <typename DataType>
const DataType &binary_tree::Node<DataType>::data() const {
  return data_;
}

//////////////////////////////////////////////////////

template <typename DataType>
SharedPtr<binary_tree::Node<DataType>> &binary_tree::Node<DataType>::parent() {
  return parent_;
}

//////////////////////////////////////////////////////

template <typename DataType>
SharedPtr<binary_tree::Node<DataType>> &binary_tree::Node<DataType>::left() {
  return left_;
}

//////////////////////////////////////////////////////

template <typename DataType>
SharedPtr<binary_tree::Node<DataType>> &binary_tree::Node<DataType>::right() {
  return right_;
}

//////////////////////////////////////////////////////

template <typename DataType>
bool binary_tree::Node<DataType>::isChild(
    const SharedPtr<binary_tree::Node<DataType>> &node) {
  return ((!isLeafNode()) && (isLeftChild(node) || isRightChild(node)));
}

//////////////////////////////////////////////////////

template <typename DataType>
bool binary_tree::Node<DataType>::isLeftChild(
    const SharedPtr<binary_tree::Node<DataType>> &node) {
  return (node == left_);
}

//////////////////////////////////////////////////////

template <typename DataType>
bool binary_tree::Node<DataType>::isRightChild(
    const SharedPtr<binary_tree::Node<DataType>> &node) {
  return (node == right_);
}

//////////////////////////////////////////////////////

template <typename DataType> bool binary_tree::Node<DataType>::hasLeft() const {
  return bool(left_);
}

//////////////////////////////////////////////////////

template <typename DataType>
bool binary_tree::Node<DataType>::hasRight() const {
  return bool(right_);
}

//////////////////////////////////////////////////////

template <typename DataType>
bool binary_tree::Node<DataType>::hasTwoChildren() const {
  return (hasLeft() && hasRight());
}

//////////////////////////////////////////////////////

template <typename DataType>
bool binary_tree::Node<DataType>::isLeafNode() const {
  return (!(hasLeft() || hasRight()));
}

//////////////////////////////////////////////////////
