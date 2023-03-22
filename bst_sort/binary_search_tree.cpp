#include "binary_search_tree.h"

void BST::insert(int num) {
    insert(num, m_root);
}

void BST::insert(int num, NodePtr &node) {
    if (node == nullptr) {
        node = new Node();
        node->m_data = num;
    } else if (num < node->m_data) {
        // go left
        insert(num, node->m_left);
    } else if (num > node->m_data) {
        // go right
        insert(num, node->m_right);
    } else {
        // duplicate value
        std::cout << "Duplicate: " << num << std::endl;
    }
}

void BST::save_as_array(std::span<int> array) {
    save_as_array(array, m_root);
}

void BST::save_as_array(std::span<int> array, NodePtr node) {
    // position in the array to store the values
    static int i = 0;

    if (node != nullptr) {
        save_as_array(array, node->m_right);
        array[i++] = node->m_data;
        save_as_array(array, node->m_left);
    }
}