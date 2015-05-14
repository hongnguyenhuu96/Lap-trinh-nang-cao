#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <iomanip>

using namespace std;
class Student
{
    private:
        struct St{
            string name;
            int age;
        };
        St data;
        Student *link;
    public:
        Student();
        Student (St theData, Student *theLink) : data(theData), link(theLink){}
        virtual ~Student();
        St getData(){return data;}
        Student*& getLink(){return link;}
        void setLink(Student *theLink){link = theLink;}
        void setData(St theData){data = theData;}
        string getName(){return data.name;}
        int getAge(){return data.age;}
        friend istream& operator >>(istream &is, Student &a);
        friend ostream& operator << (ostream &os,const Student &a);
    protected:
};

#endif // STUDENT_H
