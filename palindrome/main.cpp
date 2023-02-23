#include <iostream>
#include <cstring>

bool is_palindrome(const char* input, size_t len) {
    for (int i = 0; i < len / 2; ++i) {
        if (input[i] != input[len-i-1]) {
            return false;
        }
    }
    return true;
}

bool is_recursive_palindrome(const char* input, size_t len) {
    if (len <= 1) return true;

    char first = input[0];
    char last = input[len - 1];

    // if the first and last letters are the same, we have potential
    // palindrome
    if (first == last) {
        // remove the first and last letters
        return is_recursive_palindrome(&input[1], len - 2);
    }

    // not a palindrome if first and last are ever different
    return false;
}

int main() {

    constexpr int BUFFER_SIZE = 256;
    char buffer[BUFFER_SIZE];

    std::cout << "Enter a word: ";
    std::cin.getline(buffer, BUFFER_SIZE);

    if (is_palindrome(buffer, strnlen(buffer, BUFFER_SIZE))) {
        std::cout << buffer << " IS a palindrome." << std::endl;
    } else {
        std::cout << buffer << " is NOT a palindrome." << std::endl;
    }

    if (is_recursive_palindrome(buffer, strnlen(buffer, BUFFER_SIZE))) {
        std::cout << buffer << " IS a palindrome." << std::endl;
    } else {
        std::cout << buffer << " is NOT a palindrome." << std::endl;
    }

    return 0;
}