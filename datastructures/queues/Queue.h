#pragma once
#include "../linked_lists/LinkedList.h"

template <typename DataType> class Queue {
public:
  Queue();
  Queue(const DataType &data);

  void push(const DataType &data);
  void pop();
  void reverse();

  DataType front() const;
  size_t size() const;
  bool empty() const;

  void print() const;

private:
  LinkedList<DataType> list_;
};

//////////////////////////////////////////////////////

template <typename DataType>
Queue<DataType>::Queue() : list_(LinkedList<DataType>()) {}

//////////////////////////////////////////////////////

template <typename DataType>
Queue<DataType>::Queue(const DataType &data)
    : list_(LinkedList<DataType>(data)) {}

//////////////////////////////////////////////////////

template <typename DataType> void Queue<DataType>::push(const DataType &data) {
  this->list_.insert(data);
}

//////////////////////////////////////////////////////

template <typename DataType> void Queue<DataType>::pop() {
  this->list_.remove(0);
}

//////////////////////////////////////////////////////

template <typename DataType> void Queue<DataType>::reverse() {
  this->list_.reverse();
}
//////////////////////////////////////////////////////

template <typename DataType> DataType Queue<DataType>::front() const {
  return (this->empty()) ? DataType(NULL) : this->list_[0];
}

//////////////////////////////////////////////////////

template <typename DataType> size_t Queue<DataType>::size() const {
  return this->list_.size();
}

//////////////////////////////////////////////////////

template <typename DataType> bool Queue<DataType>::empty() const {
  return this->list_.empty();
}

//////////////////////////////////////////////////////

template <typename DataType> void Queue<DataType>::print() const {
  this->list_.print();
}

//////////////////////////////////////////////////////