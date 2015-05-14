/**
 * \file Bai1_c.cpp
 * \brief tach cac tu cua mot xau ky tu rieng ra
 * \author Nguyen Huu Hong
 */
#include<iostream>
#include<cstring>

using namespace std;

struct TU{
	char word[50];
	TU *next;
};
TU* listWord(char a[], int len);

int main(){
	TU *p;
	char a[1000];
	cin.getline(a, 1000);
	int len =  strlen(a);
	p = listWord(a, len);
	while(p != NULL){
		cout << p->word << endl;
		p = p-> next;
	}
	return 0;
}

/**
 * \brief tach cac tu cua 1 xau rieng ra roi luu vao danh sach lien ket
 * \a xau can tach tu
 * \len so ky tu cua xau a
 * \return con tro dau tien cua danh sach lien ket cac tu
 */
TU* listWord(char a[], int len){
	TU *head = NULL, *p = NULL;
	char *b;
	int x, y; // x: danh dau vi tri 1 dau cach, y: danh dau vi tri dau cach tiep theo
	b = new char[len + 3];
	// dua b ve dang b = " a "
	b[0] = ' ';
	b[1] = '\0';
	strcat(b, a);
	b[len + 1] = ' ';
	b[len + 2] = '\0';
	int blen = strlen(b);
	// dem so tu
	for (int i = 0; i < blen - 1; i++){
		if (b[i] == ' '){
			x = i;
			for (int j = i + 1; j < blen; j++){
				if(b[j] == ' '){
					y = j;
					break;
				}
			}
			if(y - x > 1){ // luu tu vao danh sach lien ket
				if(head == NULL){
					head = new TU;
					p = head;
				}
				else{
					p->next = new TU;
					p = p->next;
				}
				strncpy(p->word, b + x + 1, y - x - 1);
				p->word[y - x - 1] = '\0';
				p->next = NULL;
			}
		}
	}
	return head;
}
