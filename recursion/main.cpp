#include <iostream>

int count = 0;

void print() {
    // ...
    count++;
    if (count < 40000) {
        // generates a STATUS_STACK_OVERFLOW exception
        print();
    }
}

int main() {
    print();

    return 0;
}