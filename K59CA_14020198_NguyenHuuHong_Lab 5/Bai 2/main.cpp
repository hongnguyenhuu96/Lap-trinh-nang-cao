/** \file main.cpp (project Bai 2)
 * \brief xay dung lop SinhVien gon hoten, tuoi.
          xay dung lop danh sach lien ket : - chen 1 sinh vien
                                            - xoa 1 sinh vien
                                            - sap xep sinh vien theo tuoi
 * \author Nguyen Huu Hong - 14020198
 */




#include <iostream>
#include <linkList.h>
#include <Student.h>
using namespace std;

int main()
{
    linkList a;
    cin >> a; // nhap toan bo cac sinh vien cho danh sach
    cout << a;
    cout << "Them 1 sinh vien: " << endl;
    a.addOne();
    cout << a;
    cout << "Xoa 1 sinh vien: " << endl;
    a.deleteOne();
    cout << a;
    cout << "Sap xep sinh vien theo tuoi tang dan:" << endl;
    a.sort();
    cout << a;
}
