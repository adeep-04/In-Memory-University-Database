#ifndef PERSON_H
#define PERSON_H
#include<string>
#include <iostream>
#include<vector>
#include<map>

using namespace std;
class person
{
    protected:
        int ID;
        string name;
        int age;
        bool gander; //1 for Male. 0 for female

    public:
        person();
        person(int id, string Name, int Age,bool Gander);

        int getID() const;
        string getNAME() const;
        int getAGE() const;
        bool getGander() const;

        void setID(const int id);
        void setNAME(const string namee);
        void setAGE(const int AGE);
        void setGander(const bool Gander);


        ~person();

    protected:

};

class Students :public person 
{
    private:
        int GPA;
        string Specialty;
        int Study_year;

    public:
        Students();
        Students(int id, string Name, int Age, bool Gander, int gpa, string specialty, int study_year);

        int getGPA() const;
        string getSPECIALTY() const;
        int getSTUDY_YEAR() const;
        void setGPA(const int gpa);
        void setSPECIALTY(const string specialty);
        void setSTUDY_YEAR(const int year);
        void printStudent()const ;

};

void Add_Student(map<int,Students> &ListStudents, const int num_Student);
void Delete_Student(map<int,Students> &ListStudents, const int key);
void Search_Student(map<int,Students> ListStudents, string name, int id, bool chosse);
const void View_Student(const map<int,Students> ListStudents);


class Teachers :public person 
{
    private:
        string Subject;
        string Email;
        int End_of_contract;

    public:
        Teachers();
        Teachers(int id, string Name, int Age,bool Gander, string subject, string email, int end_of_contract);


        string getSubject() const;
        string getEmail() const;
        int getEndOfContract() const;
        void setSubject(const string subject);
        void setEmail(const string email);
        void setEndOfContract(const int year);
        void printTeacher() const;

};

void Add_teacher(map<int, Teachers> &ListTeachers,int num_teacher);
void Delete_teacher(map<int, Teachers> &ListTeachers, const int key);
void Search_Teacher(map<int, Teachers> ListTeachers, string name, int id, bool chosse);
const void View_Teacher(const map<int, Teachers> ListTeachers);

class Courses 
{
    private:
        int ID;
        string Name;
        int Credits;
        int TeacherID;

    public:
        Courses();
        Courses(int id, string name, int credits, int teacherID);


        int getID() const;
        string getName() const;
        int getTeacherID() const;
        int getCredits() const;

        void setID(const int id);
        void setName(const string name);
        void setCredits(const int credits);
        void setTeacherID(const int TID);
        void printCourse() const;

};

void Add_course(map<int,Courses> &ListCourses, int num_course);
void  Delete_course(map<int,Courses> &ListCourses, const int key);
void Search_Course(map<int,Courses> ListCourses, string name, int id, bool chosse);
const void View_Courses(const map<int,Courses> ListCourses);

class Classes 
{

    private:
       int ID;
       vector<int> CoursesID;
       vector<int> TeachersID;
       vector<int> StudentsID;

    public:
        Classes();
        Classes(int id, vector<int> coursesID, vector<int> teachersID, vector<int> studentsID );

        int getID() const;
        vector<int> getCoursesID() const;
        vector<int> getTeachersID() const;
        vector<int> getStudentsID() const;

        void setID(const int id);
        void setCoursesID(const vector<int> CID, const int sizeC);
        void setTeachersID(const vector<int> TID, const int sizeT);
        void setStudentsID(const vector<int> SID, const int sizeS);

        void printClasses( map<int,Courses> ListCourses, map<int,Teachers> ListTeachers, map<int,Students> ListStudents) const;

};

void Add_classe(map<int,Classes> &ListClasses, int num_classes);
void  Delete_Classe(map<int,Classes> &ListClasses, const int key);
const void View_Classes(const map<int,Classes> ListClasses, const map<int,Courses> ListCourses, const map<int,Teachers> ListTeachers, const map<int,Students> ListStudents);

#endif // PERSON_H
