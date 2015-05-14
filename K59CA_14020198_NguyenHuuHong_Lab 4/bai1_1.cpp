/**
 * \file bai1_1.cpp
 * \brief Vi du ve lop Date (nhap, xuat, tinh toan (neu co), constructor)
 * \author Nguyen Huu Hong
 */

#include <iostream>
#include <cmath>
#define YEAR 1800

using namespace std;

/** \brief kiem tra xem co phai nam nhuan khong
 * \param nam: nam can kiem tra co phai nam nhuan khong
 * \return true: neu la nam nhuan
 * \return false: neu khong la nam nhuan
 */
bool namNhuan(int nam){
    if((nam % 4 == 0 && nam %100 != 0) || nam % 400 == 0)
        return true;
    else
        return false;
}

/** \brief tinh so ngay ke tu ngay dau tien cua nam YEAR den ngay hien tai
 * \param ngay: ngay hien tai can tinh
 * \param thang: thang hien tai can tinh
 * \param nam: nam hien tai can tinh
 * \return tongNgay: so ngay tinh duoc
 */
long tinhNgay(int ngay, int thang, int nam){
    long tongNgay = 0;
    int a[12] ={31, 28, 31, 30,31,30,31,31,30,31, 30, 31};
    for (int i = YEAR; i < nam ; i++){
        if (namNhuan(i) == true) tongNgay += 366;
        else tongNgay += 365;
    }
    if(namNhuan(nam) == true){
        for(int j = 1; j < thang; j++){
            if (j == 2){
                tongNgay += 29;
                continue;
            }
            else{
                tongNgay += a[j - 1];
            }
        }
    }
    else{
        for(int j = 1; j < thang; j++){
            tongNgay += a[j - 1];
        }
    }
    tongNgay += ngay;
    return tongNgay;
}
/**
 * \brief class DATE: doi tuong la 1 ngay trong 1 nam
 * \param ngay: ngay
 * \param thang: thang
 * \param nam: nam
 */
class DATE
{
private:
    int ngay, thang, nam;
public:
    void nhap(); // nhap gia tri cho doi tuong
    void xuat(); // hien thi gia tri cua doi tuong
    int sosanh(DATE x); // tinh khoang cach giua 2 ngay
    DATE(int a = 0, int b = 0, int c = 0){ // ham constructor
        ngay = a;
        thang = b;
        nam = c;
    }
};
/** \brief nhap ngay thang nam cho doi tuong
 */
void DATE::nhap(){
    cout << "Nhap ngay, thang, nam: " << endl;
    cin >> ngay >> thang >> nam;
}

/** \brief hien ngay thang nam cho doi tuong
 */
void DATE::xuat(){
    cout << ngay << "/ " << thang << "/ " << nam;
}
/** \brief tinh khoang cach giua 2 ngay
 * \param x ngay2
 * \param *this ngay1
 * \return ngay1 - ngay2 = khoang cach giua 2 ngay(co dau + -)
 */
int DATE::sosanh(DATE x)
{
    long ngay2 = tinhNgay(x.ngay, x.thang, x.nam);
    long ngay1 = tinhNgay(ngay, thang, nam);
    return ngay1 - ngay2;
}

int main()
{
    DATE x, y(9,10,1996);
    x.nhap();
    int khoangCach = x.sosanh(y);
    x.xuat();
    if(khoangCach < 0)
        cout << " < ";
    else if (khoangCach > 0)
        cout << " > ";
    else cout << " = ";
    y.xuat();
    cout << endl << "Khoang cach giua 2 ngay la: " << abs(khoangCach) << endl;
    return 0;
}
