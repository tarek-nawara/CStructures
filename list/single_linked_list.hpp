#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cassert>
#include "linked_list.hpp"

namespace list {

  template<typename T>
  class SingleLinkedList : public LinkedList<T> {
  public:
    int size() override;
    void Add(const T e) override;
    void Add(const T e, const int index) override;
    void Remove(const int index) override;
    bool empty() override;
  private:
    struct Node {
      T data;
      Node* next;
    };
    Node* head_ = nullptr;
    int size_;
  };

  template<typename T>
  int SingleLinkedList<T>::size() {
    return this->size_;
  }

  template<typename T>
  void SingleLinkedList<T>::Add(const T e) {
    Node node = { e, head_ };
    head_ = &node;
    ++size_;
  }

  template<typename T>
  void SingleLinkedList<T>::Add(const T e, const int index) {
  }

  template<typename T>
  void SingleLinkedList<T>::Remove(const int index) {
  }

  template<typename T>
  bool SingleLinkedList<T>::empty() {
    return size_ == 0;
  }

}

#endif //SINGLE_LINKED_LIST
