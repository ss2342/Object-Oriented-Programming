//
// Satyen Singh
//

#ifndef HOMEWORKSANDLABSCS2124_STUDENT_H
#define HOMEWORKSANDLABSCS2124_STUDENT_H

#include <iostream>
#include <string>
#include <vector>


namespace BrooklynPoly {

    class Course;

    class Student {
        friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
    public:
        // Student methods needed by Registrar
        Student(const std::string& name);
        const std::string& getName() const;
        bool addCourse(Course* aCourse);

        // Student method needed by Course
        void removedFromCourse(Course* aCourse);

    private:
        std::string name;
        std::vector<Course*> courses;
    };

}


#endif //HOMEWORKSANDLABSCS2124_STUDENT_H
