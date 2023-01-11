#ifndef _STUDENT_H
#define _STUDENT_H

using namespace std::string_literals;

// student defaults
static const auto STUDENT_NAME = "default"s;
static const auto STUDENT_ID = "W9999999"s;

// Purpose: a data class to hold student information
// Author: Brian Shewan
// Date: 2023-Jan-11
class Student {
private:
    std::string m_name{STUDENT_NAME};   // full name "firstname lastname"
    std::string m_id{STUDENT_ID};       // format: W9999999
    int m_phone_numbers[2];             // home and mobile phone numbers

    // initializes the student default information
    void initialize_student();
public:
    Student();
    Student(std::string name, std::string id);


    // outputs the student details
    // format: "Name: <student name>, ID: <student id>"
    void print_info();

    friend std::ostream& operator<<(std::ostream& output, Student& s);
};

#endif