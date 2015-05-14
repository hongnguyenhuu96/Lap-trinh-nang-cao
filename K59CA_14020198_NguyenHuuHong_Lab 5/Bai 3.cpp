/**
 * \file Bai3.cpp
 * \brief xay dung ham template sap xep tong quat
 * \author Nguyen Huu Hong - 14020198
 */

#include <iostream>
#include <cstring>

using namespace std;

class BIGNUM{
private:
    char *a;// xau luu du lieu cua so BIGNUM
public:
    BIGNUM()
    {
        a = NULL;
    }
    BIGNUM(char *a1)
    {
    	a = strdup(a1);
    }
    ~BIGNUM()
    {
        delete a;
    }
    friend bool operator> (const BIGNUM& t1, const BIGNUM& t2);
    friend ostream& operator<< (ostream& os,const BIGNUM &p);
    BIGNUM& operator=(const BIGNUM &num);
    BIGNUM& operator=(const char *p);
};
/**
 * \brief operator > cua 2 so BIGNUM
 * \param t1: so thu nhat
 * \param t2: so thu hai
*/
bool operator> (const BIGNUM& t1, const BIGNUM& t2)
{
    string first = t1.a;
    string second = t2.a;
    while(first[0] == '0') first.erase(0 , 1);
    while(second[0] == '0') second.erase(0, 1);
    if(first.length() > second.length()) return true;
    else return false;
    if(first > second) return true;
    else return false;
}
/**
 * \brief operator = cua 2 so bignum
 * \param num: BIGNUM so de gan cho *this
*/
BIGNUM& BIGNUM :: operator= (const BIGNUM &num)
{
    a = strdup(num.a);
    return *this;
}

/**
 * \brief operator = gan gia tri cua 1 xau cho BIGNUM
 * \param p: xau gan gia tri cho BIGNUM
*/
BIGNUM& BIGNUM :: operator= (const char *p)
{
        a = strdup(p);
        return *this;
}
/**
 * \brief hien thi gia tri 1 so BIGNUM
 * \param os: dong output
 * \param p: so can hien thi gia tri
*/
ostream& operator<< (ostream& os,const BIGNUM &p){
    int len = strlen(p.a);
    for(int i = 0; i < len; i++)
    {
        cout << p.a[i];
    }
    return os;
}

/**
 * \brief ham template sap xep
 * \param num: ten mang can sap xep cac phan tu o trong
 * \param n: so phan tu cua mang
*/
template <class T>
void sort(T *num, int n){
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++){
            if(num[i] > num[j]){
                T temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
    }
}

/**
 * \brief ham template hien thi gia tri cua 1 mang
 * \param num: ten mang can hien thi gia tri cua cac phan tu
 * \param n: so phan tu cua mang num can hien thi tinh tu num[0]
*/
template <class T>
void output(T *num, int n)
{
    for(int i = 0; i < n ; i++){
        cout << num[i] << endl;
    }
}

int main()
{
    int a[5] = {1,6,5,6,2}; // gan gia tri cho 5 so kieu int
    BIGNUM num[5]; // gan gia tri cho 5 so BIGNUM
    num[0] = "567654321232132134646787945613215";
    num[1] = "126454646546513218786465";
    num[2] = "7746635456468787687846465";
    num[3] = "342113134654657897676546545113546546";
    num[4] = "6786544646546546548798787863";
    sort(a, 5);
    sort(num, 5);
    cout << "Sap xep so kieu int: " << endl;
	output(a, 5);
	cout << "Sap xep so kieu BIGNUM: " << endl;
    output(num, 5);
}
