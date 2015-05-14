/** \file 14020198_Bai3
    \brief Liet ke hoan vi cua mot day so nguyen cho truoc
    \author Nguyen Huu Hong
*/

#include<iostream>
#include<iomanip>
using namespace std;

void hoanVi(int *a, int *b, int *c, int n, int x);
int *inPut(int &n);
void in(int *b, int n);

int main(){
	int *a, *b, *c, n;
	// mang a de lay gia tri
	// mang b lay gia tri cua mang a va de in
	// mang c de danh giau
	a = inPut(n);
	b = new int[n];
	c = new int[n];
	for (int i = 0; i < n; i++){
		c[i] = 0; // khoi tao gia tri ban dau cho c == 0
	}
	system("cls");
	cout << "N = " << n << endl;
	hoanVi(a, b, c, n, 0);
}

/** \brief Nhap gia tri cho mot mang
    \param n so gia tri cua mang can nhap
    \return mang da nhap gia tri
*/
int* inPut(int &n){ // ham de nhap gia tri vao mang a
	int *a;
	cout << "N = ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	return a;
}
/** \brief Ham tao hoan vi cua n so
    \param a mang dong n phan tu chua cac gia tri can hoan vi ban dau
    \param b mang dong n phan tu chua cac gia tri da duoc hoan vi qua moi lan hoan vi
	\param n so phan tu cua a, b, c
	\param x chi so chay bat dau tu 0 -> n de truyen gia tri vao b
*/
void hoanVi(int *a, int *b, int *c, int n, int x){ // x la vi tri tinh tu ben trai sang, 
													//1 lan goi ham thi se truyen 1 gia tri cho b[x] 
													// ma gia tri nay chua duoc truyen vao truoc do
	for (int i = 0; i < n; i++){
		if(c[i] == 1) continue;// gap gia tri da truyen vao tu truoc roi thi bo qua
		
			b[x] = a[i]; // gap gia tri chua truyen tu truoc do thi cho vao b[x] thoi diem hien tai
			c[i] = 1;	// danh dau vi tri cua gia tri da duoc truyen vao b[x]
				
		if (x == n - 1){
			in(b, n);
		}
		else{
			hoanVi(a, b, c, n, x + 1);
		}
		c[i] = 0; // ket thuc 1 dequy thi cho gia tri da truyen thanh chua truyen de su dung cho cac gia tri dang sau voi x lon hon
	}				// vi ket thuc vong lap for i se tang len va b[x] lay gia tri khac nen gia tri hien thoi duoc su dung cho cac vi tri dang sau
}

/** \brief ham de in mot mang dong
    \param b ten mang dong
	\param n so phan tu cua b
*/
void in(int *b, int n){ // ham de in gia tri cua mang b trong 1 truong hop hoan vi
	for (int i = 0; i < n; i++){
		cout << setw(3) << b[i] << " ";
	}
	cout << endl;
}
