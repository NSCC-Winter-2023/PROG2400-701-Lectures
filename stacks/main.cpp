#include <iostream>

struct Student {
    std::string m_id;
    std::string m_name;
};

struct Node {
    Student m_data;
    Node* m_next {nullptr};
};

class Stack {
private:
    Node* m_first {nullptr};
public:
    ~Stack() {
#if 0
        auto node = m_first;
        while (node != nullptr) {
            auto temp = node;
            node = node->m_next;
            delete temp;
        }
#endif
        while (m_first != nullptr) {
            pop();
        }
    }
    void push(Student s) {
        // create a new node
        auto node = new Node();
        node->m_data = std::move(s);
        node->m_next = m_first;
        m_first = node;
    }

    void pop() {
        // remove the first node

        // check for empty stack
        if (m_first == nullptr) {
            // maybe throw exception, print message or do nothing....
            return;
        }

        // one node exists
        auto node = m_first;
        m_first = m_first->m_next;
        delete node;
    }

    Student peek() {
        if (m_first == nullptr) return {"W999999","EMPTY STACK"};
        return m_first->m_data;
    }

    friend std::ostream& operator<<(std::ostream& output, Stack& stack) {
        auto node = stack.m_first;
        while (node != nullptr) {
            output << "Name: " << node->m_data.m_name << ", ";
            output << "ID: " << node->m_data.m_id << std::endl;
            node = node->m_next;
        }
        return output;
    }
};

int main() {

    // test 1 - adding nodes to stack
    Stack stack;

    stack.push({"W111222", "John"});
    stack.push({"W222333", "Jane"});
    stack.push({"W333444", "Jill"});
    stack.push({"W444555", "Jack"});
    stack.push({"W555666", "Jeff"});

    std::cout << "Test 1 - add nodes to stack" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << stack << std::endl;

    // test 2 - removing nodes from stack
    stack.pop();

    std::cout << "Test 2 - remove node from stack" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << stack << std::endl;

    // test 3 - retrieve data from top of stack
    auto student = stack.peek();

    std::cout << "Test 3 - retrieve data from stack" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Name: " << student.m_name << ", ";
    std::cout << "ID: " << student.m_id << std::endl;

    return 0;
}