#include <iostream>
#include <cstring>

using std::cout, std::endl, std::cin;

int main() {

    static const auto BUFFER_SIZE = 256L;
    char buffer[BUFFER_SIZE] {0};
    auto text = "hello";

    auto done = false;
    while (!done) {
        cout << "Enter some text: ";
        cin.getline(buffer, BUFFER_SIZE);

        // if any errors are in the input stream
        // dump the buffer and clear the errors
        if (!cin) {
            cin.clear();
            cin.ignore(BUFFER_SIZE, '\n');
        }

        // echo the user's input
        // "end" will exit the program
        if (!strncmp(buffer, "end", BUFFER_SIZE - 1)) {
            done = true;
        } else {
            cout << "You typed: " << buffer << endl;
        }
    }

    return 0;
}