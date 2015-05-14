/**
 * \file bai1_2.cpp
 * \brief vi du ve lop BankAccount
 * \author Nguyen Huu Hong
 */
#include <iostream>
#include <cmath>

using namespace std;
/**
 * \brief BANK doi tuong tai tai khoan ngan hang
 * \param thang: so thang gui tien vao ngan hang
 * \param tien: so tien gui vao ngan hang
 * \param laisuat: lai xuat cua ngan hang
*/
class BANK{
private:
    int thang, tien, laisuat;
public:
    void nhap(); // nhap gia tri
    void xuat(); // hien thi
    int tienLai(); // tinh tien lai
    int tongSoTien(); // tinh tong so tien lay ve
    BANK(int tien1 = 0, int thang1 = 0, int laisuat1 = 0){ // ham constructor
        tien = tien1;
        laisuat = laisuat1;
        thang = thang1;
    }
};
/** \brief nhap du lieu cho doi tuong (so tien ban dau, so thang, va lai xuat(x%))
 */
void BANK::nhap(){
    cout << "Tien = ";
    cin >> tien;
    cout << "So thang = ";
    cin >> thang;
    cout << "Lai suat (x%)= ";
    cin >> laisuat;
}

/** \brief hien thi cac du lieu cua doi tuong
 */
void BANK::xuat(){
    cout << "Tien = " << tien << endl;
    cout << "Thang = " << thang << endl;
    cout << "Lai suat = " << laisuat << endl << endl;
}
/** \brief tinh tien lai thu duoc tu so tien va so thang gui ngan hang
 *\return tienlaithuduoc
 */

int BANK::tienLai(){
    return tien*thang*laisuat/100;
}
/** \brief tinh tong so tien lay ve
 * \return tong so tien lay ve
 */
int BANK::tongSoTien(){
    return (tien + tienLai());
}

int main()
{
    BANK y(100000,10,1);
    y.xuat();
    BANK x;
    x.nhap();
    x.xuat();
    cout << endl << "Tien lai la: " << x.tienLai();
    cout << endl << "Tong so tien lay ve la: " << x.tongSoTien();
    return 0;
}
