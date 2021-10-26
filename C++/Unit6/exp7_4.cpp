#include <iostream>
using namespace std;

class Person
{
    char name[20];
    char sex[5];
    char id_card[20];
    char birth[20];

    public:
        Person(char* name, char* sex, char* id_card, char* birth)
        {
            strcpy(this->name, name);
            strcpy(this->sex, sex);
            strcpy(this->id_card, id_card);
            strcpy(this->birth, birth);
        }
        
        void Show()
        {
            // cout<<"信息又:<<endl;
            cout<<"姓名:"<<name<<endl;
            cout<<"性别:"<<sex<<endl;
            cout<<"生份证号:"<<id_card<<endl;
            cout<<"生日:"<<birth<<endl;
        }
};


class Student: virtual public Person
{
    char no[20];
    int  grade;

    public:
        Student(char* no, int grade, char* name, char* sex, char* id_card, char* birth):Person(name, sex, id_card, birth)
        {
            strcpy(this->no, no);
            this->grade = grade;
        }

        void Show()
        {
            // cout<<"学生信息有:"<<endl;
            // Person::Show();
            cout<<"学生学号:"<<no<<endl;
            cout<<"学生成绩:"<<grade<<endl;
        }
};


class Teacher:virtual public Person
{
    char position[10];

    public:
        Teacher(char* pos, char* name, char* sex, char* id_card, char* birth):Person(name, sex, id_card, birth)
        {
            strcpy(this->position, pos);
        }

        void Show()
        {
            // cout<<"教师信息:"<<endl;
            // Person::Show();
            cout<<"职位:"<<position<<endl;
        }
};


class Stu_Tech: public Student, public Teacher
{
    public:
        Stu_Tech(char* pos, char* no, int grade, char* name, char* sex, char* id_card, char* birth)
        :Person(name, sex, id_card, birth), Teacher(pos, name, sex, id_card, birth), Student(no, grade, name, sex, id_card, birth)
        {
            cout<<"stu_tea constructing..."<<endl;
        }

        void Show()
        {
            cout<<"stu_teacher info:"<<endl;
            Person::Show();
            Student::Show();
            Teacher::Show();
        }
};

int main()
{
    class Stu_Tech St("讲师", "2020", 100, "hello", "男", "3838", "0501");
    St.Show();
}