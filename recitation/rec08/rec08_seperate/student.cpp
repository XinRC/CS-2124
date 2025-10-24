#include "student.h"
#include "course.h"
#include <iostream>
using namespace std;

namespace BrooklynPoly {

    Student::Student(const string& name) : name(name) {}
    
    const string& Student::getName() const { return name; }

    bool Student::addCourse(Course* course) {
        for (const Course* c : courses) {
            if (c == course) {
                return false;
            }
        }
        courses.push_back(course);
        return true;
    }

    void Student::removedFromCourse(Course* course) {
        for (size_t i = 0; i < courses.size(); ++i) {
            if (courses[i] == course) {
                courses[i] = courses.back();
                courses.pop_back();
                break;
            }
        }
    }

    ostream& operator<<(ostream& os, const Student& rhs) {
        os << rhs.name << ": ";
        if (rhs.courses.empty()) {
            os << "No Courses";
        } else {
            for (size_t i = 0; i < rhs.courses.size(); ++i) {
                os << rhs.courses[i]->getName();
                if (i != rhs.courses.size() - 1) {
                    os << ", ";
                }
            }
        }
        return os;
    }

} // namespace BrooklynPoly