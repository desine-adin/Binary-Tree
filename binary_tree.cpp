//
// Created by deside_adin on 9/17/21.
//
#ifndef UNTITLED4_BINARY_TREE_CPP
#define UNTITLED4_BINARY_TREE_CPP
#include "binary_tree.h"
template<typename T>
void Binary_Tree<T>::IncreasedCapacity() {
    capacity_ = capacity_ * GROWTH_FACTOR;
    T *buf = new T[capacity_];
    for (size_t i = 0; i < capacity_ / GROWTH_FACTOR; ++i) {
        buf[i] = data_[i];
    }
    for (int i = capacity_ / GROWTH_FACTOR; i < capacity_; ++i) {
        buf[i] = -1;
    }
    delete data_;
    data_ = buf;
    buf = nullptr;
}
template<typename T>
Binary_Tree<T>::Binary_Tree() {
    size_ = 0;
    capacity_ = MIN_CAPACITY;
    data_ = new T[capacity_];
    for (int i = 0; i < capacity_; ++i) {
        data_[i] = -1;
    }
}
template<typename T>
void Binary_Tree<T>::Push(const T &value) {
    int i = 0;
    while (data_[i] != -1) {
        if (value >= data_[i]) {
            i = 2 * i + 2;
        } else {
            i = 2 * i + 1;
        }
        if (2 * i + 2 >= capacity_ - 1) {
            IncreasedCapacity();
        }
    }
    data_[i] = value;
    size_++;
}
template<typename T>
Binary_Tree<T>::Binary_Tree(const std::initializer_list<T> &list) {
    capacity_ = MIN_CAPACITY;
    data_ = new T[capacity_];
    for (int i = 0; i < capacity_; ++i) {
        data_[i] = -1;
    }
    for (auto &value: list) {
        Push(value);
    }
}
template<typename T>
Binary_Tree<T>::Binary_Tree(const Binary_Tree<T> &list) {
    size_ = list.size_;
    capacity_ = list.capacity_;
    data_ = new T[capacity_];
    for (int i = 0; i < capacity_; i++) {
        data_[i] = list.data_[i];
    }
}
template <typename T>
Binary_Tree<T> &Binary_Tree<T>::operator=(const Binary_Tree<T> &list) {
    if (data_ != nullptr) {
        delete[] data_;
    }
    size_ = list.size_;
    capacity_ = list.capacity_;
    data_ = new T[capacity_];
    for (int i = 0; i < capacity_; i++) {
        data_[i] = list.data_[i];
    }
}
template<typename T>
Binary_Tree<T>::Binary_Tree (Binary_Tree<T> &&input) noexcept {
    *this = std::move(input);
}
template <typename T>
Binary_Tree<T> &Binary_Tree<T>::operator=(Binary_Tree<T> &&rhs) noexcept {
    if (this != &rhs) {
        if (data_ != nullptr) {
            delete[] data_;
        }
        size_ = std::move(rhs.size_);
        capacity_ = std::move(rhs.capacity_);
        rhs.size_=0;
        rhs.capacity_=MIN_CAPACITY;
        data_ = rhs.data_;
        rhs.data_= nullptr;
    }
    return *this;
}
template<typename T>
Binary_Tree<T>::~Binary_Tree() {
    delete[] data_;
}
template <typename T>
int Binary_Tree<T>::Size() const {
    return size_;
}
template<typename T>
bool Binary_Tree<T>::IsEmpty() const {
    return (size_ == 0);
}
template<typename T>
int Binary_Tree<T>::FindElementPosition(T &value) {
    int i = 0;
    while (data_[i] != value) {
        if (data_[i] > value) {
            i = i * 2 + 1;
        } else {
            i = 2 * i + 2;
        }
        if (i >= capacity_) {
            i = -1;
            break;
        }
    }
    return i;
}
template<typename T>
void Binary_Tree<T>::ToVector(std::vector<T> &temp, int index_of_root) const {
    if (data_[index_of_root * 2 + 1] != -1) {
        ToVector(temp, index_of_root * 2 + 1);
    }
    temp.push_back(data_[index_of_root]);
    if (data_[index_of_root * 2 + 2] != -1) {
        ToVector(temp, index_of_root * 2 + 2);
    }
}
template<typename T>
T *Binary_Tree<T>::Root() const {
    return data_;
}
template<typename T>
typename Binary_Tree<T>::Iterator Binary_Tree<T>::begin() {
    T *first;
    int i = 0;
    while (data_[i * 2 + 1] != -1) {
        i = i * 2 + 1;
    }
    first = &data_[i];
    Iterator it(this, first);
    return it;
}
template<typename T>
typename Binary_Tree<T>::Iterator Binary_Tree<T>::end() {
    T *end;
    int i = 0;
    while (data_[i * 2 + 2] != -1) {
        i = i * 2 + 2;
    }
    end = &data_[i];
    Iterator it(this, end);
    return it;
}
#endif //UNTITLED4_BINARY_TREE_CPP