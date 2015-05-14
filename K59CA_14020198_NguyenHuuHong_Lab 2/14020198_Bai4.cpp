/** \file 14020198_Bai4
    \brief Liet ke tat ca cac day nhi phan co do dai k
    \author Nguyen Huu Hong
*/
#include<iostream>

using namespace std;
void nhiPhan(int *a, int n, int n1);

int main(){
	int *a, n;
	cout << "K = ";
	cin >> n;
	cout << endl;
	a = new int[n];
	nhiPhan(a, n , n - 1);
}
/** \brief In ra tat ca cac day nhi phan co do dai k
    \param a dong de luu gia tri 0 1 cho tung day nhi phan thoa man
    \param n do dai day nhi phan
    \param n1  = n - 1 la chi so chay de kiem tra su ket thuc va gan gia tri cho phan tu a[n1] qua moi lan goi lai ham nhi phan
*/
void nhiPhan(int *a, int n, int n1){
	for (int i = 0; i < 2; i++){
		a[n1] = i;
		if (n1 == 0){
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << endl;
		} else{
			nhiPhan(a, n, n1 - 1);
		}
	}
}
