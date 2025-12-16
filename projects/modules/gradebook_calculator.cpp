#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Forward declaration
class GradeBook{
    private:
        vector<int> grades; 
    public:
        GradeBook(const vector<int>& curr_grades) : grades(curr_grades) {}
        void display() const {
            for (int values : grades) {
                cout << values << " ";
            }
        }
        double calculateAverage() {
            double sum;
            for (int values : grades) {
               sum += values;  
            } return (sum / grades.size());           
        } 
    // Count grades matching predicate
    int countIf(function<bool(int)> predicate) const {
        int count = 0;
        for (int grade : grades) {
            if (predicate(grade)) {
                count++;
            }
        }
        return count;
    }
    
    void applyToAll(function<int(int)> func) {
        for (int& grade : grades) {
            grade = func(grade);
        }
    }
    
    int findMax(function<int(int, int)> compare) const {
        if (grades.empty()) return 0;
        
        int result = grades[0];
        for (int grade : grades) {
            result = compare(result, grade);
        }
        return result;
    }
    
    int findMin(function<int(int, int)> compare) const {
        if (grades.empty()) return 0;
        
        int result = grades[0];
        for (int grade : grades) {
            result = compare(result, grade);
        }
        return result;
    }

    void forEach(function<void(int)> action) const {
        for (int grade : grades) {
            action(grade);
        }
    }
};

int main() {
    vector<int> grades = {85, 92, 78, 95, 88, 72, 65, 100};
    GradeBook gradeBook(grades);
    
    cout << "=== STUDENT GRADE PROCESSOR ===" << endl;
    cout << "All grades: ";
    gradeBook.display();
    
    // Count passing grades (>= 70)
    int passing = gradeBook.countIf([](int grade) {
        return grade >= 70;
    });
    cout << "Passing grades (>= 70): " << passing << endl;
    
    // Count failing grades (< 70)
    int failing = gradeBook.countIf([](int grade) {
        return grade < 70;
    });
    cout << "Failing grades (< 70): " << failing << endl;
    
    // Find highest grade
    int highest = gradeBook.findMax([](int a, int b) {
        return a > b ? a : b;
    });
    cout << "Highest grade: " << highest << endl;
    
    // Find lowest grade
    int lowest = gradeBook.findMin([](int a, int b) {
        return a < b ? a : b;
    });
    cout << "Lowest grade: " << lowest << endl;
    
    // Calculate average
    double average = gradeBook.calculateAverage();
    cout << "Average grade: " << average << endl;
    
    // Apply curve: add 5 points to all grades
    cout << "\n=== APPLYING 5-POINT CURVE ===" << endl;
    gradeBook.applyToAll([](int grade) {
        return grade + 5;
    });
    cout << "Grades after curve: ";
    gradeBook.display();
    
    // Find excellent grades (>= 90)
    cout << "\n=== EXCELLENT GRADES (>= 90) ===" << endl;
    gradeBook.forEach([](int grade) {
        if (grade >= 90) {
            cout << "Excellent: " << grade << endl;
        }
    });
    
    return 0;
}