#ifndef _DYNAMIC_ARRAY_H
#define _DYNAMIC_ARRAY_H

#include <iostream>

class DynamicArray {
private:
    int* m_array{nullptr};
    int m_size{0};
    int m_capacity{0};
public:
    DynamicArray();
    DynamicArray(std::initializer_list<int> nums);
    virtual ~DynamicArray();

    void add(int num);

    friend std::ostream& operator<<(std::ostream& output, DynamicArray& array);

    long size();
    long capacity();
};

#endif