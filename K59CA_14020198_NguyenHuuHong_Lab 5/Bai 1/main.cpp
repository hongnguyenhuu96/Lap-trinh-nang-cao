/**
 * \file main.cpp (project bai1)
 * \brief cac phep toan + - va so sanh tren so phuc
 * \author Nguyen Huu Hong - 14020198
 */

#include <COMPLEX.h>

using namespace std;

int main()
{
    COMPLEX a(3,4);
    COMPLEX b(5,-6);
    COMPLEX c = a + b;
    cout << c << endl;
    if(a > b) cout << a << " > " << b;
    else if(a < b) cout << a << " < " << b;
    else cout << a << " = " << b;
    if (a != b) cout << endl << a << " != " << b;
    a = b;
    if (a == b) cout << endl << a << " == "  << b;
}
