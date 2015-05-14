/**
* \file Bai4.cpp
* \brief danh sach lien ket sinh vien
* \author Nguyen Huu Hong
*/
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;

struct STUDENT{
    string name;
    int mark;
    STUDENT *next;
};
STUDENT* nhapDanhSach();
void hienThi(STUDENT *head);
void sapXepTen(STUDENT *head);
void chuyenDoi(STUDENT *head, int i, int min1);
void sapXepDiem(STUDENT *head);
void diemAB(STUDENT *head);
void timSinhVien(STUDENT *head);

int main()
{
    STUDENT *head;
    head = nhapDanhSach();
    int x;

    do{
        cout << endl << "Hay chon cac chuc nang:\n1.Hien thi ra man hinh\n2.Sap xep theo ho ten\n3.sap xep theo diem\n4.Sinh vien co diem tu a -> b\n5.Tim sinh vien\n6.Exit" << endl;
        cin >> x;
        switch(x){
        case 1: hienThi(head); break;
        case 2: sapXepTen(head); hienThi(head); break;
        case 3: sapXepDiem(head); hienThi(head); break;
        case 4: diemAB(head); break;
        case 5: timSinhVien(head); break;
        case 6: break;
        default: cout << "Ban nhap sai roi, hay nhap lai:";
        }
    }while(x != 6);

}
/** \brief  Nhap danh sach tat ca cac sinh vien
 * \return con tro head dau tien cua danh sach sach lien ket
 */
STUDENT* nhapDanhSach(){
    STUDENT *head = NULL, *p = NULL;
    string name;
    int mark, i = 0;
    char c;
    while(1){
    	if(head == NULL){
    		head = new STUDENT;
    		p = head;
    	}
    	else{
    		p->next = new STUDENT;
    		p = p->next;
    	}
    	// ten
        cout << "Nhap ten sinh vien " << i + 1 << ": " << endl;
        fflush(stdin);
        getline(cin, name);
        p->name = name;
        // diem
        cout << "Diem la: " << endl;
        cin >> mark;
        p->mark = mark;
		p->next = NULL;
        i++;
        cout << "BAN CO MUON NHAP TIEP KO (y/ n)?" << endl;
        c = getch();
        if (c == 'n' || c == 'N') break;
    }
    system("cls");
    return head;
}
/** \brief hien thi danh sach sinh vien trong danh sach lien ket
 * \param head con tro dau tien cua danh sach lien ket
 */
void hienThi(STUDENT *head){
	system("cls");
    STUDENT *p;
    p = head;
    cout << setw(25) << "HO TEN" << setw(15) << "DIEM SO"<< endl << endl;
    while(p != NULL){
        cout << setw(25) << p->name << setw(15) << p->mark << endl;
        p = p->next;
    }
}

/** \brief Sap xep theo ten cac sinh vien trong danh sach lien ket
 * \param head con tro dau tien cua danh sach lien ket
 */
void sapXepTen(STUDENT *head){
    STUDENT *p;
    p = head;
    int i = 0, j, min1;
    while(p != NULL){
        min1 = i;
        j = i + 1;
        STUDENT *p1 = p->next;
        while(p1 != NULL){
            if (p1->name < p->name){
                min1 = j;
                chuyenDoi(head, i, min1);
            }
            p1 = p1 -> next;
           j++;
        }
        p = p->next;
        i++;
    }
    cout << "Da sap xep xong!" << endl;
}

/** \brief Chuyen doi cac gia tri thuoc tinh cua 2 sinh vien trong danh sach lien ket
 * \param head con tro dau tien cua danh sach lien ket
 * \param i sinh vien thu i trong danh sach lien ket tinh bat dau tu head
 * \param min1 sinh vien thu min1 trong danh sach lien ket tinh bat dau tu head
 */
void chuyenDoi(STUDENT *head, int i, int min1){
    STUDENT *temp1 = head, *temp2 = head, *temp = new STUDENT;
    int j = 0;
    while(j < i){
        temp1 = temp1->next;
        j++;
    }
    j = 0;
    while(j < min1){
        temp2 = temp2->next;
        j++;
    }
    temp->name = temp1->name;
    temp->mark = temp1->mark;
    temp1->name = temp2 -> name;
    temp1->mark = temp2 -> mark;
    temp2->name = temp->name;
    temp2->mark = temp->mark;
}
/** \brief sap xep diem theo thu tu tu lon den be
 * \param head con tro dau tien cua danh sach lien ket
 */

void sapXepDiem(STUDENT *head){
    STUDENT *p;
    p = head;
    int i = 0, j, min1;
    while(p != NULL){
        min1 = i;
        j = i + 1;
        STUDENT *p1 = p->next;
        while(p1 != NULL){
            if (p1->mark > p->mark){
                min1 = j;
                chuyenDoi(head, i, min1);
            }
            p1 = p1 -> next;
           j++;
        }
        p = p->next;
        i++;
    }
    cout << "Da sap xep xong!" << endl;
}
/** \brief In ra cac sinh vien co diem >= a va <= b trong danh sach lien ket
 * \param head con tro dau tien cua danh sach lien ket
 */

void diemAB(STUDENT *head){
    STUDENT *p;
    p = head;
    int a, b;
    int flag = 0;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    system("cls");
    cout << setw(25) << "HO TEN" << setw(15) << "DIEM SO"<< endl << endl;
    while(p != NULL){
        if(p->mark <= b && p->mark >= a){
        	flag = 1;
            cout << setw(25) << p->name << setw(15) << p->mark << endl;
        }
        p = p->next;
    }
    if(flag == 0) cout << "Khong co sinh vien co diem thoa man";
}
/** \brief tim mot sinh vien co ten trong danh sach lien ket bang ten
 * \param head con tro dau tien cua danh sach lien ket
 */

void timSinhVien(STUDENT *head){
    string search1;
    STUDENT *p = head;
    cout << "Nhap ho va ten sinh vien ban muon tim: " << endl;
    bool flag = 0;
    fflush(stdin);
    getline(cin, search1);
    system("cls");
    cout << setw(25) << "HO TEN" << setw(15) << "DIEM SO"<< endl << endl;
    while(p != NULL){
        if(p->name == search1){
            cout << setw(25) << p->name << setw(15) << p->mark << endl;
            flag = 1;
        }
        p = p->next;
    }
    if (flag == 0) cout << "Khong tim thay sinh vien " << search1 << "!" << endl;
}
