#ifndef DSLK_H
#define DSLK_H
#include <iostream>
#include <string>

using namespace std;

template<class T>
class DSLK
{
    public:
        DSLK();
        virtual ~DSLK();
        void addOne(); // them 1 node moi vao danh sach
        void addAll(); // them tat ca gia tri cac node cho danh sach
        void output(); // hien thi gia tri cua danh sach
        friend ostream& operator<< (ostream& os,const DSLK<T> &a){ // operator << hien thi gia tri cac Node cua 1 danh sach a
            T *current = a.front;
            while(current != NULL){
            os << *current << endl;
            current = current->getLink();
            }
            return os;
        }
        friend istream& operator>> (istream& is,DSLK<T> &a){ // nhap gia tri cho danh sach a su dung operator >>
            a.addAll();
            return is;
        }
        void deleteOne(); // xoa 1 node trong danh sach
        void sort(); // sap xep danh sach dua theo tuoi
    protected:
    private:
        T* mergeSort(T* head,int n); // ham xay dung de sap xep trong sort
        T* merge(T *head1, T *head2); // ham xay dung dung trong mergeSort
        T *front, *back; // front: con tro dau tien cua danh sach // back: con tro cuoi cung cua danh sach
};
#endif // DSLK_H
