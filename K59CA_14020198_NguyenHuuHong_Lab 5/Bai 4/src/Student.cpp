#include "Student.h"
using namespace std;

/** \brief ham huy cua student
 */

inline Student::~Student()
{
    data.age = 0;
    data.name = "";
    link = NULL;
}
/** \brief toan tu >> nhap gia tri cho 1 student
 * \param is: dong nhap
 * \param a: Student can nhap gia tri
 * \return is: de nhap lien nhau >> >>
 */

inline istream& operator >> (istream& is, Student& a){
    cout << "Ten hoc sinh: ";
    getline(is, (a.data).name);
    cout << "Tuoi: ";
    is >> (a.data).age;
    cin.ignore(1000,'\n');
    return is;
}
/** \brief toan tu << xuat gia tri cho 1 student
 * \param os: dong xuat
 * \param a: Student can hien thi gia tri
 * \return os: de xuat gia tri lien tuc << <<
 */
inline ostream& operator<< (ostream& os,const Student& a)
{
    os << setw(25) << (a.data).name << " : " << (a.data).age;
    return os;
}
/** \brief operator < :so sanh 2 sinh vien dua tren yeu to so sanh la tuoi
 * \param a: sinh vien thu nhat
 * \param b: sinh vien thu 2
 * \return != 0 neu a < b
 * \return == 0 neu a khong < b
 */

inline bool operator < (const Student &a, Student &b)
{
    return ((a.data).age < (b.data).age);
}
