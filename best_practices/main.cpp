#include <iostream>
#include "include/student.h"

int main() {
    try {
        // test 1 - create a new student
        std::cout << "test 1: create a new student" << std::endl;
        Student student_one;
        std::cout << student_one << std::endl << std::endl;

        // test 2 - create a student with a name and id
        std::cout << "test 2: create a student with a name and id" << std::endl;
        Student student_two("Jake Doe", "W123123");
        std::cout << student_two << std::endl << std::endl;

        // test 3 - create a simple function to print the output
        std::cout << "test 3: create a simple function to print the output";
        std::cout << std::endl;
        Student student_three("Jane Smith", "W321321");
        student_three.print_info();
        std::cout << std::endl;

        // test 4 - display a student four times
        std::cout << "test 4: demonstrating an infinite loop" << std::endl;
        // demonstrates the incorrect use of an infinite loop
        auto count = 0;
        while (true) {
            student_three.print_info();
            count++;
            if (count > 4) {
                break;
            }
        }

        // test 5 - create a student on the heap
        auto student_four = new Student();
        std::cout << student_four << std::endl;
        delete student_four;

    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}