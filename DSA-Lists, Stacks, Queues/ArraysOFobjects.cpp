#include <iostream>
using namespace std;

class Student
{
    public:
    string Name;
    int Age;
    char Gender;
    float ProgrammingGrade;

    Student(){}
    Student(string name, int age, char gender, float porgrammingGrade)
    {
        Name = name;
        Age = age;
        Gender = gender;
        ProgrammingGrade= porgrammingGrade;
    }
};

int main()
{
    int luckyNumbers[5] = {1,3,5,13,21};

    /*Student s1;
    s1.Name= "Saldina";
    s1.Age = 28;               // First APPROACH
    s1.Gender = 'f';
    s1.ProgrammingGrade = 9;

    Student students[3];
    students[0]=s1;*/

    /*Student students[3]= {
        {"Saldina", 28, 'f', 9},
        {"Elon", 58, 'm', 10},        // Second APPROACH
        {"Bill", 60, 'm', 7}
    };*/

    Student students[3];
    for (int i = 0; i < 3; i++)
    {
        cout<<"Student "<<i+1 <<endl;

        Student s;
        cout<<"Enter Name:"<<endl;
        cin>>s.Name;
        cout<<"Enter Age:"<<endl;     // Third APPROACH
        cin>>s.Age;
        cout<<"Enter Gender:"<<endl;
        cin>>s.Gender;
        cout<<"Enter Programming Grade:"<<endl;
        cin>>s.ProgrammingGrade;

        students[i] = s;
    }

    cout<<"Programming Grade of first student is" << students[0].ProgrammingGrade;
    return 0;
}