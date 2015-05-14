/**
 * \file Bai2_c.cpp
 * \brief tra ve danh sach cac tu trong 1 xau nhap vao
 * \author Nguyen Huu Hong
 */

#include<iostream>
#include<cstring>
using namespace std;

struct WORD{
	string word;
	WORD *next;
};

WORD* danhSach(string str);
int main(){
	WORD *p;
	string str;
	getline(cin, str);
	p = danhSach(str);
	while(p != NULL){
		cout << p->word << endl;
		p = p-> next;
	}
}

/**
* \brief tach rieng biet cac tu trong 1 xau va luu vao danh sach lien ket
* \param str xau ban dau muon tach tu
* \return con tro dau tien cua danh sach lien ket chua cac tu da duoc tach ra tu xau
*/
WORD* danhSach(string str){
	WORD *p = NULL, *head = NULL;
	
	while(str[0] == ' ') str.erase(str.begin()); // neu xau nhap vao bat dau bang dau cach thi xoa het di
	str.insert(0, " "); // them 1 dau cach vao vi tri dau tien
	int len = str.length(), x, y;
	for (int i = 0; i <= len - 1; i++){
		if(str[i] == ' '){
			x = i;
			for(int j = i + 1; j <= len; j++){
				if(str[j] == ' ' || str[j] == '\0'){ // tim vi tri 2 dau cach gan nhat canh nhau, hoac dau cach va ky tu ket thuc xau
					y = j;                              // vi o giua no la tu
					break;
				}
			}
			if(y - x > 1) { // x la vi tri dau cach dau tien, y la vi tri dau cach hoac ky tu ket thuc xau dang sau (o giua la tu)
				if(head == NULL){
						head = new WORD;
						p = head;
				}
				else{
					p->next = new WORD;
					p = p->next;
				}
				p->word = str.substr(x + 1, y - x -1); // copy tu o giua x va y vao p->word
				p -> next = new WORD;
				p-> next = NULL;
			}
		}
	}
	return head; // tra lai con tro dau tien cua danh sach sach lien ket
}

