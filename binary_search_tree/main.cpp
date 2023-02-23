#include <iostream>
#include <iomanip>

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
    void insert(int num) {
        insert(num, m_root);
    }

    void remove(int num) {

        // find the node to delete
        NodePtr node = m_root;
        NodePtr parent = nullptr;

        while (node != nullptr) {
            if (num < node->m_data) {
                parent = node;
                node = node->m_left;
            } else if (num > node->m_data) {
                parent = node;
                node = node->m_right;
            } else {
                // found the node!
                break;
            }
        }

        // if we can't find the node, nothing to do!
        if (node == nullptr) return;

        // if the node has two children,
        // use the right-most node in the left tree
        // as a successor
        if (node->m_left != nullptr && node->m_right != nullptr) {
            // start at the left tree
            NodePtr successor = node->m_left;

            // go right as far as possible
            parent = node;
            while(successor->m_right != nullptr) {
                parent = successor;
                successor = successor->m_right;
            }

            // swap node data with successor
            node->m_data = successor->m_data;

            // swap node with successor
            node = successor;
        }

        // assume we have a left child
        NodePtr subtree = node->m_left;

        // if not there, it must be on the right
        if (subtree == nullptr) {
            subtree = node->m_right;
        }

        // delete the node
        if (parent == nullptr) {
            // deleting the parent node
            m_root = subtree;
        } else {
            // deleting a child node

            // check which of the parent's pointers we are
            // attached to
            if (node == parent->m_left) {
                // attached to the left side
                parent->m_left = subtree;
            } else {
                // attached to the right side
                parent->m_right = subtree;
            }
        }

        delete node;
    }

    friend std::ostream& operator<<(std::ostream& output, BST& bst) {
        bst.print_tree(output, bst.m_root, 0);
        return output;
    }

private:
    void insert(int num, NodePtr& node) {
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

    void print_tree(std::ostream& output, NodePtr& node, int indent) {
        if (node != nullptr) {
            print_tree(output, node->m_right, indent + 8);
            output << std::setw(indent) << node->m_data << std::endl;
            print_tree(output, node->m_left, indent + 8);
        }
    }
};

int main() {

    BST bst;

    // test 1 - add nodes to the tree
    std::cout << "Test 1 - adding nodes" << std::endl;
    std::cout << "---------------------" << std::endl;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    std::cout << bst << std::endl;

    // test 2 - remove a node with no children
    std::cout << std::endl;
    std::cout << "Test 2 - delete node with no children" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    bst.remove(2);

    std::cout << bst << std::endl;

    // test 3 - remove a node with one child
    std::cout << std::endl;
    std::cout << "Test 3 - delete node with one child" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    bst.remove(3);

    std::cout << bst << std::endl;

    // test 4 - remove a node with two children
    std::cout << std::endl;
    std::cout << "Test 4 - delete node with two children" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    bst.remove(7);

    std::cout << bst << std::endl;

    return 0;
}