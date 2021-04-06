//
// Satyen Singh
//

#include "rec07/student.h"
#include "rec07/course.h"
#include "rec07/registrar.h"
using namespace std;

namespace BrooklynPoly {
    ostream& operator<<(ostream& os, const Registrar& rhs) {
        os << "Registrar's Report" << endl;
        os << "Courses: ";
        os << endl;


        for (size_t i = 0; i < (rhs.courses).size(); ++i) {
            os << *rhs.courses[i];
        }

        os << "Students: ";
        os << endl;

        for (size_t i = 0; i < (rhs.students).size(); ++i) {
            os << *rhs.students[i];
        }

        return os;
    }

    Registrar::Registrar() {}

    bool Registrar::addCourse(const string& courseName) {
        if (this->findCourse(courseName) == courses.size()) {
            Course* aCourse = new Course(courseName);
            courses.push_back(aCourse);
            return true;
        }
        else {
            return false;
        }
    }

    bool Registrar::addStudent(const string& studentName) {
        if (this->findStudent(studentName) == students.size()) {
            Student* aStudent = new Student(studentName);
            students.push_back(aStudent);
            return true;
        }
        else {
            return false;
        }
    }

    bool Registrar::enrollStudentInCourse(const string& studentName,
                                          const string& courseName) {
        size_t aStudent = this -> findStudent(studentName);
        size_t aCourse = this -> findCourse(courseName);
        if (students.size() != aStudent && courses.size() != aCourse) {
            students[aStudent] -> addCourse(courses[aCourse]);
            courses[aCourse] -> addStudent((students[aStudent]));
            return true;
        }
        else {
            return false;
        }
    }

    bool Registrar::cancelCourse(const string& courseName) {
        size_t aCourse = this -> findCourse(courseName);
        if (courses.size() != aCourse) {
            courses[aCourse] -> removeStudentsFromCourse();
        }
        else {
            return false;
        }

        delete courses[aCourse];
        for (size_t i = aCourse + 1; i < courses.size(); ++i) {
            courses[i] = courses[i-1];
        }
        courses.pop_back();
        return true;

    }

    void Registrar::purge() {
        for (size_t i = 0; i < courses.size(); ++i) {
            delete courses[i];
        }
        courses.clear();

        for (size_t i = 0; i < students.size(); ++i) {
            delete students[i];
        }
        students.clear();
    }


    size_t Registrar::findStudent(const string& aStudent) const {
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i] -> getName() == aStudent) {
                return i;
            }
        }
        return students.size();
    }

    size_t Registrar::findCourse(const string & aCourse) const {
        for (size_t i = 0; i < courses.size(); ++i) {
            if (courses[i] -> getName() == aCourse) {
                return i;
            }
        }
        return courses.size();
    }
}
