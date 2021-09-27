#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
    int     id;
    char    *name=nullptr;
};

void printStudent(Student);

int main()
{
    Student s1;

    s1.id = 10;
    s1.name = new char [20];
    strcpy(s1.name, "John");
    cout << "S1 Id and name " << s1.id << "\t" << s1.name << endl;    

    printStudent(s1);
    cout << "S1 Id and name " << s1.id << "\t" << s1.name << endl;    

}
void printStudent(Student s)
{
    cout << "Student's Id and name " << s.id << "\t" << s.name << endl;  
    delete [] s.name;  
}