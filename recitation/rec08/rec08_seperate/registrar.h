#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <string>
#include <iostream>
#include <vector>

namespace BrooklynPoly {

    class Student;
    class Course;

    class Registrar {
        friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);
    public:
        Registrar() = default;
        bool addCourse(const std::string& courseName);
        bool addStudent(const std::string& studentName);
        bool enrollStudentInCourse(const std::string& studentName,
                                   const std::string& courseName);
        bool cancelCourse(const std::string& courseName);
        void purge();

    private:
        size_t findStudent(const std::string&) const;
        size_t findCourse(const std::string&) const;

        std::vector<Course*> courses;
        std::vector<Student*> students;
    };

} // namespace BrooklynPoly

#endif