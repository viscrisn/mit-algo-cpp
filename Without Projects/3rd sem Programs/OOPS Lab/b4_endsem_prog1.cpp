#include<iostream>

using namespace std;

class student
{
        int id;
        char name[30];
    public:
        student();
        void studentdisplay();

};

class sports : virtual public student
{
        char s_grade;
    public:
        sports();
        void sportsdisplay();
};

class exam : virtual public student
{
        char e_grade;
    public:
        exam();
        void examdisplay();
};
class results : public sports, public exam
{
    public:
        void resultdisplay();
};

student::student()
{
    cout<<"Enter name and id number\n";
    cin>>name;
    cin>>id;

}

void student::studentdisplay()
{
    cout<<"name and id:"<<name<<"\t"<<id<<endl;
}
sports::sports()
{
    cout<<"Enter Sports grade\n";
    cin>>s_grade;
}
void sports::sportsdisplay()
{
    cout<<"The sports grade is:\t"<<s_grade<<endl;
}

exam::exam()
{
    cout<<"Enter exams grade\n";
    cin>>e_grade;
}
void exam::examdisplay()
{
    cout<<"The exam grade is:\t"<<e_grade<<endl;
}
void results::resultdisplay()
{
    studentdisplay();
    sportsdisplay();
    examdisplay();

}


int main()
{
    results r1;
    r1.resultdisplay();

}
