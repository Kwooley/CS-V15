#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
    int     id;
    char    *name=nullptr;
};

int main()
{
    Student s1, s2;

    s1.id = 10;
    s1.name = new char [20];
    strcpy(s1.name, "John");
    cout << "S1 Id and name " << s1.id << "\t" << s1.name << endl;    

    s2 = s1;
    strcpy(s2.name, "Bill");
    cout << "S1 Id and name " << s1.id << "\t" << s1.name << endl;    
    cout << "S2 Id and name " << s2.id << "\t" << s2.name << endl;    

    cout << "Memory address of S1.name " << &(s1.name) << endl;
    cout << "Memory address of S2.name " << &(s2.name) << endl;

}