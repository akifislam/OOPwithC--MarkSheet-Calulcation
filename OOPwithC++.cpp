#include<bits/stdc++.h>

using namespace std;

//Student Class
class Subject {
public:
    string subject_name;
    string Subject_Code;
    vector<double> quiz_marks;
    double final_marks;

    Subject() {
        final_marks = 0;
    }

    // Subject Name, Quiz Calculation
    double subject_info() {
        printf("Enter Subject Name :");
        cin >> subject_name;

        printf("Enter Subject Code :");
        cin >> Subject_Code;

        int no_of_quiz, quiz_mark;
        printf("Enter No of Quiz :");
        cin >> no_of_quiz;

        for (int i = 0; i < no_of_quiz; i++) {
            cin >> quiz_mark;
            quiz_marks.push_back(quiz_mark);
            final_marks += quiz_mark;
        }
//            print_marks();
        return final_marks;
    }

    void print_marks() {
        cout << "Subject Name : " << subject_name << endl;
        cout << "Subject Code : " << Subject_Code << endl;
        cout << "=== QUIZ MARKS of " << subject_name << "===" << endl;
        for (int i = 0; i < quiz_marks.size(); i++) {
            printf("Quiz %d : %.2lf\t", i + 1, quiz_marks[i]);
        }
        cout << endl;
        cout << "== == == == ==" << endl;
        cout << "Total Marks from Course " << subject_name << " is : " << final_marks << endl;
        cout << endl;

    }


};


class Student {


    //Member
private :
    double Student_Total_Marks ;
    string student_name;
    int roll_number;
    double final_marks;
    int no_of_subject;
    Subject *course;


public :
    //Constructor
    Student() {
        //This funciton will take input of Student's Name and Roll Number Only
        Student_Total_Marks = 0;
        user_basic_info();
    }

public:

    void user_basic_info() {

        printf("Enter Student Name :\n");
        getline(cin, student_name);
        printf("Enter Student Roll Number :\n");
        cin >> roll_number;

        printf("Enter the Number of Subject: \n");


        cin >> no_of_subject;
        course = new Subject[no_of_subject];


        for (int i = 0; i < no_of_subject; i++) {
            Student_Total_Marks+=course[i].subject_info();
        }
        printAll();


    }

    void printAll() {
        cout << "Student Name : " << student_name << endl;
        cout << "Roll : " << roll_number << endl;
        cout<<"Student's Total Mark from All Courses : "<<Student_Total_Marks<<endl;
        cout << endl;
        cout << endl;
        cout << endl;

        for (int i = 0; i < no_of_subject; i++) {
           course[i].print_marks();
        }
    }

    void DestroyEverything() {
        free(course);
    }

};

int main() {
    Student *s;
    s = new Student();
//     cout << "Deleting All References" << endl;
    free(s);
    s = nullptr;

//     cout << "Freed" << endl;

}

/*
 *


 */
