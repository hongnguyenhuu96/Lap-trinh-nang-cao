#include "COMPLEX.h"

using namespace std;
/** \brief constructor khong co tham so
 */

COMPLEX::COMPLEX() // ham tao khong co tham so
{
    a = 0;
    b = 0;
}

/** \brief destructor
 */
COMPLEX::~COMPLEX() // ham huy
{
   a = 0;
   b = 0;
}

/** \brief copy constructor
 * \param other: gia tri de copy cho *this
 */
COMPLEX::COMPLEX(const COMPLEX& other)
{
    a = other.a;
    b = other.b;
}
/** \brief constructor co tham so
 * \param a1 :gan phan thuc cua so phuc = a1
 * \param b1: gan phan ao cua so phuc = b1
 */

COMPLEX::COMPLEX(float a1, float b1) // ham tao co tham so
{
    a = a1;
    b = b1;
}
/** \brief phep cong
 * \param other: so phuc khac de cong vao *this
 * \return c: ket qua phep cong
 */

COMPLEX COMPLEX:: operator + (const COMPLEX &other) // +
{
    COMPLEX c;
    c.a = a + other.a;
    c.b = b + other.b;
    return c;
}
/** \brief phep tru
 * \param other: can tinh *this - other
 * \return c: ket qua phep tru
 */

COMPLEX COMPLEX:: operator - (const COMPLEX &other) // -
{
    COMPLEX c;
    c.a = a - other.a;
    c.b = b - other.b;
    return c;
}
/** \brief tinh modun cua so phuc, de su dung trong phep toan so sanh 2 modun
 */

float COMPLEX:: modun()
{
    return sqrt(a*a + b*b);
}
/** \brief operator >
 * \param other: so sanh trong phep toan > voi *this
 * \return != 0: neu modun cua *this > modun cua other
 * \return 0: neu modun cua *this >= modun cua other
 */

int COMPLEX::operator > (COMPLEX &other) // >
{
    return (this->modun() > other.modun());
}
/** \brief operator <
 * \param other: so sanh trong phep toan < voi *this
 * \return != 0: neu modun cua *this < modun cua other
 * \return 0: neu modun cua *this >= modun cua other
 */
int COMPLEX::operator < (COMPLEX &other) // <
{
    return (this->modun() < other.modun());
}

/** \brief operator ==
 * \param other: so sanh trong phep toan = voi *this
 * \return != 0: neu modun cua *this == modun cua other
 * \return 0: neu modun cua *this != modun cua other
 */
int COMPLEX::operator == (COMPLEX &other) // ==
{
    return (this->modun() == other.modun());
}
/** \brief operator >=
 * \param other: so sanh trong phep toan >= voi *this
 * \return != 0: neu modun cua *this >= modun cua other
 * \return 0: neu modun cua *this < modun cua other
 */
int COMPLEX::operator >= (COMPLEX &other) // >=
{
    return (this->modun() >= other.modun());
}
/** \brief operator <=
 * \param other: so sanh trong phep toan <= voi *this
 * \return != 0: neu modun cua *this <= modun cua other
 * \return 0: neu modun cua *this > modun cua other
 */
int COMPLEX::operator <= (COMPLEX &other) // <=
{
    return (this->modun() <= other.modun());
}
/** \brief operator !=
 * \param other: so sanh trong phep toan != voi *this
 * \return != 0: neu modun cua *this != modun cua other
 * \return 0: neu modun cua *this == modun cua other
 */
int COMPLEX::operator != (COMPLEX &other) // !=
{
    return (this->modun() != other.modun());
}

/** \brief operator =
 * \param rhs: gan *this = rhs
 * \return *this: de tiep tuc gan tiep (vi du a = b = c)
 */

COMPLEX& COMPLEX::operator=(const COMPLEX& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    this->a = rhs.a;
    this->b = rhs.b;
    return *this;
}

/** \brief hien thi gia tri cua 1 so phuc
 * \param os: dong output
 * \param a: so phuc can hien thi
 * \return os: de tiep tuc hien thi cai khac (vi du: << <<)
 */
ostream& operator<< (ostream& os,const COMPLEX &a)
{
    os << a.a;
    if(a.b >= 0) {
        os << " + ";
        os << a.b << "i";
    }
    else{
        os << " - ";
        os << -a.b << "i";
    }
}
/** \brief nhap gia tri cho 1 so phuc
 * \param is: dong input
 * \param a: so phuc can nhap gia tri vao
 * \return is: de tiep tuc nhap tiep (vi du: >> >>)
 */
istream& operator>> (istream& is, COMPLEX &a)
{
    cout << endl << "Phan thuc la: ";
    is >> a.a;
    cout << endl << "Phan ao la: ";
    is >> a.b;
}
