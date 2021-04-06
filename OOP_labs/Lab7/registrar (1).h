//
// Satyen Singh
//

#ifndef HOMEWORKSANDLABSCS2124_REGISTRAR_H
#define HOMEWORKSANDLABSCS2124_REGISTRAR_H

#include <iostream>
#include <string>
#include <vector>


namespace BrooklynPoly {
    class Course;
    class Student;

    class Registrar {
        friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);
    public:
        Registrar();
        bool addCourse(const std::string& aCourse);
        bool addStudent(const std::string& aStudent);
        bool enrollStudentInCourse(const std::string& studentName,
                                   const std::string& courseName);
        bool cancelCourse(const std::string& courseName);
        void purge();

    private:
        size_t findStudent(const std::string& aStudent) const;
        size_t findCourse(const std::string& aCourse) const;

        std::vector<Course*> courses;
        std::vector<Student*> students;
    };
}


#endif //HOMEWORKSANDLABSCS2124_REGISTRAR_H
