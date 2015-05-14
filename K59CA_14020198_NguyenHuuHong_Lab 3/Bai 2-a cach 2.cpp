/**
* \file 2a.cpp
* \brief chuan hoa 1 tu
* \author Nguyen Huu Hong
*/
#include<iostream>
#include<cstring>
#include<ctype.h>
#include<string>
using namespace std;
void chuanHoa(string &str);

int main(){
	string str;
	getline(cin, str);
	chuanHoa(str);
	cout << str;
}

/**
	\brief chuan hoa 1 xau, xoa cac dau cach thua, chuyen doi chu thuong thanh chu hoa sau dau cach, tat ca cac chu con lai la chu thuong
	\param str tu can chuan hoa
*/
void chuanHoa(string &str){
	int i = 0;
	do{
		if(str[i] == ' ' && str[i + 1] == ' '){
			str.erase(str.begin() + i);
			i = 0;
		}
		i++;
	}while(i < str.length());
	int len = str.length();
	for (int i = 0; i < len; i++){ // chuyen chu hoa thanh chu thuong
		if (str[i] >= 65 && str[i] <= 90) str[i] += 32;
	}
	for (int i = 0; i < len; i++){
		if(str[i] == ' ' && isalpha(str[i + 1]) != 0){
			str[i + 1] -= 32; // chuyen chu thuong thanh chu hoa sau dau cach
		}
	}
	while(str[0] == ' ') str.erase(str.begin() + 0);
	if(str[0] >= 97 && str[0] <= 122) str[0] -= 32;
}
