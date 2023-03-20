#include <iostream>
#include <iomanip>

void bubble_sort(int* array, int len) {
    for (int i = 0; i < len - 2; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            // compare two adjacent elements
            if (array[j] > array[j+1]) {
                // swap elements if they are out of order
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void dump_array(int* array, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << std::setw(3) << array[i];
    }
    std::cout << std::endl;
}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 1, 2, 7};
    int len = sizeof(nums)/sizeof(int);

    std::cout << "Before Sorting ..." << std::endl;
    dump_array(nums, len);

    bubble_sort(nums, len);

    std::cout << "After Sorting ..." << std::endl;
    dump_array(nums, len);

    return 0;
}