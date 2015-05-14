/** \file bai3.cpp
 * \brief Xay dung lop MyString voi cac tinh nang:
            - Nhap du lieu vao
            - Xuat du lieu ra man hinh
            - Chuan hoa ten
            - Tach tu, tra ve danh sach tu
            - Gan xau
            - So sanh xau
            - Ghep xau
            - Dao nguoc xau
            - Gan gia tri moi
            (Luu du lieu duoi dang char*)
 * \author Nguyen Huu Hong
 */

#include <iostream>
#include <cstring>
#include <cstdio>

#define MAX 100

using namespace std;
/** \brief class MyString
 *
 * \param p: luu xau
 * \param next: tao danh sach lien ket
 */

class MyString{
private:
    char *p;
    MyString *next;
public:
    MyString(char *str){
        p = str;
    }
    MyString(){
        p = new char[MAX];
    }

    friend ostream& operator << (ostream& os,const MyString& a); // toan tu <<
    friend istream& operator >> (istream& is, MyString& a); // toan tu >>
    friend ostream& operator << (ostream& os,const MyString* a); // toan tu <<
    MyString& operator=(const MyString& a); // toan tu =
    MyString operator+ (MyString a); // toan tu +
    MyString* listWord(); // tac tu, tra ve danh sach cac tu
    void getstr(); // nhap gia tri cho xau co ca dau " "
    void chuanHoa(); // Chuan hoa ten
    void soSanh(MyString b); //So sanh xau
    void dao(); // dao xau
    MyString* getNext() {
        return next;
    }
//    MyString* getNext(){return next;}
};
/** \brief toan tu <<
 *
 * \param os: tao dong de in
 * \param a: 1 bien con tro MyString can in gia tri
 * \return os
 */

ostream& operator << (ostream& os,const MyString* a){
        os << a->p << endl;
    return os;
}
/** \brief toan tu <<
 *
 * \param os: tao dong de in
 * \param a: 1 bien MyString can in gia tri
 * \return os
 */
ostream& operator << (ostream& os,const MyString& a){
        os << a.p << endl;
    return os;
}

/** \brief toan tu =
 * \param a: bien de gan gia tri cho *this
 * \return *this
 */
MyString& MyString::operator=(const MyString& a){
    strcpy(p, a.p);
    return *this;
}

/** \brief toan tu >> (co tinh space)
 * \param is: tao dong nhap
 * \param a: bien de nhap gia tri vao
 * \return is
 */
istream& operator >> (istream& is, MyString& a){
    is >> a.p;
    return is;
}

/** \brief ham nhap xau cho MyString
 */
void MyString::getstr(){
    cin.getline(p, MAX);
}

/** \brief ham chuan hoa ten : Vi du:  nguyen Van    A -> Nguyen Van A
 */
void MyString::chuanHoa(){
    char* &a = this->p;
    int len = strlen(a);
    if(len == 0) return;
	char b[MAX]; // mang de gan cac phan tu cua a vao sau do gan lai cho a
	int j = 0;
	strlwr(a); // viet thuong
	for(int i = 0; i < len ; i ++){
		if(isalpha(a[i]) != 0 ){ // lay cac CHU trong truong hop: CHU -> chu hoac CHU -> '\0'
			 b[j++] = a[i];
		}
		if(isalpha(a[i]) != 0 && a[i + 1] == ' '){ //lay chu va dau cach trong truong hop chu -> ' ';
			b[j++] = ' '; // truong hop a = "adfsdf   " thi van bi them 1 dau cach o cuoi cung
		}
	}
	// dat ky tu ket thuc xau
	if(b[j - 1] ==' '){ // neu ky tu cuoi cung cua b la ' ' thi bien thanh '\0'
		b[j - 1] = '\0';
		j--;
	}else b[j] = '\0';
	// gan a = b va them ky tu ket thuc xau cho a
	for (int i = 0; i <= j ; i++){
		a[i] = b[i];
	}
	// viet in hoa cac ky tu cua dau 1 tu
	a[0] -= 32;
	for(int i = 0; i < j; i++){
		if(a[i] == ' ') a[i + 1] -= 32;
	}
}
/** \brief tach cac tu trong 1 xau ra rieng re va luu vao danh sach lien ket
 * \return head: con tro dau tien cua danh sach cac tu da tach duoc
 */

MyString* MyString::listWord(){
    int len = strlen(p);
    char* &a = p;
	MyString *head = NULL, *p1 = NULL;
	char *b;
	int x, y; // x: danh dau vi tri 1 dau cach, y: danh dau vi tri dau cach tiep theo
	b = new char[len + 3];
	// dua b ve dang b = " a "
	b[0] = ' ';
	b[1] = '\0';
	strcat(b, a);
	b[len + 1] = ' ';
	b[len + 2] = '\0';
	int blen = strlen(b);
	// dem so tu
	for (int i = 0; i < blen - 1; i++){
		if (b[i] == ' '){
			x = i;
			for (int j = i + 1; j < blen; j++){
				if(b[j] == ' '){
					y = j;
					break;
				}
			}
			if(y - x > 1){ // luu tu vao danh sach lien ket
				if(head == NULL){
					head = new MyString;
					p1 = head;
				}
				else{
					p1->next = new MyString;
					p1 = p1->next;
				}
				strncpy(p1->p, b + x + 1, y - x - 1);
				p1->p[y - x - 1] = '\0';
				p1->next = NULL;
			}
		}
	}
	return head;
}
/** \brief so sanh 2 xau voi nhau va hien thi luon ket qua
 * \param b: xau can so sanh voi *this
 */

void MyString::soSanh(MyString b){
    int a = strcmp(p, b.p);
    if(a == 0) cout << "Hai xau giong nhau" << endl;
    else if (a < 0) cout << p << " < " << b.p << endl;
    else cout << p << " > " << b.p << endl;
}

/** \brief noi 2 xau voi nhau
 * \param a: xau can noi vao sau *this
 * \return *this : xau da duoc noi them a
 */
MyString MyString:: operator+ (MyString a){
    strcat(p, a.p);
    return *this;
}
/** \brief dao nguoc vi tri cac ky tu trong xau
 */

void MyString::dao(){
    char temp;
    int len = strlen(p);
    for(int i = 0; i <= len/2 - 1; i++){
        temp = p[i];
        p[i] = p[len - 1 - i];
        p[len - 1 - i] = temp;
    }
}

int main()
{
    cout << "Nhap xuat thong thuong\nMoi ban nhap 1 tu:" << endl;
    MyString a;
    cin >> a;
    cout << a;
    cout << "Nhap 1 xau:" << endl;
    fflush(stdin);
    a.getstr();
    cout << "Chuan Hoa xau phia tren" << endl << endl;
    a.chuanHoa();
    cout << a;
    // liet ke danh sach cac tu
    MyString *b;
    b = a.listWord();
    cout << endl << "List Word:" << endl << endl;
    while(b != NULL){
        cout << b << endl;
        b = b->getNext();
    }
    cout << "Su dung Toan tu gan:" << endl << endl;
    MyString xau("nguyen van A"), xau2, xau3;
    xau3 = xau2 = xau;
    cout << xau3;
    cout << "So sanh:" << endl << endl;
    xau3.soSanh(xau2);
    xau3.soSanh(a);
    cout << "Ghep xau" << endl << endl;
    xau3 = (xau3 + xau2);
    cout << xau3;
    cout << endl << "Xau dao nguoc la: ";
    xau3.dao();
    cout << xau3;
}
