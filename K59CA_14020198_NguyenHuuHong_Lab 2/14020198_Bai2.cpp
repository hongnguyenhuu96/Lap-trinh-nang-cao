/** \file 14020198_Bai2
    \brief Tinh gia tri uoc chung lon nhat cua N so nguyen duong
    \author Nguyen Huu Hong
*/

#include<iostream>

using namespace std;
int uclnN(int a[], int n);
int ucln2(int a, int b);
void inPut(int a[], int n);

int main(){
	int n, *a;
	cout << "n = ";
	cin >> n;
	a = new int[n];
	inPut (a, n);
	cout << endl << "Uoc chung lon nhat la: " << uclnN(a, n);
	delete []a;
	return 0;
}

/** \brief Nhap gia tri cho mang dong a
    \param n so phan tu
*/
void inPut(int a[], int n){
	cout << endl << "Nhap n so:" << endl;
	for (int i = 0; i < n; i++){
		do{
			cin >> a[i];
		} while (a[i] < 0);
	}
}
/** \brief Tinh uoc chung lon nhat cua n so
    \param a mang dong luu gia tri cua n so
    \param n so phan tu
    \return gia tri uoc chung lon nhat cua n so
*/
int uclnN(int a[], int n){
	int x = ucln2(a[0], a[1]);
	for (int i = 2; i < n; i++){
		x =  ucln2(x, a[i]);
	}
	return x;
}
/** \brief Tinh uoc chung lon nhat cua 2 so
    \param a so thu nhat
    \param b so thu 2
    \return gia tri uoc chung lon nhat cua  a va b
*/
int ucln2(int a, int b){
	int c;
	 while((c = (a % b)) != 0){
        a = b;
        b = c;
    }
	return b;
}
