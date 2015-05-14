/** \file main.cpp (project bai 4)
 * \brief template tong quat cua bai 2 ve danh sach lien ket, vi du ap dung cho lop sinh vien
 * \return author Nguyen Huu Hong - 14020198
 */

#include <Student.h>
#include <DSLK.h>
#include "src\DSLK.cpp"
#include "src\Student.cpp"

using namespace std;

int main()
{
    DSLK<Student> a;
    cin >> a;
    cout << a;
    cout << endl << "Them 1 Sinh Vien" << endl;
    a.addOne();
    cout << a;
    a.deleteOne();
    cout << a;
    cout << "Sap xep theo tuoi: " << endl;
    a.sort();
    cout << a;
}
