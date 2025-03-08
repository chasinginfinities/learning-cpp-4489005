// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "records.h"

int main(){
    float GPA = 0.0f;
    int id;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;
    
    // Calculate the GPA for the selected student.
    std::map<char, int> letter_to_points = {{'A', 4}, {'B', 3}, {'C', 2}, {'D', 1},{'F', 0}};
    int total_credits = 0;
    double total_points = 0.0;
    for (auto grade: grades) {
        if (grade.get_student_id() == id) {
            int credits = find_if(courses.begin(), courses.end(), [&](const auto& course){return course.get_id() == grade.get_course_id();})->get_credits();
            total_points += letter_to_points[grade.get_grade()]*credits;
            total_credits += credits;
        }
    }
    GPA = total_points / total_credits;

    std::string student_str = std::find_if(students.begin(), students.end(),  [&](const auto& student){ return student.get_id() == id; })->get_name();

    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
