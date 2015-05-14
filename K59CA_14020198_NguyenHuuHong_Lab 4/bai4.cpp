/** \file bai4.cpp
 *
 * \brief xay dung: - lop SinhVien:  ten, nam sinh, diem trung binh
 *                  - lop danhSach voi cac chuc nang:  + Nhap
                                                       + Hien thi
                                                       + Them, bot sinh vien trong danh sach
                                                       + Loc sinh vien theo khoang diem
                                                       + Sap xep sinh vien theo: ten, diem
 */
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>

using namespace std;
/** \brief class SinhVien
 * \param name: ten sinh vien
 * \param date: ngay sinh
 * \param month: thang sinh
 * \param year: nam sinh
 * \param mark: diem trung binh
 * \param next: tao danh sach lien ket
 */

class SinhVien{
private:
    string name;
    int date, month, year;
    float mark;
    SinhVien *next;
public:
    SinhVien(){ // ham constructor
        next = NULL;
    }
    int nhap(int i); // nhap du lieu cho 1 sinh vien
    void hienthi(); // hien thu du lieu 1 sinh vien
    void setNext(SinhVien *next1); // gan gia tri cho next
    SinhVien*& getNext(); //lay gia tri cua next
    string getName(); // lay gia tri cua name
    float getMark(); // lay gia tri cua mark
    void swap1(SinhVien *q); // dao gia tri cua sinh vien this va sinh vien *q
};
/** \brief nhap du lieu cho 1 sinh vien
 *
 * \param i: danh dau sinh vien thu i nhap vao hoac la them 1 sinh vien moi
 * \return 1: danh dau neu muon tiep tuc nhap them sinh vien
 * \return 0: danh dau ngung khong muon nhap them sinh vien nua
 */

int SinhVien::nhap(int i){
    if(i == -1)
        cout << endl << "Nhap sinh vien muon them:" << endl;
    else
        cout << "Nhap sinh vien " << i << ":" << endl;
    cout << "Ho ten (Bam enter de ket thuc nhap): ";
    fflush(stdin);
    getline(cin, name);
    if(name[0] == '\0') return 0;
    cout << "Ngay, thang, nam sinh: ";
    cin >> date >> month >> year;
    cout << "Diem trung binh: ";
    cin >> mark;
    next = NULL;
    return 1;
}
/** \brief hien thi thong tin cua 1 sinh vien
 */
void SinhVien::hienthi(){
    cout << endl << setw(20) << name << setw(10) << date << " " << month << " " << year << setw(20) << mark;
}
/** \brief gan gia tri cho next
 */
void SinhVien::setNext(SinhVien *next1){
    next = next1;
}
/** \brief lay next ra tu doi tuong SinhVien
 * \return next: contro next cua doi tuong
 */
SinhVien*& SinhVien::getNext(){
        return next;
}
/** \brief lay ten sinh vien
 * \return name: ten sinh vien
 */
string SinhVien::getName(){
    return name;
}
/** \brief lay diem sinh vien
 * \return mark: diem sinh vien
 */
float SinhVien::getMark(){
    return mark;
}

/** \brief doi cac gia tri cua 2 sinh vien
 * \param *q sinh vien can doi cac thuoc tinh voi this
 */
void SinhVien::swap1(SinhVien *q){
    string temp;
    int temp1;
    float temp2;
    // doi ten
    temp = this->name;
    this->name = q ->name;
    q->name = temp;
    //doi ngay thang nam sinh
    temp1 = this->date;
    this->date = q->date;
    q->date = temp1;
    temp1 = this->month;
    this->month = q->month;
    q->month = temp1;
    temp1 = this->year;
    this->year = q->year;
    q->year = temp1;
    // doi diem
    temp2 = this->mark;
    this->mark = q->mark;
    q->mark = temp2;
}

/** \brief class danhSach
 * \param head: con tro dau tien cua danh sach
 */

class danhSach{
private:
    SinhVien *head;
public:
    void nhapToanBo(); // nhap gia tri cho toan bo danh sach gom cac sinh vien
    void inToanBo(); // in toan bo sinh vien trong 1 doi tuong danh sach
    void timKiem(); // tim kiem 1 sinh vien trong danh sach
    void loc(); // loc cac sinh vien co diem tu a->b
    void them(); // them 1 sinh vien vao danh sach
    void xoa(); // xoa 1 sinh vien trong danh sach
    void xepTen(); // xap xep ten sinh vien theo bang chu cai
    void xepDiem(); // xep xep diem cua cac sinh vien
};

/** \brief nhap toan bo gia tri cua cac sinh vien vao trong danh sach
 */
void danhSach::nhapToanBo(){
    int i = 0;
    head = NULL;
    SinhVien *p, *q;
    while(1){
        q = new SinhVien;
        ++i;
        if(q->nhap(i) == 0){ // neu phuong thuc nhap tra ve 0 tuc la khong nhap tiep
            delete q;
            break;
        }
        if(head == NULL){
            head = p = q;
        }
        else{
            p->setNext(q);
            p = p->getNext();
        }
    }
}
/** \brief in toan bo sinh vien trong  1 danh sach
 */
void danhSach::inToanBo(){
    SinhVien *p = head;
    cout << endl << setw(20) << "Ho ten" << setw(17) << "Ngay sinh" << setw(20) << "Diem trung binh" << endl;
    while (p != NULL){
        p->hienthi();
        p = p->getNext();
    }
}
/** \brief tim kiem 1 sinh vien trong danh sach theo ten
 */

void danhSach::timKiem(){
    string temp;
    cout << endl << "Nhap ten sinh vien muon tim kiem: ";
    fflush(stdin);
    getline(cin, temp);
    SinhVien *p = head;
    int flag = 0;
    while(p != NULL){
        if(p->getName() == temp){
            p->hienthi();
            flag = 1;
        }
        p = p->getNext();
    }
    if (flag == 0) cout << "Khong tim thay sinh vien do";
}
/** \brief loc ra cac sinh vien co diem tu a -> b;
 */

void danhSach::loc(){
    SinhVien *p = head;
    float a, b;
    cout << endl << "Nhap khoang diem: a -> b:" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    int flag =0;
    while (p != NULL){
        if((p->getMark() >= a) && (p->getMark() <= b)){
            p->hienthi();
            flag = 1;
        }
        p = p->getNext();
    }
    if (flag == 0) cout << "Khong co sinh vien nao co diem thoa man!" << endl;
}
/** \brief them 1 sinh vien vao danh sach
 */
void danhSach::them(){
    SinhVien *q;
    q = new SinhVien;
    if(q->nhap(-1) == 0){
            delete q;
    }
    SinhVien *p = head;
    while(p->getNext() != NULL){
        p = p->getNext();
    }
    p->setNext(q);
    p = p->getNext();
}
/** \brief sap xep cac sinh vien theo ten
 */

void danhSach::xepTen(){
    SinhVien *p = head;
    while(p->getNext() != NULL){
        string minName = p ->getName();
        SinhVien *q1 = p->getNext();
        SinhVien *q2 = p->getNext();
        while(q1 != NULL){
            if(q1->getName() < minName){
            minName = q1->getName();
            }
            q1 = q1->getNext();
        }
        while (q2 != NULL){
            if(q2->getName() == minName){
                q2->swap1(p);
            }
            q2 = q2->getNext();
        }
        p = p->getNext();
    }
}
/** \brief sap xep cac sinh vien theo diem
 */
void danhSach::xepDiem(){
    SinhVien *p = head;
    while(p->getNext() != NULL){
        float minMark = p ->getMark();
        SinhVien *q1 = p->getNext();
        SinhVien *q2 = p->getNext();
        while(q1 != NULL){
            if(q1->getMark() < minMark){
            minMark = q1->getMark();
            }
            q1 = q1->getNext();
        }
        while (q2 != NULL){
            if(q2->getMark() == minMark){
                q2->swap1(p);
            }
            q2 = q2->getNext();
        }
        p = p->getNext();
    }
}
/** \brief xoa 1 sinh vien
 */

void danhSach::xoa(){
    string xoa;
    cout << endl << "Nhap ten sinh vien muon xoa: ";
    fflush(stdin);
    getline(cin, xoa);
    SinhVien *p, *pt;
    p = pt = head;
    if(p->getName() == xoa){
        head = head->getNext();
        delete p;
        cout << endl << "Xoa thanh cong";
        return;
    }
    p = p->getNext();
    while (p != NULL){
        if(p->getName() == xoa){
            pt->getNext() = p->getNext(); // deo biet loi gi o day
            delete p;
            cout << endl << "Xoa thanh cong";
            return;
        }
        p = p->getNext();
        pt = pt->getNext();
    }
    if(p == NULL) cout << "Khong tim thay sinh vien: " << xoa;
}
int main()
{
    danhSach a;
    cout << endl << "Nhap du lieu cho danh sach:" << endl;
    a.nhapToanBo();
    a.inToanBo();
    cout << endl << "Tim kiem sinh vien trong danh sach" << endl;
    a.timKiem();
    cout << endl << "Loc cac sinh vien co diem tu a -> b" << endl;
    a.loc();
    cout <<  endl << "Them 1 sinh vien vao danh sach" << endl;
    a.them();
    a.inToanBo();
    cout <<  endl << "Sap xep sinh vien theo ten" << endl;
    a.xepTen();
    a.inToanBo();
    cout << endl << "Sap xep Sinh vien theo diem so tu thap den cao" << endl;
    a.xepDiem();
    a.inToanBo();
    cout << endl << "Xoa 1 Sinh Vien" << endl;
    a.xoa();
    a.inToanBo();
    return 0;
}
