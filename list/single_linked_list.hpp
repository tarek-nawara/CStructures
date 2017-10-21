#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cassert>
#include "linked_list.hpp"

namespace list {

  template<typename T>
  class SingleLinkedList : public LinkedList<T> {
  public:
    // Get the size of the
    // linked list.
    int size() override;

    // Add element to the beginning
    // of the list.
    void Add(const T e) override;

    // Add element to the given index
    // of the list, the element's index
    // will be the given index.
    void Add(const T e, const int index) override;

    // Remove element at the given index
    // from the list.
    void Remove(const int index) override;

    // Test wither the given list
    // is empty or not.
    bool empty() override;
  private:
    struct Node {
      T data;
      Node* next;
    };
    void RemoveHead();
    Node* head_ = nullptr;
    int size_ = 0;
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
    assert(index >= 0 && index <= size_);
    Node node = { e, nullptr };
    Node* current = head_;
    for (int i = 0; i < index; ++i) {
      current = current->next;
    }
    node.next = current->next;
    current->next = &node;
    ++size_;
  }

  template<typename T>
  void SingleLinkedList<T>::Remove(const int index) {
    assert(index >= 0 && index < size_);
    if (index == 0) {
      this->RemoveHead();
      return;
    }
    Node* current = head_;
    for (int i = 0; i < index - 1; ++i) {
      current = current->next;
    }
    current->next = current->next->next;
    --size_;
  }

  template<typename T>
  void SingleLinkedList<T>::RemoveHead() {
    if (head_ == nullptr) return;
    head_ = head_->next;
    --size_;
  }

  template<typename T>
  bool SingleLinkedList<T>::empty() {
    return size_ == 0;
  }

}

#endif //SINGLE_LINKED_LIST
