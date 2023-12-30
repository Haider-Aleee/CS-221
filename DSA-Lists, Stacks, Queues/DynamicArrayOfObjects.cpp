#include <iostream>
using namespace std;

class Student
{
    public:
    string Name;
    int age;
    char Gender;
    float ProgrammingGrade;
};

void PrintStudents(Student* students, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<"STUDENT "<<i+1<<endl;
        cout<<students[i].Name<<"\t";
        cout<<students[i].age<<"\t";
        cout<<students[i].Gender<<"\t";
        cout<<students[i].ProgrammingGrade<<"\t";
    }
    
}
int main()
{
    int size;
    cout<<"Number of Students: ";
    cin>>size;

    Student* students= new Student[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"STUDENT "<<i+1<<endl;

        Student s;
        cout<<"Name: ";
        cin>>s.Name;
        cout<<"Age: ";
        cin>>s.age;
        cout<<"Gender: ";
        cin>>s.Gender;
        cout<<"Programming Grade: ";
        cin>>s.ProgrammingGrade;

        students[i]=s;
    }

    char choice;
    cout<<"Do you want a bigger array? (Y/N)"<<endl;
    cin>>choice;
    if (choice=='n' || choice=='N')
    {
        delete[]students;
        return 0;
    }
    int newSize;
    cout<<"Enter new size:\n";
    cin>>newSize;

    Student* newStudents= new Student[newSize];
    //memcpy(newStudents, students, sizeof(Student)*size);
    for (int i = 0; i < size; i++)
    {
        newStudents[i]= students[i];
    }
    delete[] students;
    students= newStudents;

     for (int i = size; i < newSize; i++)
    {
        cout<<"STUDENT "<<i+1<<endl;

        Student s;
        cout<<"Name: ";
        cin>>s.Name;
        cout<<"Age: ";
        cin>>s.age;
        cout<<"Gender: ";
        cin>>s.Gender;
        cout<<"Programming Grade: ";
        cin>>s.ProgrammingGrade;

        students[i]=s;
    }
    PrintStudents(students,newSize);


    delete [] students;
    return 0;
}