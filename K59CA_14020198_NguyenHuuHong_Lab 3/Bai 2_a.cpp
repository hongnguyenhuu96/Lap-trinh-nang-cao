/**
 * \file Bai2_a.cpp
 * \brief chuan hoa xau nhap vao
 * \author Nguyen Huu Hong
 */
#include<iostream>
#include<cstring>
using namespace std;

void chuanHoa(string &str);

int main(){
	string str;
	getline(cin, str);
	chuanHoa(str);
	cout << endl << str;
}
/**
* \brief chuan hoa 1 xau, bo cac dau cach thua va viet hoa
* \param str xau ban dau muon tach tu
*/
void chuanHoa(string &str){
    string b;
	while(str[0] == ' ') str.erase(str.begin()); // neu xau nhap vao bat dau bang dau cach thi xoa het di
	str.insert(0, " "); // them 1 dau cach vao vi tri dau tien
	int len = str.length(), x, y;
	for (int i = 0; i <= len - 1; i++){ // tim vi tri 2 dau cach canh nhau, hoac dau cach va ket thuc xau
		if(str[i] == ' '){
			x = i; // vi tri dau cach dau tien
			for(int j = i + 1; j <= len; j++){
				if(str[j] == ' ' || str[j] == '\0'){ // tim vi tri 2 dau cach gan nhat canh nhau, hoac dau cach va ky tu ket thuc xau
					y = j;                              // vi o giua no la tu
					break;
				}
			}
			if(y - x > 1) { // x la vi tri dau cach dau tien, y la vi tri dau cach hoac ky tu ket thuc xau dang sau (o giua la tu)
                str[x + 1] -= 32; // chuyen chu cai sau dau cach thanh chu hoa
				b += str.substr(x + 1, y - x -1);
				b += " ";// them dau cach vao dang sau
			}
		}
	}
	str = b;
}

