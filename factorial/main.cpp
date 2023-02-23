#include <iostream>

// 5! = 5 x 4 x 3 x 2 x 1

int recursive_factorial(int num) {
    if (num == 1) {
        return 1;
    }
    return num * recursive_factorial( num - 1);
}

int main() {

    int num = 0;

    std::cout << "Enter a number: ";
    std::cin >> num;

    // calculate the factorial
    int factorial = 1;
    for (int i = num; i >= 1; --i) {
        factorial *= i;
    }

    std::cout << num << "! = " << factorial << std::endl;

    // calculate using recursion
    std::cout << num << "! = " << recursive_factorial(num) << std::endl;

    return 0;
}