/** \file 1402098_Bai1.cpp
	\brief Tinh tich cua 2 ma tran m*n va n*k
	\author Nguyen Huu Hong
*/

#include<iostream>

using namespace std;

float** inPut (int m, int n, char p);
float** product(float **a, float **b, int m, int n, int k);
float** creatMatrix(int m, int n);
void outPut(float **a, int m, int n, char p);


int main(){
	int m, n ,k;
	cout << "m =";
	cin >> m;
	cout << "n =";
	cin >> n;
	cout << "k =";
	cin >> k;
	float **a, **b, **c;
	a = inPut (m, n, 'A');	
	b = inPut (n, k, 'B');
	c = product (a, b, m, n, k);
	outPut (c, m, k, 'C');
	return 0;
}
/** \brief Nhap du lieu vao ma tran
	\param m so hang
	\param n so cot
	\param p ten cua ma tran
	\return ma tran chua cac gia tri da nhap
*/
float** inPut (int m, int n, char p){
	float **a;
	a = creatMatrix(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++){
			cout << p << "["<< i << ", " << j << "] = ";
			cin >> a[i][j];
		}
		return a;
}
/** \brief Nhan 2 ma tran
	\param a ma tran ben trai
	\param b ma tran ben phai
	\param m so hang cua ma tran a
	\param n so cot cua ma tran a va cung la so hang cua ma tran b
	\param k so cot cua ma tran b
	\return ma tran tich cua a*b (ma tran nay co kich thuoc m * k)
*/
float** product(float **a, float **b, int m, int n, int k){
	float **c = creatMatrix(m, k);
	for (int i = 0; i < m; i++)
        for (int h = 0; h < k; h++)
        {
            c[i][h] = 0;
            for (int j = 0; j < n; j++)
                c[i][h] += a[i][j] * b[j][h];
        }
    return c;
}
/** \brief Tao mot ma tran
	\param m so hang cua ma tran can tao
	\param n so cot cua ma tran can tao
	\return ma tran tao ra
*/
float** creatMatrix(int m, int n){
	float **a = new float*[m];
	for (int i = 0; i < m; i++){
		a[i] = new float[n];
	}
	return a;
}
/** \brief In mot ma tran
    \param c ma tran can in ra
    \param m so hang cua ma tran can in
    \param n so cot cua ma tran can in
    \param p ten ma tran can in
*/
void outPut(float **c, int m, int n, char p){
	cout << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++){
			cout << p << "[" << i << ", " << j << "] = " << c[i][j]<< endl;
		}
}
