//
// Satyen Singh
//

#include "student.h"
#include "course.h"
using namespace std;

namespace BrooklynPoly {
    ostream& operator<<(ostream& os, const Course& rhs) {
        os << rhs.getName() << ": ";
        if (rhs.students.size() == 0) {
            os << "No Students";
        }
        else {
            for (size_t i = 0; i < (rhs.students).size(); ++i) {
                os << (rhs.students[i])->getName() << ' ';
            }
        }
        os << endl;
        return os;
    }

    Course::Course(const string& courseName) : name(courseName) {}

    const string& Course::getName() const {
        return name;
    }

    bool Course::addStudent(Student* aStudent) {
        students.push_back(aStudent);
        return true;
    }


    void Course::removeStudentsFromCourse() {
        for (size_t i = 0; i < students.size(); ++i) {
            students[i]->removedFromCourse(this);
        }
        students.clear();
    }

}

