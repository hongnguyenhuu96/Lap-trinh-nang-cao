/**
 * \file Bai3.cpp
 * \brief tim so lan xuat hien cua 1 xau con
 * \author Nguyen Huu Hong
 */

#include<iostream>
#include<cstring>

using namespace std;
int xuatHien(char a[], char search[]);
int main(){
	char a[100];
	cout << "Nhap xau: " << endl;
	cin.getline(a, 100);
	char search[100];
	cout << "Nhap xau con muon tim: " << endl;
	cin.getline(search, 100);
	cout << endl <<"So lan xuat hien la: " << xuatHien(a, search) << endl;
}

/**
* \brief tim so lan xuat hien cua 1 xau con
* \param a xau chinh
* \param search xau con
* \return so lan xuat hien
*/
int xuatHien(char a[], char search[]){
	int len = strlen(search);
	int count = 0, i = 0;
	do{
		if(strncmp(a + i , search, len) == 0) count++;
		i++;
	}while(i < strlen(a));
	return count;
}
