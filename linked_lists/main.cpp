#include <iostream>

class LinkedListNode {
public:
    int m_data{-1};
    LinkedListNode* m_next{nullptr};
};

class LinkedList {
private:
    LinkedListNode* m_start{nullptr};
public:
    LinkedList() {}

    void add(int num) {
        // create a new node
        auto node = new LinkedListNode();
        node->m_data = num;

        if (m_start == nullptr) {
            // add the first node to the list
            m_start = node;
        } else {
            // add to the end of the list
            LinkedListNode* curr = m_start;
            LinkedListNode* prev = nullptr;

            // look for the end of the chain
            while (curr != nullptr) {
                prev = curr;
                curr = curr->m_next;
            }

            // attach the new node
            prev->m_next = node;
        }
    }

    friend std::ostream& operator<<(std::ostream& output, LinkedList& list);
};

std::ostream& operator<<(std::ostream& output, LinkedList& list) {
    auto node = list.m_start;
    while (node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }
    return output;
}

int main() {

    // test 1 - create a new linked list
    LinkedList list;

    std::cout << "Test 1 - create new linked list" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 2 - add one number to an empty linked list
    list.add(1);

    std::cout << "Test 2 - add a number to the beginning of the list" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 3 - add one to an existing linked list
    list.add(2);

    std::cout << "Test 3 - add a number to the end of the list" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << list << std::endl;

    return 0;
}