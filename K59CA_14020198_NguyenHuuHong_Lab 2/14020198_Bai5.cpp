/** \file 14020198_Bai5.cpp
    \brief Sap xep day so nguyen theo phuong phap tron (Merge Sort)
    \author Nguyen Huu Hong
*/
#include<iostream>

using namespace std;

int* inPut(int &n);
void mergeSort(int *a, int a1, int an);
void merge(int *a, int a11, int a12, int a21, int a22);

int main(){
	int *a, n;
	a = inPut(n);
	mergeSort(a, 0, n - 1);
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}
/** \brief Nhap gia tri cho ma tran
    \param n so phan tu cua ma tran
    \return ma tran da nhap so phan tu
*/
int* inPut(int &n){
	int *a;
	cout << "N = ";
	cin >> n;
	a =  new int[n];
	for(int i = 0; i < n; i++){
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	return a;
}
/** \brief Ham de sap sep tron theo thu tu tang dan
	\param a mang dong chua cac phan tu da nhap ban dau, khi sap xep xong luu lai gia tri o day
    \param a1 chi so dau tien cua mang a
    \param an chi so cuoi cung cua mang a
*/
void mergeSort(int *a, int a1, int an){
	if(an == a1){
		return;
	}
	else{
		mergeSort(a, a1, (a1 + an)/2);
		mergeSort(a, (a1 + an)/ 2 + 1 , an);
	}
	merge(a, a1, (a1 + an)/2, (a1 + an)/2 + 1, an );
	return;
}
/** \brief tron cac phan tu a[a11] -> a[12] voi a[21] -> a[22] lai va xep theo thu tu tang dan tu a[11] -> a[22]
	\param a mang dong chua cac phan tu da nhap ban dau, khi sap xep xong luu lai gia tri o day
    \param a11 chi so dau tien cua mang a[11] -> a[12]
    \param a12 chi so cuoi cung cua mang a[11] -> a[12]
    \param a21 chu so dau tien cua mang a[21] -> a[22]
    \param a22 chi so cuoi cung cua mang a[21] -> a[22]
*/
void merge(int *a, int a11, int a12, int a21, int a22){
	int b = a11, *p, n = a22 - a11 + 1, i = 0;
	p = new int[n];
	while (a11 <= a12 && a21 <= a22){
		if (a[a11] < a[a21]){
			p[i++] = a[a11++];
		} else{
			p[i++] = a[a21++];
		}
	}
	if (a12 - a11 >= 0){
		for (int j = a11; j <= a12; j++){
			p[i++] = a[j];
		}
	} else{
		for (int j = a21; j <= a22; j++){
			p[i++] = a[j];
		}
	}
	i = 0;
	for (int j = b; j <= a22; j++){
		a[j] = p[i++];
	}
}
