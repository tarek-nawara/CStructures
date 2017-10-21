#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace list {

  template<typename T>
  class LinkedList {
  public:
    virtual int size() = 0;
    virtual void Add(const T e) = 0;
    virtual void Add(const T e, const int index) = 0;
    virtual void Remove(const int index) = 0;
    virtual bool empty() = 0;
  };

} // end namespace list

#endif // LINKED_LIST_H

