#include <iostream>
#include <iomanip>
#include <span>

void insertion_sort(std::span<int> array) {
    for (int i = 1; i < array.size(); ++i) {
        // take the current element
        int temp = array[i];

        // shuffle elements greater than current to be ahead of this value
        int j;
        for (j = i; j > 0 && temp < array[j - 1]; j--) {
            array[j] = array[j - 1];
        }

        // insert the element
        array[j] = temp;
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

    insertion_sort(nums);

    std::cout << "After Sorting ..." << std::endl;
    dump_array(nums);

    return 0;
}