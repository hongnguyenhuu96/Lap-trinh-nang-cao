/**
 * \file Bai1_a.cpp
 * \bief chuan hoa mot ten
 * \author Nguyen Huu Hong
 */

#include<iostream>
#include<cstring>
using namespace std;
void chuanHoa(char a[], int len);

int main(){
	char a[100];
	cin.getline(a, 100);
	int len = strlen(a);
	chuanHoa(a, len);
	cout << endl << "Sau khi chuan hoa: " << endl << a;
	return 0;
}
/**
 * \brief chuan hoa mot ten, bo di cac dau cach thua, cac ky tu khong phai la chu va viet in hoa
 * \param a mang ky tu muon chuan hoa
 * \param len so ky tu cua mang ky tu
 */
void chuanHoa(char a[], int len){
	char b[100]; // mang de gan cac phan tu cua a vao sau do gan lai cho a
	int j = 0;
	strlwr(a); // viet thuong
	for(int i = 0; i < len ; i ++){
		if(isalpha(a[i]) != 0 /* && (isalpha(a[i + 1]) != 0 || a[i + 1] == '\0')*/){ // lay cac CHU trong truong hop: CHU -> chu hoac CHU -> '\0'
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

