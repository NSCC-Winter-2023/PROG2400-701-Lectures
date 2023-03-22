#include <iostream>
#include <span>
#include <iomanip>

int split(std::span<int> array, int first, int last) {

    // pick a pivot point
    int pivot = array[first];

    // start searching for numbers less than and greater than the pivot point
    int left = first;
    int right = last;

    while (left < right) {

        // move all less than the pivot point to the left
        while (pivot < array[right]) {
            right--;
        }

        // move all greater than the pivot point to the right
        while (pivot >= array[left]) {
            left++;
        }

        // if two were found out of place, swap them
        if (left < right) {
            std::swap(array[left], array[right]);
        }
    }

    // move the pivot point between the two sublists
    array[first] = array[right];
    array[right] = pivot;

    return right;
}

void quick_sort(std::span<int> array, int first, int last) {

    if (first < last) {
        // split array into less thans and greater thans
        // "pos" is the position of the pivot point
        int pos = split(array, first, last);

        // sort the less thans
        quick_sort(array, first, pos - 1);

        // sort the greater thans
        quick_sort(array, pos + 1, last);
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

    quick_sort(nums, 0, nums.size() - 1);

    std::cout << "After Sorting ..." << std::endl;
    dump_array(nums);
    return 0;
}