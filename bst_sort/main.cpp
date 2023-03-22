#include <iostream>
#include <span>
#include <iomanip>
#include "binary_search_tree.h"

void bst_sort(std::span<int> array) {

    BST bst;

    for (int i = 0; i < array.size(); ++i) {
        bst.insert(array[i]);
    }

    bst.save_as_array(array);
}

void dump_array(std::span<int> array) {
    for (int i : array) {
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;
}

int main() {

    auto nums = std::to_array({3, 6, 8, 10, 5, 9, 4, 1, 2, 7});

    std::cout << "Before Sorting ..." << std::endl;
    dump_array(nums);

    bst_sort(nums);

    std::cout << "After Sorting ..." << std::endl;
    dump_array(nums);

    return 0;
}