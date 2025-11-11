#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Section {
  friend ostream& operator<<(ostream& os, const Section& rhs);

private:
  string name;

  class TimeSlot{
  private:
    string day;
    unsigned hour;

  public: 
    // normal constructor
    TimeSlot(const string& day, unsigned hour) : day(day), hour(hour) {}

    // To display date correctyl -> within class:
    friend ostream& operator<<(ostream& os, const TimeSlot rhs) {
      string period = "am";
      int displayHour = rhs.hour;

      if (rhs.hour >= 12) { // starting 12 pm 
        period = "pm";
        if (rhs.hour > 12) {
          displayHour = rhs.hour - 12;
        }
      }
      if (rhs.hour == 0) {
        displayHour = 12;
      }
      
      os << "Day: " << rhs.day << ", Start time: " << displayHour << period; 
      return os;
    }

  };

    

class Student {
  private:
    string name;
    vector<int> grades;
  public:
    Student(const string& name) : name(name), grades(14, -1) {}

    const string& getName() const {return name;} //getter

    void addGrade(int grade, int week) { // modifies grade on specific week
      if (week >= 1 && week <= 14) {
        grades[week-1] = grade;
      }
    }

    // friend inclass << operator 
    friend ostream& operator<<(ostream& os, const Student& rhs){
      os << "Name: " << rhs.name << ", Grades: ";
      for (int grade : rhs.grades) {
        os << grade << " "; 
      }
      return os;
    }
 

  };

TimeSlot time;
vector <Student*> students;

public:
  // normal constructor
  Section(const string& name, const string& day, unsigned hour) 
    : name(name), time(day, hour) {}

  ~Section(){ //deconstructor since we use (new) 
    cout << "Section" << name << " is being deleted" << endl;
    for (const Student* student : students) {
      cout << "Deleting " << student->getName() << endl;
      delete student; 
    }
  } 

  // copy constructor -> part 2 of big 3 -> deep copy:
  Section(const Section& other) : name(other.name), time(other.time) {
    // deep copying students:
    for (const Student* student : other.students) {
      students.push_back(new Student(*student));
    }
  }

  // assignment overloader -> part 3 of big 3 (NOT DOING FOR RECITATION) :

  // adding students into section:
  void addStudent(const string& studentName) {
    students.push_back(new Student(studentName)); 
  }

  // adding a grade:
  void addGrade(const string& studentName, int grade, int week) {
    for (Student* student : students) { 
      if (student->getName() == studentName) {
        student->addGrade(grade, week); 
        return;
      } 
    }
  }


  void reset() {
    for (const Student* student : students) {
      delete student;
    }
    students.clear();
  }


};


class LabWorker{
  friend ostream& operator<<(ostream& os, const LabWorker& rhs);
private: 
  string name;
  Section* section; 

public: 
  // normal constructor
  LabWorker(const string& name) : name(name), section(nullptr) {}

  void addSection(Section& sec) {
    section = &sec;
  }

  // moe.addGrade("John", 17, 1);  
  void addGrade(const string& studentName, int grade, int week) {
    if (section) {
      section->addGrade(studentName, grade, week);
    } 
  }

};


//output operators:
// Section:
ostream& operator<<(ostream& os, const Section& rhs) {
  os << "Section " << rhs.name << ", Time slot: [" << rhs.time << "], Students: ";
  if (rhs.students.empty()) { // checks if no students
    os << " None.";
  } else {
    for (const Section::Student* student : rhs.students) {
      os << "\n" << *student;
    }
    return os; 
  }

  return os; 
}
// Labworker:
ostream& operator<<(ostream& os, const LabWorker& rhs) {
  os << rhs.name;
  if (rhs.section) {
    os << " has ";
    os << *rhs.section; // strange how we can't hace this in the above statement...
  } else {
    os << " does not have any section";
  }
  return os;
}



//Test code
void doNothing(Section sec) { cout << sec << endl; }

int main()
{
    cout << "\n\n"; 
    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);  
    moe.addGrade("Paul", 19, 1);  
    moe.addGrade("George", 16, 1);  
    moe.addGrade("Ringo", 7, 1);  
    cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);  
    moe.addGrade("Paul", 20, 3);  
    moe.addGrade("Ringo", 0, 3);  
    moe.addGrade("George", 16, 3);  
    cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Copy Constructor: make sure the following calls work:\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n" << secA2 << endl;

} // main

