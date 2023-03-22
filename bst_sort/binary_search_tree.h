#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#include <iostream>
#include <span>

struct Node;

using NodePtr = Node*;

struct Node {
    int m_data {-1};
    NodePtr m_left {nullptr};
    NodePtr m_right {nullptr};
};

class BST {
private:
    NodePtr m_root {nullptr};

public:
    void insert(int num);
    void save_as_array(std::span<int> array);
private:
    void insert(int num, NodePtr& node);
    void save_as_array(std::span<int> array, NodePtr node);
};


#endif