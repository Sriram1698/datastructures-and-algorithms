#pragma once

#include "SinglyNode.h"

/**
 * @brief The doubly node contains what ever the node contains with an
 * additional information of where the previous node is located in the memory
 *
 * @tparam DataType
 */
template <typename DataType> class DoublyNode : public Node<DataType> {
public:
  DoublyNode(const DataType &dat,
             const SharedPtr<DoublyNode<DataType>> &nxt = nullptr,
             const SharedPtr<DoublyNode<DataType>> &prv = nullptr);

  virtual ~DoublyNode();

  void prev(const SharedPtr<DoublyNode<DataType>> prv);
  void prev(const DataType &dat);

  SharedPtr<DoublyNode<DataType>> prev() const;

protected:
  SharedPtr<DoublyNode<DataType>> prev_;
};

//////////////////////////////////////////////////////

template <typename DataType>
DoublyNode<DataType>::DoublyNode(
    const DataType &dat, const SharedPtr<DoublyNode<DataType>> &nxt = nullptr,
    const SharedPtr<DoublyNode<DataType>> &prv = nullptr)
    : Node<DataType>(dat, nxt), prev_(prv) {}

//////////////////////////////////////////////////////

template <typename DataType> DoublyNode<DataType>::~DoublyNode() = default;

//////////////////////////////////////////////////////

template <typename DataType>
void DoublyNode<DataType>::prev(const SharedPtr<DoublyNode<DataType>> prv) {
  prev_ = prv;
}

//////////////////////////////////////////////////////

template <typename DataType>
void DoublyNode<DataType>::prev(const DataType &dat) {
  prev_ = MakeShared<DoublyNode<DataType>>(dat);
}

//////////////////////////////////////////////////////

template <typename DataType>
SharedPtr<DoublyNode<DataType>> DoublyNode<DataType>::prev() const {
  return prev_;
}

//////////////////////////////////////////////////////