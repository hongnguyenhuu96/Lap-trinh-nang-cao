#include "Student.h"

Student::Student()
{
   data.name = "";
   data.age = 0;
   link = NULL;
}

Student::~Student()
{
    data.name = "";
    data.age = 0;
    link = NULL;
}
istream& operator >>(istream &is, Student &a){
    cout << "Name: ";
    is >> a.data.name;
    cout << "Age: ";
    is >> a.data.age;
    is.ignore(1000,'\n');
    return is;
}

ostream& operator << (ostream &os,const Student &a){
    os << setw(25) << (a.data).name << " : " << a.data.age << endl;
    return os;
}
