#include <iostream>
#include <algorithm>
using namespace std;

class Student
{
    public:
    string Name;
    int Age;
    char Gender;
    float ProgrammingGrade;

    Student(string name, int age, char gender, float programmingGrade)
    {
        Name=name;
        Age= age;
        Gender= gender;
        ProgrammingGrade= programmingGrade;
    }
};

bool compareByGrade(const Student &s1, const Student &s2)
{
    return s1.ProgrammingGrade>s2.ProgrammingGrade;
}
int main()
{
    Student students[5] ={
        {"John", 20, 'M', 9},
        {"Bob", 21, 'M', 8},
        {"Alice", 20, 'M', 9.2},
        {"Eve", 23, 'F',8.5},
        {"Saldina", 22, 'F', 10}
    };

    //Searching
    for (int i = 0; i <=4; i++)
    {
        if(students[i].Name=="Alice")
        {
            cout<<"Alice found at index: "<<i<<endl;
            students[i].ProgrammingGrade=10;
            break;
        }
    }
    
    //Sorting
    sort(students, students+5, compareByGrade);

    for (int i = 0; i <=4; i++)
    {
        cout<<students[i].Name<<" is at position "<<i+1<<endl;

    }
    
}