#pragma once
#include "Queue.h"

template <typename DataType> class Deque : public Queue<DataType> {
public:
  Deque();
  Deque(const DataType &data);

  void push_front(const DataType &data);
  void push_back(const DataType &data);

  void pop_front();
  void pop_back();

  void reverse();

  DataType front() const;
  DataType back() const;

  size_t size() const;
  bool empty() const;

  void print() const;
};

//////////////////////////////////////////////////////

template <typename DataType> Deque<DataType>::Deque() : Queue<DataType>() {}

//////////////////////////////////////////////////////

template <typename DataType>
Deque<DataType>::Deque(const DataType &data) : Queue<DataType>(data) {}

//////////////////////////////////////////////////////

template <typename DataType>
void Deque<DataType>::push_front(const DataType &data) {
  this->list_.insert(data, 0);
}

//////////////////////////////////////////////////////

template <typename DataType>
void Deque<DataType>::push_back(const DataType &data) {
  this->list_.insert(data);
}

//////////////////////////////////////////////////////

template <typename DataType> void Deque<DataType>::pop_front() {
  this->list_.remove(0);
}

//////////////////////////////////////////////////////

template <typename DataType> void Deque<DataType>::pop_back() {
  this->list_.remove(this->list_.size() - 1);
}

//////////////////////////////////////////////////////

template <typename DataType> void Deque<DataType>::reverse() {
  this->list_.reverse();
}
//////////////////////////////////////////////////////

template <typename DataType> DataType Deque<DataType>::front() const {
  return (this->empty()) ? DataType(NULL) : this->list_[0];
}

//////////////////////////////////////////////////////

template <typename DataType> DataType Deque<DataType>::back() const {
  return (this->empty()) ? DataType(NULL)
                         : this->list_[this->list_->size() - 1];
}

//////////////////////////////////////////////////////

template <typename DataType> size_t Deque<DataType>::size() const {
  return this->list_.size();
}

//////////////////////////////////////////////////////

template <typename DataType> bool Deque<DataType>::empty() const {
  return this->list_.empty();
}

//////////////////////////////////////////////////////

template <typename DataType> void Deque<DataType>::print() const {
  this->list_.print();
}

//////////////////////////////////////////////////////