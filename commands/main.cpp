#include <iostream>
#include <sstream>
#include <string>

using namespace std::string_literals;

int main() {

    std::string input;
    std::cout << "Enter something: ";
    getline(std::cin, input);

    std::stringstream ss;
    ss << input;

    char command;
    int start, end;

    ss >> command >> start >> end;

    if (!ss) {
        std::cout << "You didn't type a command in." << std::endl;
        std::cout << "Text: " << input << std::endl;
    } else {
        std::cout << "command: " << command << std::endl;
        std::cout << "start: " << start << std::endl;
        std::cout << "end: " << end << std::endl;
    }

    return 0;
}