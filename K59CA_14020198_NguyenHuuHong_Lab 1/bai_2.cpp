#include <iostream>
#include <cstring>

int kiemtra(char s[], int a, int b); // kiem tra tu :tu vi tri dau cach a -> vi tri dau cach b

using namespace std;
int main(){
	char s[100];
	int i, j, k, lastSpace = -1;
	cin.getline(s, 100);
	int count = 0; // bien dem so tu dung
	int n = strlen(s);
	for (i = 0; i < n; i ++){
		if (s[i] == ' '){
			if (kiemtra(s, -1, i) == 1) count ++; // kiem tra tu dau tien : vi tri bat dau -> dau cach dau tien
			break;
		}
	}
	
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++){
			if (s[i] == ' ' && s[j] == ' '){
				if (kiemtra(s, i, j) == 1) count++; // kiem tra tu giua 2 dau cach lien nhau gan nhat (i -> j)
				break;
			}
		}
	for (i = 0; i < n; i++){
		if(s[i] == ' ') lastSpace = i; // tim vi tri dau cach cuoi cung
	}
	if (kiemtra(s, lastSpace, n) == 1) count ++; //kiem tra tu dau cach cuoi cung -> het || neu xau khong co dau cach nao kiem toan bo xau(do lastSpace = -1)
	
	cout << "So tu dung la: " << count << endl;
	return 0;
}

int kiemtra(char s[], int a, int b){
	int i, flag = 1;
	if (b == a + 1) return 0;
	for (i = a + 1; i < b ; i++){
		if (!((s[i] >= 97 && s[i] <= 122)||(s[i] >= 65 && s[i] <= 90))){ // xet dieu kien phai la cac chu cai
			flag = 0;
		}
	}
	return flag;
}
