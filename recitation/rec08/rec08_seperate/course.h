#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#include <vector>

namespace BrooklynPoly {

    class Student;

    class Course {
        friend std::ostream& operator<<(std::ostream& os, const Course& rhs);
    public:
        Course(const std::string& courseName);
        const std::string& getName() const;
        bool addStudent(Student*);
        void removeStudentsFromCourse(); 

    private:
        std::string name;
        std::vector<Student*> students;
    };

} // namespace BrooklynPoly

#endif