#include "person.h"
#include <iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;
int TotalStudents_ID = 0;
int NumberDeletedStudents = 0;

int TotalTeachers_ID = 0;
int NumberDeletedTeachers = 0;

int Totalcourses_ID = 0;
int NumberDeletedcourses = 0;

int Totalclasses_ID = 0;
int NumberDeletedclasses = 0;


person::person():ID(0), name("non"), age(0), gander(0) {}

person::person(int id, string Name, int Age, bool Gander): ID(id), name(Name), age(Age), gander(Gander) {}


int person::getAGE()const
{ 
  return age;
}

string person::getNAME()const 
{
  return name;
}

int person::getID()const 
{
  return ID;
}

bool person::getGander() const 
{
  return gander;
}

void person::setID(const int id)
{
  ID = id;
}

void person::setNAME(const string namee) 
{
  name = namee;
}

void person::setAGE(const int AGE) 
{
  age = AGE;
}

void person::setGander(const bool Gander) 
{
  gander = Gander;
}

person::~person() {}

//Students part
Students::Students(): GPA(0), Specialty("non"), Study_year(0) {}
Students::Students(int id, string Name, int Age, bool Gander, int gpa, string specialty, int study_year): person(id, Name, Age, Gander), GPA(gpa), Specialty(specialty), Study_year(study_year) {}

int Students::getGPA()const 
{
  return GPA;
}

string Students::getSPECIALTY()const 
{
  return Specialty;
}

int Students::getSTUDY_YEAR()const 
{
  return Study_year;
}

void Students::setGPA(const int gpa)
{
  GPA = gpa;
}

void Students::setSPECIALTY(const string specialty)
{
  Specialty = specialty;
}

void Students::setSTUDY_YEAR(const int year)
{
  Study_year = year;
}

void Students::printStudent() const 
{
  string Gander = (gander) ? "Male" : "Female";
  cout << "Student's ID: " << ID << "|| his name: " << name << "|| his age: " << age << "|| Gander: " << Gander << "|| his GPA: " << GPA << "|| his major: " << Specialty << "|| his year of study: " << Study_year << endl << endl;
}

void Add_Student(map<int,Students> &ListStudents, const int num_Student)
{
  int sizee = (TotalStudents_ID + num_Student);
  for (int i = TotalStudents_ID; i < sizee; i++) //TotalStudents_ID is the last ID on the list
  { 
    ListStudents[i].setID(i);
    cout << "\nName: ";
    string name;
    cin.ignore();
    getline(cin, name);
    ListStudents[i].setNAME(name);

    cout << "\nAge: ";
    int age;
    cin >> age;
    ListStudents[i].setAGE(age);

    cout << "\nGander: (1 for male, 0 for female) ";
    bool gander;
    cin >> gander;
    ListStudents[i].setGander(gander);

    cout << "\nGPA: ";
    int gpa;
    cin >> gpa;
    ListStudents[i].setGPA(gpa);

    cout << "\nSpecialty: ";
    string specialty;
    cin.ignore();
    getline(cin, specialty);
    ListStudents[i].setSPECIALTY(specialty);

    cout << "\nStudy year: ";
    int year;
    cin >> year;
    ListStudents[i].setSTUDY_YEAR(year);

    TotalStudents_ID++;
  }
}

void Delete_Student(map<int,Students> &ListStudents, const int key)
{
  ListStudents.erase(key);
  NumberDeletedStudents++;
}

void Search_Student(map<int,Students> ListStudents, string name, int id, bool chosse)
{
  if (chosse)
  {
    bool true_false=false;
    for (const auto& pair : ListStudents) 
    {
      if (pair.second.getNAME() == name) 
      {
        cout << "=====================================" << endl;
        cout << "The student has been found." << endl;
        int studentID = pair.first ;
        ListStudents[studentID].printStudent();
        cout << "===========================================" << endl;
        true_false = true;
      }
    }
    if((!true_false))
    {
      cout << "====Not found====" << endl;
    }
  }
  else
  {
    if (ListStudents.count(id))
    {
      cout << "=====================================" << endl;
      cout << "The student has been found." << endl;
      ListStudents[id].printStudent();
      cout << "=====================================" << endl;
    }
    else
    {
      cout << "====Not found====" << endl;
    };
  };
}

const void View_Student(const map<int,Students> ListStudents)
{
  cout << "==================================" << endl;
  cout << "The total number of students is: " << (TotalStudents_ID-NumberDeletedStudents) << endl;
  cout << "==================================" << endl;
  for (const auto& pair : ListStudents) 
  {
    pair.second.printStudent();
  }
}

//Professors part
Teachers::Teachers(): Subject("non"), Email("non"), End_of_contract(0) {}
Teachers::Teachers(int id, string Name, int Age, bool Gander, string subject, string email, int end_of_contract): person(id, Name, Age, Gander), Subject(subject), Email(email), End_of_contract(end_of_contract) {}


string Teachers::getSubject() const 
{
  return Subject;
}

string Teachers::getEmail() const 
{
  return Email;
}

int Teachers::getEndOfContract() const 
{
  return End_of_contract;
}

void Teachers::setSubject(const string subject)
{
  Subject = subject;
}

void Teachers::setEmail(const string email)
{
  Email = email;
}

void Teachers::setEndOfContract(const int year)
{
  End_of_contract = year;
}

void Teachers::printTeacher() const 
{
  string Gander = (gander) ? "Male" : "Female";
  cout << "Teacher's ID: " << ID << "|| his name: " << name << "|| his age: " << age << "|| Gander: " << Gander << "|| his subject: " << Subject << "|| his email: " << Email << "|| his contract ends: " << End_of_contract << endl << endl;
}

void Add_teacher(map<int,Teachers> &ListTeachers, int num_teacher)
{
  int sizee = (TotalTeachers_ID + num_teacher);
  for (int i = TotalTeachers_ID; i < sizee; i++) //TotalTeachers_ID is the last ID on the list
  { 
    ListTeachers[i].setID(i);
    cout << "\nName: ";
    string name;
    cin.ignore();
    getline(cin, name);
    ListTeachers[i].setNAME(name);

    cout << "\nAge: ";
    int age;
    cin >> age;
    ListTeachers[i].setAGE(age);

    cout << "\nGander: (1 for male, 0 for female) ";
    bool gander;
    cin >> gander;
    ListTeachers[i].setGander(gander);

    cout << "\nSubject: ";
    string subject;
    cin.ignore();
    getline(cin, subject);

    ListTeachers[i].setSubject(subject);

    cout << "\nEmail: ";
    string email;
    cin >> email;
    ListTeachers[i].setEmail(email);

    cout << "\nEnd Of Contract: ";
    int year;
    cin >> year;
    ListTeachers[i].setEndOfContract(year);
    TotalTeachers_ID++;
  }
}

void Delete_teacher(map<int,Teachers> &ListTeachers, const int key)
{
  ListTeachers.erase(key);
  NumberDeletedTeachers++;
}


void Search_Teacher(map<int,Teachers> ListTeachers, string name, int id, bool chosse)
{
  if (chosse)
  {
    bool true_false = false;
    for (const auto& pair : ListTeachers) 
    {
      if (pair.second.getNAME() == name) 
      {
        cout << "=====================================" << endl;
        cout << "The teacher has been found." << endl;
        int TeacherID = pair.first ;
        ListTeachers[TeacherID].printTeacher();
        cout << "===========================================" << endl;
        true_false = true;
      }
    }
    if(!true_false)
    {
      cout << "====Not found1====" << endl;
    }
  }
  else
  {
    if (ListTeachers.count(id))
    {
      cout << "=====================================" << endl;
      cout << "The teacher has been found." << endl;
      ListTeachers[id].printTeacher();
      cout << "=====================================" << endl;
    }
    else
    {
      cout << "====Not found====" << endl;
    };
  };
}

const void View_Teacher(const map<int,Teachers> ListTeachers)
{
  cout << "======================================" << endl;
  cout << "The total number of Teachers is: " << (TotalTeachers_ID - NumberDeletedTeachers) << endl;
  cout << "======================================" << endl;
  for (const auto& pair : ListTeachers) 
  {
    pair.second.printTeacher();
  }
}

//Course part
Courses::Courses(): ID(0), Name("non"), Credits(0), TeacherID(0) {};
Courses::Courses(int id, string name, int credits, int teacherID): ID(id), Name(name), Credits(credits), TeacherID(teacherID) {};

int Courses::getID() const 
{
  return ID;
}
string Courses::getName()const 
{
  return Name;
}
int Courses::getCredits() const 
{
  return Credits;
}
int Courses::getTeacherID()const 
{
  return TeacherID;
}

void Courses::setID(const int id)
{
  ID = id;
}
void Courses::setName(const string name)
{
  Name = name;
}
void Courses::setCredits(const int credits)
{
  Credits = credits;
}
void Courses::setTeacherID(const int TID)
{
  TeacherID = TID;
}

void Courses::printCourse()const 
{
  cout << "Course ID: " << ID << "|| Name: " << Name << "|| Credits: " << Credits << "|| Responsible teacherID: " << TeacherID<<endl;
}

void Add_course(map<int,Courses> &ListCourses, int num_course)
{
  //Add a feature to display all teachers and teachersID
  int sizee = (Totalcourses_ID + num_course);
  for (int i = Totalcourses_ID; i < sizee; i++) //Totalcourses_ID is the last ID on the list
  { 
    ListCourses[i].setID(i);

    cout << "\nName: ";
    string name;
    cin.ignore();
    getline(cin, name);
    ListCourses[i].setName(name);

    cout << "\nCredits: ";
    int credits;
    cin >> credits;
    ListCourses[i].setCredits(credits);

    cout << "\nTeacherID: "; 
    int TID;
    cin >> TID;
    ListCourses[i].setTeacherID(TID);

    Totalcourses_ID++;
  }
}

void Search_Course(map<int,Courses> ListCourses, string name , int id, bool chosse)
{
  if (chosse)
  {
    bool true_false = false;
    for (const auto& pair : ListCourses) 
    {
      if (pair.second.getName() == name) 
      {
        cout << "=====================================" << endl;
        cout << "The Courses has been found." << endl;
        int CourseID = pair.first ;
        ListCourses[CourseID].printCourse();
        cout << "===========================================" << endl;
        true_false = true;
      }
    }
    if (!true_false)
    {
      cout << "====Not found1====" << endl;
    }

  }
  else
  {
    if (ListCourses.count(id))
    {
      cout << "=====================================" << endl;
      cout << "The Courses has been found." << endl;
      ListCourses[id].printCourse();
      cout << "=====================================" << endl;
    }
    else
    {
      cout << "====Not found====" << endl;
    };
  };
}

void  Delete_course(map<int,Courses> &ListCourses, const int key)
{
  ListCourses.erase(key);
  NumberDeletedcourses++;
}

const void View_Courses(const map<int,Courses> ListCourses)
{
  cout << "=========================================" << endl;
  cout << "The total number of Courses is: " << (Totalcourses_ID - NumberDeletedcourses) << endl;
  cout << "=========================================" << endl;
  for (const auto& pair : ListCourses) 
  {
    pair.second.printCourse();
  }
}

//Classes part
Classes::Classes() {}
Classes::Classes(int id, vector<int> coursesID, vector<int> teachersID, vector<int> studentsID ): ID(id), CoursesID(coursesID), TeachersID(teachersID), StudentsID(studentsID) {}

int Classes::getID() const 
{
  return ID;
}
vector<int> Classes::getCoursesID() const 
{
  return CoursesID;
}
vector<int> Classes::getTeachersID() const 
{
  return TeachersID;
}
vector<int> Classes::getStudentsID() const 
{
  return StudentsID;
}

void Classes::setID(const int id)
{
  ID = id;
};

void Classes::setCoursesID(const vector<int> CID, const int sizeC)
{
  int oldSize = CoursesID.size();
  CoursesID.resize(oldSize + sizeC);
  if (oldSize == CoursesID.size())
  {
    for(int i = 0; i < oldSize; i++)
    {
      CoursesID[i] = CID[i];
    }
  }
  for (int i = 0; i < sizeC; i++)
  {
    CoursesID[i] = CID[i];
  }
}

void Classes::setTeachersID(const vector<int> TID, const int sizeT)
{
  int oldSize = TeachersID.size();
  TeachersID.resize(oldSize + sizeT);

  if(oldSize == TeachersID.size())
  {
    for(int i = 0; i < oldSize; i++)
    {
      TeachersID[i] = TID[i];
    }
  }

  for (int i = 0; i < sizeT; i++)
  {
    TeachersID[i]= TID[i];
  }
}

void Classes::setStudentsID(const vector<int> SID, const int sizeS)
{
  int oldSize = StudentsID.size();
  StudentsID.resize(oldSize + sizeS);

  if(oldSize == StudentsID.size())
  {
    for (int i = 0;i < oldSize; i++)
    {
      StudentsID[i] = SID[i];
    }
  }

  for (int i = 0; i < sizeS; i++)
  {
    StudentsID[i]= SID[i];
  }
}

void Classes::printClasses(map<int,Courses> ListCourses, map<int,Teachers> ListTeachers, map<int,Students> ListStudents) const 
{
  cout << "\n=====================================" << endl;
  cout << "ClasseID: " << ID <<endl;
  cout << "=====================================\n" << endl;
  cout << "Class Courses: "<<endl;

  if ((CoursesID.size()) != 0)
  {
    for (int i = 0 ; i < (int)CoursesID.size(); i++)
    {
      int IDindex = CoursesID[i];
      string name = ListCourses[IDindex].getName();
      if (name == "non")
      { 
        continue;
      }
      ListCourses[IDindex].printCourse();
    }
  }
  else
  {
    cout << "There are no courses.\n";
  };

  cout << "\n=====================================\n" << endl;
  cout << "\nClass Teachers: " << endl;
  cout << "=====================================" << endl;

  if((TeachersID.size()) != 0)
  {
    for (int i = 0 ; i < (int)TeachersID.size(); i++)
    {
      int IDindex = TeachersID[i];
      string name = ListTeachers[IDindex].getNAME();
      if(name == "non")
      {
        continue;
      }
      ListTeachers[IDindex].printTeacher();
    }
  }
  else
  {
    cout << "There are no Teachers.\n";
  };

  cout << "=====================================" ;
  cout << "\nClass Students: " << endl;
  cout << "=====================================\n" << endl;

  if ((StudentsID.size()) != 0)
  {
    int sizeprint = (int)StudentsID.size();
    for (int i = 0 ; i < sizeprint ; i++)
    {
      int IDindex = StudentsID[i];
      string name = ListStudents[IDindex].getNAME();
      if(name == "non")
      {
        continue;
      }
      ListStudents[IDindex].printStudent();
    }
  }
  else
  {
    cout << "There are no Students.\n";
  };
}

void Add_classe(map<int,Classes> &ListClasses, int num_classes)
{
  //Add a feature to display all teachers, teachersID, courses, coursesID, students and studentsID
  int sizee = (Totalclasses_ID + num_classes);
  for (int i= Totalclasses_ID; i < sizee; i++) //Totalclasses_ID is the last ID on the list
  { 
    cout << "=============================\n";
    cout << "classe N" << i+1 << endl;

    ListClasses[i].setID(i);

    vector<int> CID;
    int sizeC;
    cout << "\nHow many courses do you want to add: ";
    cin >> sizeC;
    CID.resize(sizeC);
    cout << "(Enter the ID not the name)" << endl;
    for (int i = 0; i < sizeC; i++)
    {
      cin >> CID[i];
    }
    ListClasses[i].setCoursesID(CID, sizeC);

    vector<int> TID;
    int sizeT;
    cout << "\nHow many Teachers do you want to add: ";
    cin >> sizeT;
    cout << "(Enter the ID not the name)" << endl;
    TID.resize(sizeT);
    for (int i = 0; i < sizeT; i++)
    {
      cin >> TID[i];
    }
    ListClasses[i].setTeachersID(TID, sizeT);

    vector<int> SID;
    int sizeS;
    cout << "\nHow many Students do you want to add: ";
    cin >> sizeS;
    SID.resize(sizeS);
    cout << "(Enter the ID not the name)" << endl;
    for (int i = 0; i < sizeS; i++)
    {
      cin >> SID[i];
    }
    ListClasses[i].setStudentsID(SID, sizeS);
    Totalclasses_ID++;
  }
}

void  Delete_Classe(map<int,Classes> &ListClasses, const int key)
{
  ListClasses.erase(key);
  NumberDeletedclasses++;
}

const void View_Classes(const map<int,Classes> ListClasses, const map<int,Courses> ListCourses, const map<int,Teachers> ListTeachers, const map<int,Students> ListStudents)
{
  cout << "=========================================" << endl;
  cout << "The total number of Courses is: " << (Totalclasses_ID - NumberDeletedclasses) << endl;
  cout << "=========================================" << endl;
  for (const auto& pair : ListClasses) 
  {
    pair.second.printClasses(ListCourses, ListTeachers, ListStudents) ;
  }
}



