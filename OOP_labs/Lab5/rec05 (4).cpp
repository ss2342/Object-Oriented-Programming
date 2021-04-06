//
// Satyen Singh
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Section {
public:

    friend ostream& operator<<(ostream& os, const Section& section) {
        os << "Section: " << section.sectionName << ' ' << section.sectionInfo;
        if (section.recordsOfStudents.size() == 0) {
            os << ", Students: None" << endl;
        }
        else {
            os << ", Students:" << endl;
            for (size_t i = 0; i < section.recordsOfStudents.size(); ++i) {
                os << *section.recordsOfStudents[i] << endl;
            }
        }
        return os;
    }

    Section(const string& nameOfSection, const string& dayOfSection, int timeOfSection) :
            sectionName(nameOfSection), sectionInfo(dayOfSection, timeOfSection) {}

    void addStudent(const string& student) {
        StudentRecord* studentptr = new StudentRecord(student);
        recordsOfStudents.push_back(studentptr);
    }

    void changeStudentGrade(const string& student, int& grade, int& index) {
        for (size_t i = 0; i < recordsOfStudents.size(); ++i) {
            if (recordsOfStudents[i]->getStudentName() == student) {
                recordsOfStudents[i] -> changeGrade(grade, index);
            }
        }
    }

    ~Section() {
        cout << "Section " << sectionName << " is being deleted." << endl;
        for (size_t i = 0; i < recordsOfStudents.size(); ++i) {
            cout << "deleting " << recordsOfStudents[i] -> getStudentName() << endl;
             delete recordsOfStudents[i];
        }
    }
private:
    class TimeSlot {
    public:
        friend ostream&operator<<(ostream& os, const TimeSlot& timeslot) {
            if (timeslot.time > 12) {
                os << timeslot.day <<' ' << timeslot.time - 12;
            }
            else {
                os << timeslot.day << ' ' << timeslot.time;
            }
            return os;
        }

        TimeSlot(const string& dayInfo, int timeInfo) : day(dayInfo), time(timeInfo) {}

    private:
        string day;
        int time;
    };


    class StudentRecord {
    public:
        friend ostream&operator<<(ostream& os, const StudentRecord& record) {
            os << "Name: " << record.studentName << ", Grades: ";
            for (size_t i = 0; i < record.studentGrades.size(); ++i) {
                os << record.studentGrades[i] << ' ';
            }
            return os;
        }
        StudentRecord(const string& nameOfStudent) :
                      studentName(nameOfStudent), studentGrades(14 ,-1) {}

        const string& getStudentName() const {
            return studentName;
        }

        int changeGrade(int newGrade, int index) {
            studentGrades[index-1] = newGrade;
        }




    private:
        string studentName;
        vector<int> studentGrades;



    };
    string sectionName;
    TimeSlot sectionInfo;
    vector<StudentRecord*> recordsOfStudents;

};

class LabWorker {
public:
    LabWorker(const string& WorkerName) : nameOfWorker(WorkerName) {}

    friend ostream& operator<<(ostream& os, const LabWorker& worker);

    void addSection(Section& section) {
        this->aSection = &section;
    }

    void addGrade(const string& nameOfStudent, int grade, int index) {
        aSection->changeStudentGrade(nameOfStudent, grade, index);
    }

private:
    Section* aSection = nullptr;
    string nameOfWorker;
};

ostream& operator<<(ostream& os, const LabWorker& worker) {

    if (worker.aSection == nullptr) {
        os << worker.nameOfWorker << " does not have a section." << endl;
    }
    else {
        os << worker.nameOfWorker << " has section " <<  *worker.aSection << endl;
    }
    return os;
}
// Test code
void doNothing(Section sec) {
    cout << sec << endl;;
}

int main() {

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
    LabWorker moe("Moe");
    cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection(secA2);
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
    jane.addSection(secB3);
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

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works properly, i.e. no memory leaks\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";

} // main
