#include <iostream>
#include "include/student.h"

Student::Student()
        : Student("no name"s, "W1234567"s) {
}

Student::Student(std::string name, std::string id)
        : m_name(std::move(name)), m_id(std::move(id)) {
    initialize_student();
}

void
Student::initialize_student() {
    // initial phone numbers will be all zero
    for (int i = 0; i < 2; ++i) {
        this->m_phone_numbers[i] = 0;
    }
}

void
Student::print_info() { std::cout << *this << std::endl; }

std::ostream &operator<<(std::ostream &output, Student &s) {
    output << "Name: " << s.m_name;
    output << ", STUDENT_ID: " << s.m_id;
    return output;
}
