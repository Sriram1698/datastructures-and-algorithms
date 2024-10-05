#pragma once
#include "../linked_lists/LinkedList.h"

template <typename DataType> class Stack {
public:
  Stack();
  Stack(const DataType &data);

  void push(const DataType &data);
  void pop();
  void reverse();

  DataType top() const;
  size_t size() const;
  bool empty() const;

  void print() const;

private:
  LinkedList<DataType> list_;
};

//////////////////////////////////////////////////////

template <typename DataType>
Stack<DataType>::Stack() : list_(LinkedList<DataType>()) {}

//////////////////////////////////////////////////////

template <typename DataType>
Stack<DataType>::Stack(const DataType &data)
    : list_(LinkedList<DataType>(data)) {}

//////////////////////////////////////////////////////

template <typename DataType> void Stack<DataType>::push(const DataType &data) {
  this->list_.insert(data, 0);
}

//////////////////////////////////////////////////////

template <typename DataType> void Stack<DataType>::pop() {
  this->list_.remove(0);
}

//////////////////////////////////////////////////////

template <typename DataType> void Stack<DataType>::reverse() {
  this->list_.reverse();
}
//////////////////////////////////////////////////////

template <typename DataType> DataType Stack<DataType>::top() const {
  return (this->empty()) ? DataType(NULL) : this->list_[0];
}

//////////////////////////////////////////////////////

template <typename DataType> size_t Stack<DataType>::size() const {
  return this->list_.size();
}

//////////////////////////////////////////////////////

template <typename DataType> bool Stack<DataType>::empty() const {
  return this->list_.empty();
}

//////////////////////////////////////////////////////

template <typename DataType> void Stack<DataType>::print() const {
  this->list_.print();
}

//////////////////////////////////////////////////////