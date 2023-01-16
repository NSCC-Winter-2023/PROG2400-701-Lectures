#include <iostream>
#include <vector>
#include "DynamicArray.h"

std::ostream& operator<<(std::ostream& output, const std::vector<int>& v) {
    for (auto& n : v) {
        output << n << " ";
    }
    return output;
}
void operator<<(std::vector<int>& v, const std::vector<int>& in) {
    for (auto& n : in) {
        v.push_back(n);
    }
}
void vector_demo() {

    std::vector<int> nums {1, 2, 3, 4, 5};
    std::cout << nums << std::endl;
    std::cout << "size: " << nums.size() << std::endl;
    std::cout << "capacity: " << nums.capacity() << std::endl;

    nums.push_back(6);
    std::cout << nums << std::endl;
    std::cout << "size: " << nums.size() << std::endl;
    std::cout << "capacity: " << nums.capacity() << std::endl;

    nums << std::vector({7, 8, 9, 10, 11});
    std::cout << nums << std::endl;
    std::cout << "size: " << nums.size() << std::endl;
    std::cout << "capacity: " << nums.capacity() << std::endl;

    // re-allocates memory to the exact and performs another copy
    nums.shrink_to_fit();
    std::cout << nums << std::endl;
    std::cout << "size: " << nums.size() << std::endl;
    std::cout << "capacity: " << nums.capacity() << std::endl;

    // reserve a larger block of memory
    nums.reserve(25);
    std::cout << nums << std::endl;
    std::cout << "size: " << nums.size() << std::endl;
    std::cout << "capacity: " << nums.capacity() << std::endl;
}

int main() {

    // test 1 - create a dynamic array
    DynamicArray nums {1, 2, 3, 4, 5};
    std::cout << nums << std::endl;
    std::cout << "size: " << nums.size() << std::endl;
    std::cout << "capacity: " << nums.capacity() << std::endl;

    // test 2 - add to dynamic array
    nums.add(6);
    std::cout << nums << std::endl;
    std::cout << "size: " << nums.size() << std::endl;
    std::cout << "capacity: " << nums.capacity() << std::endl;

    return 0;
}