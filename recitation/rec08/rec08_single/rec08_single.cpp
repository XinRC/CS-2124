/*
    Xin Chen
  rec08_start.cpp
  Starter Code for required functionality

  Yes, of course, you may add other methods.

  And no, this won't compile. You have to fix the cyclic association
  and implement the methods.
  
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student; 

class Course {
    friend ostream& operator<<(ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
    Course(const string& courseName);
    const string& getName() const;

    // Adding the student to this course's vector of students.
    // Make sure the student is not already in this course. 
    // (Don't fail silently.)
    // This would be called from Registrar::enrollStudentInCourse.
    bool addStudent(Student*);

    // Tell all the students in this course that they are no longer in it.
    // This would be called from Registrar::cancelCourse.
    void removeStudentsFromCourse(); 

private:
    string name;
    vector<Student*> students;
}; // Course class


class Student {
    friend ostream& operator<<(ostream& os, const Student& rhs);
public:
    // Student methods needed by Registrar
    Student(const string& name);
    const string& getName() const;

    // Adding the course to the student's vector of courses.
    // Make sure this student is not already in that course. 
    // (Don't fail silently.)
    // This method would be called from Registrar::enrollStudentInCourse.
    bool addCourse(Course*);

    // Removes the Course from the student's vector of Courses.
    // Needed by Course::removeStudentsFromCourse
    void removedFromCourse(Course*);

private:
    string name;
    vector<Course*> courses;
}; // Student class


class Registrar {
    friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
    // This default constructor just initializes the two empty vectors.
    // " = default" means we are using the system provided constructor.
    // You don't have to implement anything for this function.
    Registrar() = default;

    // Creates a new course on the heap, if none with courseName
    // exists in Registrar's courses vector. Don't fail silently.
    bool addCourse(const string& courseName);

    // Creates a new student on the heap, if none with studentName
    // exists in Registrar's students vector. Don't fail silently.
    bool addStudent(const string&);

    // If a student with studentName and a course with courseName exist, 
    // then enroll the student in the course. Note, don't fail silently.
    // Do not create any new Student or Course objects.
    bool enrollStudentInCourse(const string& studentName,
                               const string& courseName);

    // Unenroll the students from the course courseName and remove it
    // from the Registrar.
    bool cancelCourse(const string& courseName);

    // Get rid of everything!!!
    void purge();

private:
    size_t findStudent(const string&) const;
    size_t findCourse(const string&) const;

    vector<Course*> courses;
    vector<Student*> students;
}; // Registrar

int main()
{

    Registrar registrar;

    cout << "No courses or students added yet\n";
    cout << registrar << endl;
     
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout << "Should fail, i.e. do nothing, "
         << "since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;
   
    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;
} // main
  
// ================================================================//

// Course:
// addStudent, removeStudent, 
// ostreams
Course::Course(const string& courseName) : name(courseName) {}

const string& Course::getName() const { return name; }

bool Course::addStudent(Student* student) {// adds student into course list vector
    for (const Student* s : students) {
        if (s == student) {
            return false;
        }
    }
    students.push_back(student);
    return true;
}

void Course::removeStudentsFromCourse() { // removes student from courst list vector
    for (Student* s : students) {
        s->removedFromCourse(this);
    } students.clear();   
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

// ============================================================//

// Student:
// addCourse, removedFromCourse, 
// ostreams
Student::Student(const string& name) : name(name) {}
const string& Student::getName() const { return name; }

bool Student::addCourse(Course* course) { // adds a course into student's vector
    for (const Course* c : courses) {
        if (c == course) {
            return false;
        }
    }
    courses.push_back(course);
    return true;
}


void Student::removedFromCourse(Course* course) { // remove.. -> pop from back?
    for (size_t i = 0; i < courses.size(); ++i) {
        if (courses[i] == course) {
            courses[i] = courses.back(); // replacing back element to "i"th element
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

// ============================================================//

//Registar: 
// addCourse, addStudent, enrollStudentInCourse, cancelCourse, purge, ostreams

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
    // will return the size of vector if items does not exist
    size_t studentIndex = findStudent(studentName);
    size_t courseIndex = findCourse(courseName);

    if (studentIndex == students.size() || courseIndex == courses.size()) {
        return false;
    }

    // IF DO exist -> uses the vector[index] to make sure its added for both vectors:
    Student* student = students[studentIndex];
    Course* course = courses[courseIndex];

    if (course->addStudent(student) && student->addCourse(course)) {
        return true; 
    }
    return false; 

}

bool Registrar::cancelCourse(const string& courseName) {
    size_t courseIndex = findCourse(courseName); // makes sure course exists (245->249)

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
    // gets rid of everything, manually erease students/courses vectors
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



// ============================================================//

//Private:
// findStudent, findCourse
// these will get us our student/course index from vector

size_t Registrar::findStudent(const string& student) const {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i]->getName() == student) {
            return i;
        };
    };
    return students.size(); // if can't find student 
}

size_t Registrar::findCourse(const string& course) const { 
    for (size_t i = 0; i < courses.size(); ++i) {
        if (courses[i]->getName() == course) {
            return i;
        }
    }
    return courses.size(); // if can't find course
}

/*
Code Reading Question:
There will be an error at Line B because the #include "a.h" is repeated.
We want to use: "ifndefined, define, endif" since it is good practice and 
prevents redefinition 
*/