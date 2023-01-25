#include <iostream>

class LinkedListNode {
public:
    int m_data{-1};
    LinkedListNode* m_next{nullptr};
};

class LinkedList {
private:
    LinkedListNode* m_start{nullptr};
    int m_size{0};
public:
    LinkedList() {}
    virtual ~LinkedList() {
        auto node = m_start;
        while (node != nullptr) {
            auto temp = node;
            node = node->m_next;
            delete temp;
        }
    }

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

        m_size++;
    }

    void insert(int data, int index) {

        if (index >= m_size) {
            return add(data);
        }

        // create a new node
        auto node = new LinkedListNode();
        node->m_data = data;

        // find the index we are inserting before
        auto curr = m_start;
        LinkedListNode* prev = nullptr;

        auto count{1};
        while (curr != nullptr) {
            if (count++ == index) {
                break;
            }
            prev = curr;
            curr = curr->m_next;
        }

        // am I inserting at the beginning?
        if (prev == nullptr) {
            // insert at the start of the list
            node->m_next = m_start;
            m_start = node;
        } else {
            // inserting in the middle of the list
            node->m_next = prev->m_next;
            prev->m_next = node;
        }

        m_size++;
    }

    void remove(int index) {

        // find the node to delete
        auto node = m_start;
        LinkedListNode* prev = nullptr;

        auto count{1};
        while (node != nullptr) {
            // look for the desired index
            if (count++ == index) {
                break;
            }
            prev = node;
            node = node->m_next;
        }

        // did we find the node we are looking for?
        if (node != nullptr) {

            // am I deleting the first node?
            if (prev == nullptr) {
                // first node
                m_start = node->m_next;
            } else {
                // other node
                prev->m_next = node->m_next;
            }

            // finally!
            delete node;

            m_size--;
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

    // test 4 - delete the first node in the list
    list.remove(1);

    std::cout << "Test 4 - remove a node from the start of the list" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 5 - add more nodes to list
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);

    std::cout << "Test 5 - added more nodes to the list" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 6 - remove the last node from the list
    list.remove(5);

    std::cout << "Test 6 - remove the last node from the list" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 7 - remove a node from the middle of the list
    list.remove(2);

    std::cout << "Test 7 - remove from the middle of the list" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 8 - insert a node at the beginning of the list
    list.insert(10, 1); // insert 10 at node index 1

    std::cout << "Test 8 - insert at the beginning of the list" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 9 - insert a node in the middle of the list
    list.insert(20, 3); // insert 20 at node index 3

    std::cout << "Test 9 - insert in the middle of the list" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 10 - insert a node at the end of the list
    list.insert(30, 10); // insert 30 at node index 10

    std::cout << "Test 10 - insert at the end of the list" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << list << std::endl;
    return 0;
}