//
// Created by deside_adin on 9/17/21.
//

#ifndef UNTITLED4_BINARY_TREE_H
#define UNTITLED4_BINARY_TREE_H

#include <iostream>
#include <initializer_list>
#include <vector>
#include <cassert>
template<typename T>
class Binary_Tree {
private:
    T *data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 10;
    static const size_t MIN_CAPACITY = 10;
    static const size_t GROWTH_FACTOR = 3;

    /*void Clear() {
        while (size_ != 0) {
            PopBack();
        }
    }*/
    void IncreasedCapacity();

public:
    Binary_Tree();

    void Push(const T &value);

    Binary_Tree(const std::initializer_list<T> &list);

    Binary_Tree(const Binary_Tree<T> &list);

    Binary_Tree<T> &operator=(const Binary_Tree<T> &list);

    Binary_Tree(Binary_Tree<T> &&input) noexcept;

    Binary_Tree<T> &operator=(Binary_Tree<T> &&rhs) noexcept;

    ~Binary_Tree();

    int Size() const;

    bool IsEmpty() const;

    int FindElementPosition(T &value);

    void ToVector(std::vector<T> &temp, int index_of_root = 0) const;

    T *Root() const;

    class Iterator;

    Iterator begin();

    Iterator end();

    friend class Iterator;
};
#endif //UNTITLED4_BINARY_TREE_H
