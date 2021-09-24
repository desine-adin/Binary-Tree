#include <iostream>
#include <initializer_list>
#include <vector>
#include <cassert>

#include "iterator.h"
#include "binary_tree.cpp"
#include "visitor.cpp"
int FindMaxElement::GetValue() const {
    return value;
}
void FindMaxElement::Visit(Binary_Tree<int> *tree) {
    auto it = Binary_Tree<int>::Iterator(tree->end());
    value = *it;
}
std::vector<int> ToSortedVector::GetVector() {
    return temp;
}
void ToSortedVector::Visit(Binary_Tree<int> *tree) {
    auto it = Binary_Tree<int>::Iterator(tree->begin());
    while(it!=tree->end()){
        temp.push_back(*it);
        it++;
    }
    temp.push_back(*it);
}
int main() {
    Binary_Tree<int> a{1,2,3,4,5,6,7,8,9};
    FindMaxElement b;
    b.Visit(&a);
    std::cout << b.GetValue();
    std::vector <int> i;
    ToSortedVector c;
    c.Visit(&a);
    i=c.GetVector();
    for (int j=0;j<i.size();++j){
        std::cout << i[j] << " ";
    }
}