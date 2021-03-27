#include<bits/stdc++.h>

using namespace std;

//This is a class to store Subject Information
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
            cout<<"Mark for "<<subject_name<<" Quiz "<<i+1<<" : ";
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
    // Conatins:
    //Student Name
    // Roll Number
    //Subject Name
public:
    string student_name;
    int roll_number;


public:
    void set_student_name() {
        printf("Enter Student Name :\n");
        getline(cin, student_name);

    }

    void set_student_roll() {
        printf("Enter Student Roll Number :\n");
        cin >> roll_number;

    }

    string get_student_name() {
        return student_name;

    }

    int get_student_roll() {
        return roll_number;
    }


};


//Inherited from Student Class
class StudentDemo : public Student {
    Subject *course;
    double Student_Total_Marks;
    int no_of_subject;

//Constructor
public:
    StudentDemo() {
        Student_Total_Marks = 0;
        no_of_subject = 0;
        course = nullptr;

        //Inherited Methods from Student Class
        set_student_name();
        set_student_roll();


        get_subject_info();
    };

    void get_subject_info() {
        printf("Enter the Number of Subject: \n");

        cin >> no_of_subject;
        course = new Subject[no_of_subject];

        for (int i = 0; i < no_of_subject; i++) {
            Student_Total_Marks += course[i].subject_info();
        }

        printAll();
    }

    void printAll() {
        cout << "Student Name : " << get_student_name() << endl;
        cout << "Roll : " << get_student_roll() << endl;
        cout << "Student's Total Mark from All Courses : " << Student_Total_Marks << endl;
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
    StudentDemo *Akif = new StudentDemo();


//     cout << "Freed" << endl;

}

/*
 *


 */
