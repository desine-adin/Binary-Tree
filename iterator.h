//
// Created by deside_adin on 9/17/21.
//

#ifndef UNTITLED4_ITERATOR_H
#define UNTITLED4_ITERATOR_H

#include "binary_tree.h"

template<typename T>
class Binary_Tree<T>::Iterator {
private:
    T *cur;
    int index;
    Binary_Tree<T> *BT;
public:

    Iterator(Binary_Tree<T> *BT_, T *first) : BT(BT_), cur(first) {
        index = BT->FindElementPosition(*cur);
    }

    Iterator(const Iterator &temp) : cur(temp.cur), index(temp.index), BT(temp.BT) {
    }

    T &operator++(int) {
        T *curreal = cur;
        if (BT->data_[2 * index + 2] != -1) {
            index = 2 * index + 2;
        } else if (index % 2 == 1) {
            index = (index - 1) / 2;
        } else if (index % 2 == 0) {
            while (index % 2 == 0) {
                index = (index - 2) / 2;
                if (index == 0) {
                    std::cout << "Memory mistake";
                    std::exit(1);
                }
            }
            index = (index - 1) / 2;
        }
        cur = &BT->data_[index];
        return *curreal;
    }

    T &operator--(int) {
        T *curreal = cur;
        if (BT->data_[2 * index + 1] != -1) {
            index = 2 * index + 1;
        } else if (index % 2 == 0) {
            index = (index - 2) / 2;
        } else if (index % 2 == 1) {
            while (index % 2 == 1) {
                index = (index - 1) / 2;
                if (index == 0) {
                    std::cout << "Memory mistake";
                    std::exit(1);
                }
            }
            index = (index - 2) / 2;
        }
        cur = &BT->data_[index];
        return *curreal;
    }

    T &operator--() {
        if (BT->data_[2 * index + 1] != -1) {
            index = 2 * index + 1;
        } else if (index % 2 == 0) {
            index = (index - 2) / 2;
        } else if (index % 2 == 1) {
            while (index % 2 == 1) {
                index = (index - 1) / 2;
                if (index == 0) {
                    std::cout << "Memory mistake";
                    std::exit(1);
                }
            }
            index = (index - 2) / 2;
        }
        cur = &BT->data_[index];
        return *cur;
    }

    T &operator++() {
        if (BT->data_[2 * index + 2] != -1) {
            index = 2 * index + 2;
        } else if (index % 2 == 1) {
            index = (index - 1) / 2;
        } else if (index % 2 == 0) {
            while (index % 2 == 0) {
                index = (index - 2) / 2;
                if (index == 0) {
                    std::cout << "Memory mistake";
                    std::exit(1);
                }
            }
            index = (index - 1) / 2;
        }
        cur = &BT->data_[index];
        return *cur;
    }

    bool operator!=(const Iterator &it) {
        return cur != it.cur;
    }

    bool operator==(const Iterator &it) {
        return cur == it.cur;
    }

    T &operator*() {
        return *cur;
    }
};

#endif //UNTITLED4_ITERATOR_H
