#include "registrar.h"
#include "student.h"
#include "course.h"
#include <iostream>
using namespace std;

namespace BrooklynPoly {

    bool Registrar::addCourse(const string& courseName) {
        if (findCourse(courseName) != courses.size()) {
            return false; 
        }
        courses.push_back(new Course(courseName));
        return true;
    }

    bool Registrar::addStudent(const string& studentName) {
        if (findStudent(studentName) != students.size()) {
            return false;
        }
        students.push_back(new Student(studentName));
        return true;
    }

    bool Registrar::enrollStudentInCourse(const string& studentName, const string& courseName) {
        size_t studentIndex = findStudent(studentName);
        size_t courseIndex = findCourse(courseName);

        if (studentIndex == students.size() || courseIndex == courses.size()) {
            return false;
        }

        Student* student = students[studentIndex];
        Course* course = courses[courseIndex];

        if (course->addStudent(student) && student->addCourse(course)) {
            return true; 
        }
        return false; 
    }

    bool Registrar::cancelCourse(const string& courseName) {
        size_t courseIndex = findCourse(courseName);

        if (courseIndex == courses.size()) {
            return false; 
        }

        Course* course = courses[courseIndex];
        course->removeStudentsFromCourse();

        delete course;
        courses[courseIndex] = courses.back();
        courses.pop_back();

        return true;
    }

    void Registrar::purge() { 
        for (Course* course : courses) {
            delete course;
        }
        courses.clear();

        for (Student* student : students) {
            delete student;
        }
        students.clear();
    }

    ostream& operator<<(ostream& os, const Registrar& rhs) {
        os << "Registrar's Report\n";
        os << "Courses:\n";
        for (const Course* course : rhs.courses) {
            os << *course << endl;
        }
        os << "Students:\n";
        for (const Student* student : rhs.students) {
            os << *student << endl;
        }
        return os;
    }

    size_t Registrar::findStudent(const string& student) const {
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i]->getName() == student) {
                return i;
            };
        };
        return students.size();
    }

    size_t Registrar::findCourse(const string& course) const { 
        for (size_t i = 0; i < courses.size(); ++i) {
            if (courses[i]->getName() == course) {
                return i;
            }
        }
        return courses.size();
    }

} // namespace BrooklynPoly