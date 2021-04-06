//
// Satyen Singh
//

#include "student.h"
#include "course.h"
using namespace std;

namespace BrooklynPoly {
    ostream& operator<<(ostream& os, const Student& rhs) {
        os << rhs.getName() << ": ";
        if (rhs.courses.size() == 0) {
            os << "No Courses" << endl;
        }
        else {
            for (size_t i = 0; i < (rhs.courses).size(); ++i) {
                os << (rhs.courses[i])->getName() << ' ';
            }
        }
        os << endl;
        return os;

    }

    Student::Student(const string& name) : name(name) {}

    const string& Student::getName() const {
        return name;
    }

    bool Student::addCourse(Course* aCourse) {
        courses.push_back(aCourse);
        return true;
    }

    void Student::removedFromCourse(Course* aCourse) {
        int found;

        for (size_t i = 0; i < courses.size(); ++i) {
            if (courses[i] == aCourse) {
                found = i;
            }
        }

        for (size_t i = found + 1; i < courses.size(); ++i) {
            courses[i] = courses[i-1];
        }
        courses.pop_back();

    }

}

