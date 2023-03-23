#include <iostream>
#include <span>
#include <iomanip>
#include <queue>

std::ostream& operator<<(std::ostream& output, std::queue<int> queue) {
    if (queue.empty()) return output;
    while (queue.size() > 1) {
        auto num = queue.front();
        queue.pop();
        output << num << ",";
    }
    output << queue.front();
    return output;
}

std::ostream& operator<<(std::ostream& output, std::span<int> array) {
    if (array.empty()) return output;
    int i = 0;
    for (; i < array.size() - 1; i++) {
        output << array[i] << ",";
    }
    output << array[i];
    return output;
}

void split(std::queue<int>& inarray, std::queue<int>& out1, std::queue<int>& out2) {

    int num_subfiles = 0;

    // keep splitting while we have stuff to split!
    int prev = -1;
    while (!inarray.empty()) {

        // read a "record"
        int curr = inarray.front();
        inarray.pop();

        // when the previous number is greater than the current, we are starting a new subfile
        if (curr < prev) num_subfiles++;

        // put records in order into temp files
        if (num_subfiles % 2 == 0) {
            out2.push(curr);
        } else {
            out1.push(curr);
        }

        prev = curr;
    }

}

bool elements_in_file(std::queue<int>& first, std::queue<int>& second, int last) {
    return !first.empty() && (first.front() > last) &&
            (second.empty() || (second.front() < last) || (first.front() < second.front()));
}

bool elements_in_sublist(std::queue<int>& first, std::queue<int>& second, int last) {
    return !first.empty() && (first.front() > last);
}

int merge(std::queue<int>& out, std::queue<int>& in1, std::queue<int>& in2) {

    int num_subfiles = 0;

    // who starts the process??
    auto& first = in2.empty() || (in1.front() < in2.front()) ? in1 : in2;
    auto& second = first == in1 ? in2 : in1;

    // keep merging while there are records to read
    while (!in1.empty() || !in2.empty()) {

        // keep taking in order elements until the end of a sublist
        int last = -1;
        while (elements_in_sublist(first, second, last)) {
            // take elements from the same file while in order
            do {
                last = first.front();
                first.pop();
                out.push(last);
            } while (elements_in_file(first, second, last));

            // move to other file
            if (!second.empty()) {
                std::swap(first, second);
            }
        }

        num_subfiles++;

    }

    return num_subfiles;
}

void merge_sort(std::span<int> array) {
    int num_subfiles = 0;

    // copy array to the merged queue
    std::queue<int> merged;
    for (auto num : array) {
        merged.push(num);
    }

    std::queue<int> split1, split2;
    do {
        split(merged, split1, split2);

        std::cout << "Split" << std::endl;
        std::cout << "temp1: " << split1 << std::endl;
        std::cout << "temp2: " << split2 << std::endl;

        num_subfiles = merge(merged, split1, split2);

        std::cout << "Merge" << std::endl;
        std::cout << merged << std::endl;

    } while (num_subfiles != 1);

    // copy queue to array
    int i = 0;
    while (!merged.empty()) {
        array[i++] = merged.front();
        merged.pop();
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

    merge_sort(nums);

    std::cout << "After Sorting ..." << std::endl;
    dump_array(nums);

    return 0;
}