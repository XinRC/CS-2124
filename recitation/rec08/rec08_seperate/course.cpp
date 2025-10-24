#include "course.h"
#include "student.h"
#include <iostream>
using namespace std;

namespace BrooklynPoly {

    Course::Course(const string& courseName) : name(courseName) {}

    const string& Course::getName() const { return name; }

    bool Course::addStudent(Student* student) {
        for (const Student* s : students) {
            if (s == student) {
                return false;
            }
        }
        students.push_back(student);
        return true;
    }

    void Course::removeStudentsFromCourse() {
        for (Student* s : students) {
            s->removedFromCourse(this);
        } 
        students.clear();   
    }

    ostream& operator<<(ostream& os, const Course& rhs) {
        os << rhs.name << ": ";
        if (rhs.students.empty()) {
            os << "No Students";
        } else {
            for (size_t i = 0; i < rhs.students.size(); ++i) {
                os << rhs.students[i]->getName();
                if (i != rhs.students.size() - 1) {
                    os << ", ";
                }
            }
        }
        return os;
    }

} // namespace BrooklynPoly