#pragma once

#include "SinglyNode.h"

template <typename DataType> class LinkedList {
public:
  LinkedList();
  LinkedList(const DataType &data);

  template <typename Iterator> LinkedList(Iterator begin, Iterator end);

  virtual ~LinkedList();

  virtual void insert(const DataType &data);
  virtual void insert(const DataType &data, const uint64_t index);

  virtual void erase(const DataType &data);

  virtual bool empty() const;
  virtual size_t size() const;

  virtual void print() const;

protected:
  void incrementSize();
  void decrementSize();

  SharedPtr<Node<DataType>> head_;
  size_t size_;
};

//////////////////////////////////////////////////////

template <typename DataType>
LinkedList<DataType>::LinkedList() : head_(nullptr), size_(0) {}

//////////////////////////////////////////////////////

template <typename DataType>
LinkedList<DataType>::LinkedList(const DataType &data)
    : head_(MakeShared<Node<DataType>>(data)), size_(1) {}

//////////////////////////////////////////////////////

template <typename DataType>
template <typename Iterator>
LinkedList<DataType>::LinkedList(Iterator begin, Iterator end)
    : head_(nullptr), size_(0) {
  if (begin == end) {
    return;
  }

  for (auto it = begin; it != end; ++it) {
    this->insert(*it);
  }
}

//////////////////////////////////////////////////////

template <typename DataType> LinkedList<DataType>::~LinkedList() = default;

//////////////////////////////////////////////////////

template <typename DataType>
void LinkedList<DataType>::insert(const DataType &data) {
  if (head_) {
    SharedPtr<Node<DataType>> current = head_;
    while (current->next()) {
      current = current->next();
    }
    current->next(data);
  } else {
    head_ = MakeShared<Node<DataType>>(data);
  }
  this->incrementSize();
}

//////////////////////////////////////////////////////

template <typename DataType>
void LinkedList<DataType>::insert(const DataType &data, const uint64_t index) {
  if (index > this->size()) {
    return;
  }
  if (head_) {
    SharedPtr<Node<DataType>> current = head_;
    SharedPtr<Node<DataType>> prev = nullptr;
    int index_counter = 0;
    while (current) {
      if (index == index_counter) {
        break;
      }
      prev = current;
      current = current->next();
      index_counter++;
    }
    if (prev) {
      SharedPtr<Node<DataType>> temp = current;
      prev->next(data);
      SharedPtr<Node<DataType>> current = prev->next();
      current->next(temp);
    } else {
      head_ = MakeShared<Node<DataType>>(data);
      head_->next(current);
    }
  } else {
    head_ = MakeShared<Node<DataType>>(data);
  }
  this->incrementSize();
}

//////////////////////////////////////////////////////

template <typename DataType>
void LinkedList<DataType>::erase(const DataType &data) {
  if (size_ == 0) {
    return;
  }
  SharedPtr<Node<DataType>> current = head_;
  SharedPtr<Node<DataType>> prev = nullptr;
  while (current) {
    if (current->data() == data) {
      if (prev) {
        prev->next(current->next());
      } else {
        head_ = current->next();
      }
      this->decrementSize();
      break;
    }
    prev = current;
    current = current->next();
  }
}

//////////////////////////////////////////////////////

template <typename DataType> bool LinkedList<DataType>::empty() const {
  return (this->size() <= 0);
}

//////////////////////////////////////////////////////

template <typename DataType> size_t LinkedList<DataType>::size() const {
  return size_;
}

//////////////////////////////////////////////////////

template <typename DataType> void LinkedList<DataType>::incrementSize() {
  size_++;
}

//////////////////////////////////////////////////////

template <typename DataType> void LinkedList<DataType>::decrementSize() {
  if (!this->empty()) {
    size_--;
  }
}

//////////////////////////////////////////////////////

template <typename DataType> void LinkedList<DataType>::print() const {
  std::cout << "[ ";
  auto current = head_;
  while (current) {
    std::cout << current->data() << ", ";
    current = current->next();
  }
  std::cout << "]" << std::endl;
}

//////////////////////////////////////////////////////