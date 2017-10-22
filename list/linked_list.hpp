#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <functional>

namespace list {

  template<typename T>
  class LinkedList {
  public:
    virtual int size() const = 0;
    virtual void add(const T e) = 0;
    virtual void add(const T e, const int index) = 0;
    virtual void remove(const int index) = 0;
    virtual bool empty() const = 0;
    template<typename U>
    void map(const std::function<U (T)> f);
    void filter(const std::function<T (bool)> predicate);
  };

} // end namespace list

#endif // LINKED_LIST_H

