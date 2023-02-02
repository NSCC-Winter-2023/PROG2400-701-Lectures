#include <iostream>
#include <memory>

#if 0
struct Data {
    int m_num {-1};
};

class SmartPtr {
private:
    Data* m_data {nullptr};
public:
    SmartPtr(int num) {
        m_data = new Data();
        m_data->m_num;
    }
    ~SmartPtr() {
        delete m_data;
    }
    static SmartPtr make_ptr(int num) {
        auto ptr = SmartPtr(-1);
        ptr.m_data = new Data();
        ptr.m_data->m_num = num;
    }
};
#endif

struct Node {
    int m_data {-1};
    std::unique_ptr<Node> m_next {nullptr};
};

class Queue {
private:
    std::unique_ptr<Node> m_first {nullptr};
    Node* m_last {nullptr};

public:
    void push(int data) {
        auto node = std::make_unique<Node>();
        node.get()->m_data = data;

        // check if first node
        if (m_first == nullptr) {
            // first node
            m_first = std::move(node);
            m_last = m_first.get();
        } else {
            // add to existing linked list
            m_last->m_next = std::move(node);
            m_last = m_last->m_next.get();
        }
    }

    int peek() {
        // is there a first node?
        if (m_first == nullptr) {
            return -1;
        }
        return m_first->m_data;
    }

    int pop() {
        // always remove from the start of the queue
        auto node = std::move(m_first);

        // check for empty queue
        if (node == nullptr) {
            return -1;
        }

        // detach node
        m_first = std::move(node->m_next);

        // hold data for return
        int data = node->m_data;

        // we are passing ownership of the data as well!
        return data;
    }

    friend std::ostream& operator<<(std::ostream& output, Queue& queue) {
        auto node = queue.m_first.get();
        while (node != nullptr) {
            std::cout << node->m_data << " ";
            node = node->m_next.get();
        }
        return output;
    }
};


int main() {

    Queue queue;

    // test 1 - add node to queue
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    // test 1 - add nodes
    std::cout << "Test 1 - add new nodes" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << queue << std::endl << std::endl;

    // test 2 - look at value of first node
    std::cout << "Test 2 - peek at first node" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << queue.peek() << std::endl;
    std::cout << queue << std::endl << std::endl;

    // test 3 - remove node from queue
    std::cout << "Test 3 - pop first node" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue << std::endl << std::endl;

    // test 4 - process the entire queue
    std::cout << "Test 4 - process all nodes" << std::endl;
    std::cout << "--------------------------" << std::endl;

    while (queue.peek() != -1) {
        std::cout << queue.pop() << std::endl;
        std::cout << queue << std::endl;
    }

    return 0;
}