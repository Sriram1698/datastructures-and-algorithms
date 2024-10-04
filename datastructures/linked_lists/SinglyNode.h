#include "../memory/Memory.h"

/**
 * @brief The node contains the data and the information about where the next
 *  node is located in the memory
 *
 * @tparam DataType
 */
template <typename DataType> class Node {
public:
  Node(const DataType &dat, const SharedPtr<Node<DataType>> &nxt = nullptr);
  virtual ~Node();

  SharedPtr<Node<DataType>> next() const;
  DataType data() const;

  void next(const SharedPtr<Node<DataType>> nxt);
  void next(const DataType& dat);

  void data(const DataType &dat);

protected:
  DataType data_;
  SharedPtr<Node<DataType>> next_;
};

//////////////////////////////////////////////////////

template <typename DataType>
Node<DataType>::Node(const DataType &dat,
                     const SharedPtr<Node<DataType>> &nxt)
    : data_(dat), next_(nxt) {}

//////////////////////////////////////////////////////

template <typename DataType> Node<DataType>::~Node() = default;

//////////////////////////////////////////////////////

template <typename DataType>
SharedPtr<Node<DataType>> Node<DataType>::next() const {
  return next_;
}

//////////////////////////////////////////////////////

template <typename DataType> DataType Node<DataType>::data() const {
  return data_;
}

//////////////////////////////////////////////////////

template <typename DataType>
void Node<DataType>::next(const SharedPtr<Node<DataType>> nxt) {
  next_ = nxt;
}

//////////////////////////////////////////////////////

template <typename DataType>
void Node<DataType>::next(const DataType& dat)
{
    next_ = MakeShared<Node<DataType> >(dat);
}

//////////////////////////////////////////////////////

template <typename DataType> void Node<DataType>::data(const DataType &dat) {
  data_ = dat;
}

//////////////////////////////////////////////////////