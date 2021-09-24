//
// Created by deside_adin on 9/17/21.
//

#ifndef UNTITLED4_VISITOR_H
#define UNTITLED4_VISITOR_H
#include "binary_tree.h"
#include "iterator.h"
template<typename T>
class Visitor{
public:
    virtual void Visit(Binary_Tree<T>* tree) = 0;
    virtual ~Visitor(){}
};
class FindMaxElement:private Visitor<int>{
private:
    int value{-1};
public:
    int GetValue() const;
    void Visit(Binary_Tree<int>*tree) override;
};
class ToSortedVector:private Visitor<int>{
private:
    std::vector<int> temp;
public:
    std::vector<int> GetVector();
    void Visit(Binary_Tree<int>* tree) override;
};
#endif //UNTITLED4_VISITOR_H
