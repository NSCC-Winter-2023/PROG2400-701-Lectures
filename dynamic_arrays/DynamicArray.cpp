#include <initializer_list>
#include <cstring>
#include "DynamicArray.h"

DynamicArray::DynamicArray() {

}

DynamicArray::DynamicArray(std::initializer_list<int> nums) {
    // an optimization here to reserve memory could be added
    for (auto n : nums) {
        add(n);
    }
}

DynamicArray::~DynamicArray() {
    delete [] m_array;
}

void DynamicArray::add(int num) {
    int* temp = nullptr;
    if (m_size == m_capacity) {
        // allocate / re-allocate memory for array
        temp = m_array;
        auto old_capacity = m_capacity;
        m_capacity += 5; // desired efficiency
        m_array = new int[m_capacity];

        // copy old data into new array
        // be careful to optimize the copy!
        std::memcpy(m_array, temp, old_capacity * sizeof(m_array[0]));
    }
    m_array[m_size] = num;
    m_size++;

    delete [] temp;
}

std::ostream &operator<<(std::ostream &output, DynamicArray &array) {
    for (int i = 0; i < array.m_size; ++i) {
        std::cout << array.m_array[i] << " ";
    }
    return output;
}

long DynamicArray::size() {
    return m_size;
}

long DynamicArray::capacity() {
    return m_capacity;
}
