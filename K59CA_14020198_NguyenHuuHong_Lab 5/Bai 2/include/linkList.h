#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
#include <iomanip>
#include <Student.h>

using namespace std;
class linkList
{
    public:
        linkList(); // constructor
        virtual ~linkList(); // destructor
        void addOne(); // them 1 sinh vien
        friend ostream& operator << (ostream& os, const linkList &a); // xem toan bo danh sach
        friend istream& operator >> (istream &is, linkList &a); // nhap toan bo danh sach
        void deleteOne(); // xoa 1 sinh vien
        void sort(); // sap xep sinh vien
    protected:
    private:
        Student *front, *back;
        Student* merge(Student *head1, Student *head2);
        Student* mergeSort(Student *head1, int n);

};

#endif // LINKLIST_H
