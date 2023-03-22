#include <iostream>
#include <array>
#include <span>
#include <iomanip>

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

void shell_sort(std::span<int> array) {

    // gap size : 5 2 1
    for (int gap = array.size() / 2; gap > 0 ; gap /= 2) {

        for (int start = 0; start < gap; ++start) {

            // insertion sort
            for (int i = start + gap; i < array.size(); i += gap) {

                int temp = array[i];

                int j;
                for (j = i; j >= gap && temp < array[j - gap]; j -= gap) {
                    array[j] = array[j - gap];
                }

                array[j] = temp;
            }
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

    shell_sort(nums);

    std::cout << "After Sorting ..." << std::endl;
    dump_array(nums);

    return 0;
}