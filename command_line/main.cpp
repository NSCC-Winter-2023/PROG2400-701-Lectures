#include <iostream>

void things_not_to_do() {
    //    // things NOT to do!

    // you are NOT outputting any of the first line
    std::cout << "EDIT ";
    std::cout << "testfile" << std::endl;

    // you are NOT asking the user for the filename
    std::string filename{"testfile"};
    std::cout << "EDIT ";
    std::cin >> filename;
}

void pointer_review() {
    // pointer review
    char text[] = "hello world";
    std::cout << "text: " << text << std::endl;
    std::cout << "text: " << std::hex << (unsigned long long)text << std::endl;

    unsigned short* ptr = (unsigned short *)text;
    std::cout << "ptr: " << std::hex << (unsigned long long)ptr << std::endl;
    std::cout << "*ptr: " << *ptr << std::endl;
}

int main(int argc, char* argv[]) {

    std::cout << "argv: " << std::hex << argv << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "  argv: " << std::hex << (int *)argv[i] << std::endl;
    }

    if (argc > 1) {
        // there is at least one argument
        std::cout << "filename: " << argv[1] << std::endl;
        for (int i = 2; i < argc; ++i) {
            std::cout << argv[i] << std::endl;
        }
    }

    return 0;
}