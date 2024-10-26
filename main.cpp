#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "person.h"

using namespace std;

void valid_choose(int &choose,const int num_choose);

int main()
{

  map<int,Students> ListStudents;
  map<int,Teachers> ListTeachers;
  map<int,Courses> ListCourses;
  map<int,Classes> ListClasses;

  while(true)
  {
    int choose;

    cout << "=====================================\n" << endl;
    cout << "Welcome to the database" << endl<< "=====================================\n" <<endl;

    cout << "Select an option: " << endl;

    cout << "=====================================" << endl;

    cout << "1: Add to database " << endl;
    cout << "2: Delete from database " << endl;
    cout << "3: Edit the database " << endl;
    cout << "4: Search database" << endl;
    cout << "5: View database " << endl;
    cout << "6: Exit" << endl;
    cout << "=====================================\n" << endl;


    valid_choose(choose,6);

    if (choose==6)
    {
      break;
    }

    if (choose == 1)
    {
      cout << "\n=====================================\n" << endl;
      cout << "Select an option: " << endl;

      cout << "=====================================" << endl;

      cout << "1: Add Student to database " << endl;
      cout << "2: Add Teacher to database  " << endl;
      cout << "3: Add Course to database  " << endl;
      cout << "4: Add Classe to database " << endl;
      cout << "=====================================\n" << endl;

      int choose1;
      valid_choose(choose1,4);

      if (choose1 == 1) 
      {
        cout << "Number of students you want to add: ";
        int num_Student;
        cin >> num_Student;
        Add_Student(ListStudents, num_Student);
      }

      if (choose1 == 2)
      {
        cout << "Number of teachers you want to add: ";
        int num_teacher;
        cin >> num_teacher;
        Add_teacher(ListTeachers, num_teacher);
      }

      if (choose1 == 3)
      {
        cout << "Number of courses you want to add: ";
        int num_course;
        cin >> num_course;
        Add_course(ListCourses, num_course);
      }

      if (choose1 == 4)
      {
        cout << "Number of Classes you want to add: ";
        int num_classes;
        cin >> num_classes;
        Add_classe(ListClasses,  num_classes);
      }

    }

    if (choose == 2)
    {
      cout << "\n=====================================\n" << endl;
      cout << "Select an option: " << endl;

      cout << "=====================================" << endl;

      cout << "1: Delete  Student from database " << endl;
      cout << "2: Delete  Teacher from database  " << endl;
      cout << "3: Delete  Course from database  " << endl;
      cout << "4: Delete  Classe from database " << endl;
      cout << "=====================================\n" << endl;

      int choose1;
      valid_choose(choose1, 4);

      if(choose1 == 1)
      {
        cout << "Enter the studentID you want to delete: ";
        int key;
        cin >> key;
        cout << "Is this the student you want to delete? \n";
        ListStudents[key].printStudent();
        cout << "Enter 1 to confirm deletion and 0 to cancel deletion. " << endl;
        bool yes_no;
        cin >> yes_no;
        if (yes_no)
        {
          Delete_Student(ListStudents, key);
        }

      }

      if(choose1 == 2)
      {
        cout << "Enter the teacherID you want to delete: ";
        int key;
        cin >> key;
        cout << "Is this the teacher you want to delete? \n";
        ListTeachers[key].printTeacher();
        cout << "Enter 1 to confirm deletion and 0 to cancel deletion. " << endl;
        bool yes_no;
        cin >> yes_no;
        if (yes_no)
        {
          Delete_teacher(ListTeachers, key);
        }
      }

      if(choose1 == 3)
      {
        cout << "Enter the courseID you want to delete: ";
        int key;
        cin >> key;
        cout << "Is this the course you want to delete? \n";
        ListCourses[key].printCourse();
        cout << "Enter 1 to confirm deletion and 0 to cancel deletion. " << endl;
        bool yes_no;
        cin >> yes_no;
        if (yes_no)
        {
          Delete_course(ListCourses, key);
        }
      }


      if(choose1 == 4)
      {
        cout << "Enter the ClasseID you want to delete: ";
        int key;
        cin >> key;
        cout << "Is this the Classe you want to delete? \n";
        ListClasses[key].printClasses(ListCourses, ListTeachers, ListStudents);
        cout << "Enter 1 to confirm deletion and 0 to cancel deletion. "<<endl;
        bool yes_no;
        cin >> yes_no;
        if (yes_no)
        {
          Delete_Classe( ListClasses,  key);
        }
      }
    }

    if (choose == 3)
    {
      cout << "\n=====================================\n" << endl;
      cout << "Select an option: " << endl;

      cout << "=====================================" << endl;

      cout << "1: Edit  Student from database " << endl;
      cout << "2: Edit  Teacher from database  " << endl;
      cout << "3: Edit  Course from database  " << endl;
      cout << "4: Edit  Classe from database " << endl;
      cout << "=====================================\n" << endl;

      int choose1;
      valid_choose(choose1, 4);

      if(choose1 == 1)
      {
        cout << "\n=====================================\n" << endl;
        cout << "What do you want to modify? " << endl;
        cout << "Select an option: " << endl;
        cout << "=====================================" << endl;
        cout << "1: Edit  Student name " << endl;
        cout << "2: Edit  Student age " << endl;
        cout << "3: Edit  Student gander " << endl;

        cout << "4: Edit  Student GPA " << endl;
        cout << "5: Edit  Student specialty " << endl;
        cout << "6: Edit  Student study year " << endl;
        cout << "=====================================\n" << endl;
        int choose2;
        valid_choose(choose2, 6);

        if(choose2 == 1)
        {
          cout << "Enter student ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the student you want to modify? " << endl;
          ListStudents[id].printStudent();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if(yes_no)
          {
            cout << " Enter new name: " << endl;
            string name;
            cin.ignore();
            getline(cin, name);
            ListStudents[id].setNAME(name);
          }
        }

        if(choose2 == 2)
        {
          cout << "Enter student ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the student you want to modify? " << endl;
          ListStudents[id].printStudent();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout<<" Enter new age: "<<endl;
            int age;
            cin>>age;
            ListStudents[id].setAGE(age);
          }
        }

        if (choose2 == 3)
        {
          cout << "Enter student ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the student you want to modify? " << endl;
          ListStudents[id].printStudent();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << " Enter new gander: (0 for female. 1 for male.) " << endl;
            bool gander;
            cin >> gander;
            ListStudents[id].setGander(gander);
          }
        }

        if (choose2 == 4)
        {
          cout << "Enter student ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the student you want to modify? " << endl;
          ListStudents[id].printStudent();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << " Enter new GPA: " << endl;
            int gpa;
            cin >> gpa;
            ListStudents[id].setGPA(gpa);
          }
        }
        if (choose2 == 5)
        {
          cout << "Enter student ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the student you want to modify? " << endl;
          ListStudents[id].printStudent();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout <<" Enter new specialty: " << endl;
            string specialty;
            cin.ignore();
            getline(cin,specialty);
            ListStudents[id].setSPECIALTY(specialty);
          }
        }

        if (choose2 == 6)
        {
          cout << "Enter student ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the student you want to modify? " << endl;
          ListStudents[id].printStudent();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if(yes_no)
          {
            cout << " Enter new study year: " << endl;
            int year;
            cin >> year;
            ListStudents[id].setSTUDY_YEAR(year);
          }
        }
      }

      if (choose1 == 2)
      {
        cout << "\n=====================================\n" << endl;
        cout << "What do you want to modify? " << endl;
        cout << "Select an option: " << endl;
        cout << "=====================================" << endl;
        cout << "1: Edit  Teacher name " << endl;
        cout << "2: Edit  Teacher age " << endl;
        cout << "3: Edit  Teacher gander " << endl;

        cout << "4: Edit  Teacher subject " << endl;
        cout << "5: Edit  Teacher email " << endl;
        cout << "6: Edit  Teacher end of contract " << endl;
        cout << "=====================================\n" << endl;
        int choose2;
        valid_choose(choose2, 6);
        if (choose2 == 1)
        {
          cout << "Enter teacher ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the teacher you want to modify? " << endl;
          ListTeachers[id].printTeacher();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << " Enter new name: " << endl;
            string name;
            cin.ignore();
            getline(cin,name);
            ListTeachers[id].setNAME(name);
          }
        }

        if (choose2 == 2)
        {
          cout << "Enter teacher ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the teacher you want to modify? " << endl;
          ListTeachers[id].printTeacher();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << " Enter new age: " << endl;
            int age;
            cin >> age;
            ListTeachers[id].setAGE(age);
          }
        }

        if (choose2 == 3)
        {
          cout << "Enter teacher ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the teacher you want to modify? " << endl;
          ListTeachers[id].printTeacher();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << " Enter new gander: (0 for female. 1 for male.) " << endl;
            bool gander;
            cin >> gander;
            ListTeachers[id].setGander(gander);
          }
        }

        if (choose2 == 4)
        {
          cout << "Enter teacher ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the teacher you want to modify? " << endl;
          ListTeachers[id].printTeacher();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << " Enter new subject: " << endl;
            string subject;
            cin.ignore();
            getline(cin, subject);
            ListTeachers[id].setSubject(subject);
          }
        }

        if (choose2 == 5)
        {
          cout << "Enter teacher ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the teacher you want to modify? " << endl;
          ListTeachers[id].printTeacher();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << " Enter new email: " << endl;
            string email;
            cin.ignore();
            getline(cin,email);
            ListTeachers[id].setEmail(email);
          }
        }

        if (choose2 == 6)
        {
          cout << "Enter teacher ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the teacher you want to modify? " << endl;
          ListTeachers[id].printTeacher();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << " Enter new date of End of contract: " << endl;
            int end_of_contract;
            cin >> end_of_contract;
            ListTeachers[id].setEndOfContract(end_of_contract);
          }
        }
      }

      if (choose1 == 3)
      {
        cout << "\n=====================================\n" << endl;
        cout << "What do you want to modify? " << endl;
        cout << "Select an option: " << endl;
        cout << "=====================================" << endl;
        cout << "1: Edit  Course name " << endl;
        cout << "2: Edit  Course credits " << endl;
        cout << "3: Edit  Course teacherID " << endl;
        cout << "=====================================\n" << endl;

        int choose2;
        valid_choose(choose2,3);
          
        if (choose2 == 1)
        {
          cout << "Enter course ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the course you want to modify? " << endl;
          ListCourses[id].printCourse();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << " Enter new name : " << endl;
            string name;
            cin.ignore();
            getline(cin, name);
            ListCourses[id].setName(name);
          }
        }

        if (choose2 == 2)
        {
          cout << "Enter course ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the course you want to modify? " << endl;
          ListCourses[id].printCourse();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << " Enter new credits: " << endl;
            int credits;
            cin >> credits;
            ListCourses[id].setCredits(credits);
          }
        }

        if (choose2 == 3)
        {
          cout << "Enter course ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the course you want to modify? " << endl;
          ListCourses[id].printCourse();
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << " Enter new teacherID: " << endl;
            int teacherID;
            cin >> teacherID;
            cout << "Is this the teacher you want to add? " << endl;
            ListTeachers[teacherID].printTeacher();
            cout << "(If yes, enter 1, if no, enter 0)" << endl;
            bool yes;
            cin >> yes;
            if(yes)
            { 
              ListCourses[id].setTeacherID(teacherID);
            }
          }
        }
      }

      if (choose1 == 4)
      {
        cout << "\n=====================================\n" << endl;
        cout << "What do you want to modify? " << endl;
        cout << "Select an option: " << endl;
        cout << "=====================================" << endl;
        cout << "1: Edit  Classe coursesID " << endl;
        cout << "2: Edit  Classe teachersID " << endl;
        cout << "3: Edit  Classe StudentsID " << endl;
        cout << "=====================================\n" << endl;

        int choose2;
        valid_choose(choose2,3);

        if (choose2 == 1)
        {
          cout << "Enter classe ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the classe you want to modify? " << endl;
          ListClasses[id].printClasses(ListCourses, ListTeachers,ListStudents);
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << "How many coursesIDs do you want to change : " << endl;
            int num_change;
            cin >> num_change;
            for (int i = 0; i < num_change ;i++)
            {
              vector<int> ListCourseID = ListClasses[id].getCoursesID();
              for (int j = 0; j < ListCourseID.size(); j++)
              {
                cout << "The position: " << j << " CourseID: " << ListCourseID[j] << " || ";
              }
                cout << "\nLocate the position of CourseID you want to change" << endl;
                int position;
                cin >> position;
                cout << "Enter the new CourseID : " << endl;
                int newID;
                cin >> newID;
                ListCourseID[position] = newID;
                ListClasses[id].setCoursesID(ListCourseID, 0);
            }
          }
        }

        if (choose2 == 2)
        {
          cout << "Enter classe ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the classe you want to modify? " << endl;
          ListClasses[id].printClasses(ListCourses, ListTeachers, ListStudents);
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << "How many teachersIDs do you want to change : " << endl;
            int num_change;
            cin >> num_change;
            for(int i = 0; i < num_change; i++)
            {
              vector<int> ListeachersID = ListClasses[id].getTeachersID();
              for (int j = 0; j < ListeachersID.size(); j++)
              {
                cout << "The position: " << j << " TeachersID: " << ListeachersID[j] << " || ";
              }
              cout << "\nLocate the position of TeachersID you want to change" << endl;
              int position;
              cin >> position;
              cout << "Enter the new TeachersID : " << endl;
              int newID;
              cin >> newID;
              ListeachersID[position] = newID;
              ListClasses[id].setTeachersID(ListeachersID, 0);
            }
          }
        }

        if (choose2 == 3)
        {
          cout << "Enter classe ID: " << endl;
          int id;
          cin >> id;
          cout << "Is this the classe you want to modify? " << endl;
          ListClasses[id].printClasses(ListCourses, ListTeachers, ListStudents);
          cout << "(If yes, enter 1, if no, enter 0)" << endl;
          bool yes_no;
          cin >> yes_no;
          if (yes_no)
          {
            cout << "How many studentsIDs do you want to change : " << endl;
            int num_change;
            cin >> num_change;
            for (int i = 0; i < num_change; i++)
            {
              vector<int> ListstudentsID = ListClasses[id].getStudentsID();
              for (int j = 0; j < ListstudentsID.size(); j++)
              {
                cout << "The position: " << j << " TeachersID: " << ListstudentsID[j] << " || ";
              }
              cout << "\nLocate the position of studentID you want to change" << endl;
              int position;
              cin >> position;
              cout << "Enter the new studentID : " << endl;
              int newID;
              cin >> newID;
              ListstudentsID[position] = newID;
              ListClasses[id].setStudentsID(ListstudentsID, 0);
            }
          }
        }
      }
    }

    if (choose == 4)
    {
      cout << "=====================================\n" << endl;
      cout << "Select an option: " << endl;
      cout << "\n=====================================" << endl;

      cout << "1: Search for a Student " << endl;
      cout << "2: Search for a Teacher " << endl;
      cout << "3: Search for a Course " << endl;
      cout << "4: Search for a Classe " << endl;
      cout << "=====================================\n" << endl;

      int choose1;
      valid_choose(choose1,4);

      if (choose1 == 1)
      {
        cout << "Do you want to search by StudentName(1) or StudentID(0): (Enter the number in front of the option) " << endl;
        bool sear;
        cin >> sear;
        if(sear)
        {
          cout << "Enter StudentName: ";
          string name;
          cin >> name;
          Search_Student(ListStudents,name,0,sear);
        }
        else
        {
          cout << "Enter StudentID: ";
          int id;
          cin >> id;
          Search_Student(ListStudents,"non",id,sear);
        };
      }

      if (choose1 == 2)
      {
        cout << "Do you want to search by TeacherName(1) or TeacherID(0): (Enter the number in front of the option) " << endl;
        bool sear;
        cin >> sear;
        if (sear)
        {
          cout << "Enter TeacherName: ";
          string name;
          cin >> name;
          Search_Teacher(ListTeachers, name, 0, sear);
        }
        else
        {
          cout << "Enter TeacherID: ";
          int id;
          cin >> id;
          Search_Teacher(ListTeachers, "non", id, sear);
        };

      }

      if (choose1 == 3)
      {
        cout << "Do you want to search by CourseName(1) or CourseID(0): (Enter the number in front of the option) " << endl;
        bool sear;
        cin >> sear;
        if (sear)
        {
          cout << "Enter CourseName: ";
          string name;
          cin >> name;
          Search_Course(ListCourses, name, 0, sear);
        }
        else
        {
          cout << "Enter CourseID: ";
          int id;
          cin >> id;
          Search_Course(ListCourses,"non" ,id,sear);
        };
      }

      if(choose1 == 4)
      {
        cout << "Enter ClasseID: ";
        int classeID;
        cin >> classeID;
        if (ListClasses.count(classeID))
        {
          ListClasses[classeID].printClasses(ListCourses, ListTeachers,ListStudents);
        }
        else
        {
          cout << "====Not found1====" << endl;
        };
      }
    }

    if (choose == 5)
    {

      cout << "=====================================\n" << endl;
      cout << "Select an option: " << endl;
      cout << "\n=====================================" << endl;

      cout << "1: View Student database " << endl;
      cout << "2: View Teacher database  " << endl;
      cout << "3: View Course database  " << endl;
      cout << "4: View Classe database " << endl;
      cout << "5: View all database " << endl;
      cout << "=====================================\n" << endl;

      int choose1;
      valid_choose(choose1, 5);

      if (choose1 == 1)
      {
        View_Student(ListStudents);
      }

      if (choose1 == 2)
      {
        View_Teacher(ListTeachers);
      }

      if(choose1 == 3)
      {
        View_Courses(ListCourses);
      }

      if(choose1 == 4)
      {
        View_Classes(ListClasses, ListCourses, ListTeachers,  ListStudents);
      }

      if(choose1 == 5)
      {
        cout << "=====================================\n" << endl;
        cout << "Students: "<<endl;
        cout << "=====================================\n" << endl;
        View_Student(ListStudents);


        cout << "\n=====================================\n" << endl;
        cout << "Teacher: "<<endl;
        cout << "=====================================\n" << endl;
        View_Teacher(ListTeachers);

        cout << "\n=====================================\n" << endl;
        cout << "Courses: "<<endl;
        cout << "=====================================\n" << endl;
        View_Courses(ListCourses);

        cout << "\n=====================================\n" << endl;
        cout << "Classes: "<<endl;
        View_Classes(ListClasses, ListCourses, ListTeachers,  ListStudents);
        cout << "=====================================\n" << endl;
      }
    }
  }

  return 0;
}

void valid_choose(int &choose, const int num_choose)
{
  do
  {
    cin >> choose;
    if(choose <= 0 || choose > num_choose)
    {
      cout << "Wrong choice\nTry again\n";
    }
  }
  while(choose <= 0 || choose > num_choose);
}