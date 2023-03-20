#include <iostream>
#include <iomanip>
#include <span>

void selection_sort(std::span<int> array) {
    for (int i = 0; i < array.size() - 1; ++i) {
        
        // find the smallest number
        int lowest = i;
        for (int j = i; j < array.size(); ++j) {
            if (array[j] < array[lowest]) {
                lowest = j;
            }
        }

        // swap with the appropriate in-order index
        if (array[lowest] < array[i]) {
            std::swap(array[lowest], array[i]);
        }
    }
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

    selection_sort(nums);

    std::cout << "After Sorting ..." << std::endl;
    dump_array(nums);

    return 0;
}