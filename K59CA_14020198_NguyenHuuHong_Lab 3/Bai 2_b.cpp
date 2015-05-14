/**
 * \file Bai2_b.cpp
 * \brief dem so tu cua 1 xau
 * \author Nguyen Huu Hong
 */
#include<iostream>
#include<cstring>
using namespace std;

int demTu(string str);

int main(){
	string str;
	getline(cin, str);
	cout << "So tu la = " << demTu(str);
}
/**
	\brief dem so tu cua 1 xau
	\param str xau can dem so tu
	\return so tu cua xau dem duoc
*/
int demTu(string str){
	while(str[0] == ' ') str.erase(str.begin()); // neu bat dau bang dau cach thi xoa het dau cach di
	int len = str.length(), x, y, count = 1;// count = 1 do tinh den dau cach dau tien thi da duoc 1 tu nen
	for (int i = 0; i <= len - 1; i++){ // tim vi tri 2 dau cach lien nhau sau tu dau tien
		if(str[i] == ' '){
			x = i; // x la vi tri dau cach dau tien
			for(int j = i + 1; j <= len; j++){
				if(str[j] == ' ' || str[j] == '\0'){
					y = j; // y la vi tri dau cach hoac ky tu ket thuc xau dang sau x
					break;
				}
			}
			if(y - x > 1) { // neu x va y khong nam cach nhau tuc la co them 1 tu
				count++;
			}
		}
	}
	return count;
}
