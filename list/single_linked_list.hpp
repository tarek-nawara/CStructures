#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>
#include <cassert>
#include <functional>

#include "linked_list.hpp"

namespace list {

  template<typename T>
  class SingleLinkedList : public LinkedList<T> {
  public:
    // Get the size of the
    // linked list.
    int size() const override;

    // Add element to the beginning
    // of the list.
    void add(const T e) override;

    // Add element to the given index
    // of the list, the element's index
    // will be the given index.
    void add(const T e, const int index) override;

    // Remove element at the given index
    // from the list.
    void remove(const int index) override;

    // Test wither the given list
    // is empty or not.
    bool empty() const override;

    // Apply a transformation function over
    // the elements of this list.
    template<typename U>
    void map(const std::function<U (T)> mapper);

    // Apply a predicate over the elements
    // of this list, only keep elements
    // satisfy the predicate.
    void filter(const std::function<bool (T)> predicate);

    // Get the element of the list
    // at the given index.
    T operator[](int index) const;

    template<typename A>
    friend std::ostream& operator<<(std::ostream&, const SingleLinkedList<A>&);

  private:
    struct Node {
      T data;
      Node* next;
      Node(T data, Node* next = nullptr) :
        data(data), next(next) {}
    };
    void removeHead();
    Node* head_ = nullptr;
    int size_ = 0;
  };

  template<typename T>
  int SingleLinkedList<T>::size() const {
    return this->size_;
  }

  template<typename T>
  void SingleLinkedList<T>::add(const T e) {
    Node* node = new Node(e, head_);
    head_ = node;
    ++size_;
  }

  template<typename T>
  void SingleLinkedList<T>::add(const T e, const int index) {
    assert(index >= 0 && index <= size_);
    Node* node = new Node(e);
    Node* current = head_;
    for (int i = 0; i < index; ++i) {
      current = current->next;
    }
    node->next = current->next;
    current->next = node;
    ++size_;
  }

  template<typename T>
  void SingleLinkedList<T>::remove(const int index) {
    assert(index >= 0 && index < size_);
    if (index == 0) {
      this->removeHead();
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
  void SingleLinkedList<T>::removeHead() {
    if (head_ == nullptr) return;
    head_ = head_->next;
    --size_;
  }

  template<typename T>
  bool SingleLinkedList<T>::empty() const {
    return size_ == 0;
  }

  template<typename T>
  template<typename U>
  void SingleLinkedList<T>::map(const std::function<U (T)> mapper) {
    for (Node* current = head_; current != nullptr; current = current->next) {
      current->data = f(current->data);
    }
  }

  template<typename T>
  void SingleLinkedList<T>::filter(const std::function<bool (T)> predicate) {
    SingleLinkedList<T>* newList = new SingleLinkedList<T>();
    for (Node* current = head_; current != nullptr; current = current->next) {
      if (predicate(current->data)) {
        newList->add(current->data);
      }
    }
    this->head_ = newList->head_;
    this->size_ = newList->size_;
  }

  template<typename T>
  T SingleLinkedList<T>::operator[](int index) const {
    assert(index >= 0 && index < size_);
    Node* current = head_;
    for (int i = 0; i < index; ++i) {
      current = current->next;
    }
    return current->data;
  }

  template<typename T>
  inline std::ostream& operator<<(std::ostream& out, const SingleLinkedList<T>& list) {
    out << "[";
    for (int i = 0; i < list.size(); ++i) {
      if (i > 0) out << ",";
      out << list[i];
    }
    out << "]";
    return out;
  }

}

#endif //SINGLE_LINKED_LIST
