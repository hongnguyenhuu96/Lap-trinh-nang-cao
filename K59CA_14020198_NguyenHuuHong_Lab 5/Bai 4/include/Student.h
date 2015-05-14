#ifndef STUDENT_H
#define STUDENT_H
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        struct St{
            string name;
            int age;
        };
        St data; // cac gia tri cua 1 sinh vien
        Student *link; // link toi sinh vien tiep theo
    public:
        Student() {data.name = ""; data.age = 0; link = NULL;} // constructor khong doi
        virtual ~Student(); // destructor
        Student (const St &theData, Student* theLink): data(theData), link(theLink){} // constructor co doi
        Student*& getLink(){return link;} // lay link
        void setLink(Student* theLink){link = theLink;} // gan 1 link khac cho link cua this
        St getData(){return data;} // lay data
        string& name(){return data.name;} // lay ten
        friend istream& operator >> (istream& is, Student& a); // nhap gia tri cho 1 sinh vien
        friend ostream& operator << (ostream& os,const Student& a); // hien thi gia tri cua 1 sinh vien
        friend bool operator < (const Student &a, Student &b); // so sanh tuoi sinh vien a va b : operator <
};



#endif // STUDENT_H
