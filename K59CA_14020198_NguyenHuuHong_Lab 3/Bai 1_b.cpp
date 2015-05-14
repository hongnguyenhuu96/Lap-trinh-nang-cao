/**
 * \file Bai1_b. cpp
 * \brief dem so tu cua 1 xau
 * \author Nguyen Huu Hong
 */
#include<iostream>
#include<cstring>

using namespace std;
int demTu(char a[], int len);

int main(){
	char a[100];
	cin.getline(a, 100);
	int len = strlen(a);
	cout << endl << "So tu la: " << demTu(a, len);
	return 0;
}

/**
 * \brief dem so tu cua mot xau
 * \param a xau can dem so tu
 * \len so ky tu cua xau a
 * \return so tu cua mot xau
 */
int demTu(char a[], int len){
	char *b;
	int x, y, count = 0;
	b = new char[len + 3];
	// dua xau b ve dang = " a ";
	b[0] = ' ';
	b[1] = '\0';
	strcat(b, a);
	b[len + 1] = ' ';
	b[len + 2] = '\0';
	int blen = strlen(b);
	for (int i = 0; i < blen - 1; i++){
		if (b[i] == ' '){ // danh dau vi tri 1 dau cach
			x = i;
			for (int j = i + 1; j < blen; j++){
				if(b[j] == ' '){
					y = j; // danh dau vi tri dau cach tiep theo
					break;
				}
			}
			if(y - x > 1){ // chi tinh truong hop cac dau cach khong dung canh nhau thi tang so tu
				count++;
			}
		}
	}
	return count;
}
