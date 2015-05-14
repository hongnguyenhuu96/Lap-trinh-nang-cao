/** \file bai2.cpp
 *
 * \brief xay dung lop so lon bao gom: - Ham constructor gan gia tri cho so do voi tham so la 1 xau
 *                                     - Ham hien thi gia tri cua so do ra man hinh
 *                                     - Cac toan tu + - *
 * \author Nguyen Huu Hong
 */
#include <iostream>
#include <cstring>
#include <iomanip>

#define CONG 1
#define TRU 0

using namespace std;

/** \brief them cac so 0 vao dang truoc 1 xau, sua khi chuyen co dang 00000068762
 * \param p: xau can them so 0 vao dang truoc
 * \param a: do dai xau sau khi them cac so 0
 * \return q: xau da duoc them so 0
 */
char* dichChuyen(char *p, int a){
	int len = strlen(p), i;
	char *q = new char[a + 1];
	for(i = 0; i < a - len; i++){
		q[i] = '0';
	}
	q[a - len] = '\0';
	strcat(q + i, p);
	return q;
}

/** \brief xet xem tinh cong hay tinh tru di nhau
 * \param p: chua so thu 1
 * \param q: chua so thu 2
 * \return CONG: neu 2 so cung dau
 * \return TRU: neu 2 so cung dau
 */
int xetDau(char *p, char *q){
	if(p[0] == '-'){
		if(q[0] == '-') return CONG;
		else return TRU;
	}else {
		if(q[0] == '-') return TRU;
		else return CONG;
	}
}
/** \brief class BIGNUM
 * \param p: bien char* de luu gia tri
 */
class BIGNUM{
private:
    char *p;

public:
    BIGNUM(){ // ham constructor khong doi
        p = NULL;
    }
    BIGNUM(char *x){ // ham constructor co doi
        int len = strlen(x);
        p = new char[len + 1];
        strcpy(p, x);
	}
    friend ostream& operator << (ostream& os,const BIGNUM &a); // toan tu in ra man hinh
    BIGNUM operator+ (BIGNUM x); // toan tu +
    BIGNUM operator- (BIGNUM x); // toan tu -
    BIGNUM operator* (BIGNUM x); // toan tu *
    BIGNUM& operator= (const BIGNUM& x); // toan tu =
    int soSanh (BIGNUM x); // ham so sanh 2 so BIGNUM tra ve 0 neu *this < x, 1 neu *this > x, 2 neu *this == x
    BIGNUM cong2SoDuong (BIGNUM x); //cong 2 so khongam BIGNUM
    BIGNUM tru2SoDuong (BIGNUM x); //tru 2 so khongam BIGNUM (tra ve gia tri tuyet doi cua hieu)
    void boSo0(); // bo cac so 0 du thua. Vidu 000001 chi con 1
    char* xoaDau(); // tinh gia tri tuyet doi cua so BIGNUM

};

/** \brief tra ve gia tri tuyet doi cua *this (xoa dau '-')
 * \return temp: gia tri tuyet doi cua *this
 */
char* BIGNUM::xoaDau(){
    char *temp;
    if(this->p[0] == '-') temp = this->p + 1;
    else temp = this ->p;
    return temp;
}

/** \brief bo cac so 0 du thua truoc cac so (vi du so -000001 = -1, 00000 = 0)
 */
void BIGNUM::boSo0(){
    int len = strlen(this->p);
    int flag = 0;
    if(p[0] == '-'){
        for (int i = 1; i < len; i++){
            if(p[i] != '0') flag = 1;
        }
    }
    else{
        for (int i = 0; i < len; i++){
            if(p[i] != '0') flag = 1;
        }
    }
    if(flag == 0){
        p[0] = '0';
        p[1] = '\0';
        return;
    }
    if(this->p[0] == '-'){
        int i = 1;
        while(p[i] == '0'){
            i++;
        }
        strncpy(p + 1, p + i, len - i);
        p[len - i + 1] = '\0';
    }
    else{
        int i = 0;
        while(p[i] == '0'){
            i++;
        }
        strncpy(p , p + i, len - i);
        p[len - i] = '\0';
    }
}

/** \brief toan tu << de hien ra so kieu BIGNUM
 * \param os: bien de tao dong in ra
 * \param a : so BIGNUM can hien thi
 * \return os
 */
ostream& operator << (ostream& os,const BIGNUM &a){
    int len = strlen(a.p);
    for (int i = 0; i < len; i++){
        os << a.p[i];
        if ((i + 1) % 3 == 0) os << " ";
    }
    os << endl;
    return os;
}

/** \brief chi dung de cong 2 so BIGNUM duong
 * \param x: so cong voi *this
 * \return result: tong cua 2 so
 */

BIGNUM BIGNUM::cong2SoDuong (BIGNUM x){
	BIGNUM result;
	int len1 = strlen(p);
	int len2 = strlen(x.p);
	int len = (len1 > len2 ? len1 : len2);
	// ham di chuyen bi loi
	if(len1 < len2) p = dichChuyen(p, len2);
	else x.p = dichChuyen(x.p, len1); // dua cac so ve dang 00004546546 cong cho no tien
	len += 1;
	result.p = new char[len + 1];
	result.p[len] = '\0';
	for(int i = 0; i < len; i++){
		result.p[i] = '0'; // tao mang de luu dap an cong
	}
	while(len > 1){ // cong
		len--;
		result.p[len] = result.p[len] + p[len - 1]  - '0' + x.p[len - 1] - '0';
		if(result.p[len] > '9'){
			result.p[len] -= 10;
			result.p[len - 1] += 1;
		}
	}
	return result;
}

/** \brief toan tu cong 2 so BIGNUM (tac dung binh thuong voi ca so am va duong)
 * \param x: so can cong voi *this (can tinh *this + x)
 * \return result: ket qua cua phep cong
 */
BIGNUM BIGNUM::operator+ (BIGNUM x){ // ta se tinh theo cac gia tri tuyet doi roi them dau sau
    static int i = 1;
    this->boSo0();
    x.boSo0();
	BIGNUM temp, x1, x2, result;

	if(xetDau(p, x.p) == CONG){ // cong gia tri tuyet doi neu 2 so cung dau
        x1.p = this->xoaDau();
        x2.p = x.xoaDau();

        temp = x1.cong2SoDuong(x2);

	}
	else{ // tru 2 so neu 2 so khac dau, phep tru o day cho gia tri tuet doi cua |ketqua|
        x1.p = this->xoaDau();
        x2.p = x.xoaDau();
        temp = x1.tru2SoDuong(x2);
	}

	temp.boSo0();

	int len = strlen(temp.p);
    result.p = new char[len + 2];//cap phat bo nho cho bien luu tru ket qua (do bien nay co tinh dau(+ -) nen len + 2)
//    result.p[len + 1] = '\0';
    // dau cua phep tinh se luon tinh theo dau cua so co gia tri tuyet doi lon hon
    if(x1.soSanh(x2) == 1){ // neu x1 > x2 lay dau theo x1
        if(this->p[0] == '-'){
            result.p[0] = '-';
            result.p[1] = '\0';
            strcat(result.p, temp.p);
        }
        else strcpy(result.p, temp.p);
    }
    else { // neu x1 <= x2 lay dau theo x2
       if(x.p[0] == '-'){
            result.p[0] = '-';
            result.p[1] = '\0';
            strcat(result.p, temp.p);
        }
        else strcpy(result.p, temp.p);
    }

    i ++;
    return result;
}

/** \brief toan tu tru 2 so (tac dung binh thuong voi ca so am va duong)
 * \param x: so de *this tru di (can tinh *this - x)
 * \return result: gia tri cua phep tru
 */
BIGNUM BIGNUM::operator- (BIGNUM x){
    BIGNUM result;
    BIGNUM temp;
    if(x.p[0] == '-'){
        temp.p = new char[strlen(x.p) + 1];
        strcpy(temp.p, x.p);
        temp.p = temp.xoaDau();
    }
    else {
        temp.p = new char[strlen(x.p) + 2];
        temp.p[0] = '-';
        temp.p[1] = '\0';
        strcat(temp.p, x.p);
    }
    result = *this + temp;
    return result;
}

/** \brief toan tu * dung de nhan 2 so (co tac dung binh thuong voi ca so am va so duong)
 * \param x: so de nhan voi *this (can tinh *this * x)
 * \return result: ket qua cua phep nhan
 */
BIGNUM BIGNUM::operator* (BIGNUM x){
    char dau1 = p[0];
    char dau2 = x.p[0];
    BIGNUM x1, x2, result;
    x1.p = this->xoaDau();
    x2.p = x.xoaDau();
    int len1 = strlen(x1.p);
    int len2 = strlen(x2.p);
    int len = len1 + len2;
    result.p = new char[len + 1];
    for(int i = 0; i < len; i++){
        result.p[i] = '0';
    }
    result.p[len] = '\0';
    for(int j = len2 - 1; j >=0; j--){
        BIGNUM temp;
        temp.p = new char[len + 1];
        for(int k = 0; k < len; k++){
                temp.p[k] = '0';
        }
        temp.p[len] = '\0';
        int a = len - (len2 - j);
        for(int i = len1 - 1; i >= 0; i--){
            temp.p[a - 1] += ((x2.p[j] - '0') * (x1.p[i] - '0') + temp.p[a] -'0') / 10;
            temp.p[a] += ((x2.p[j] - '0') * (x1.p[i] - '0')) % 10;
            if(temp.p[a] > '9'){
                temp.p[a - 1] +=  (temp.p[j] - '0') / 10;
                temp.p[a] = ((temp.p[a] - '0') % 10) + '0';
            }
             a--;
        }
        temp.boSo0();
        result = result + temp;
    }
    if((dau1 == '-' && dau2 != '-') ||( dau1 == '-' && dau2 != '-')){
        char x[len];
        x[0] = '-';
        x[1] = '\0';
        strcat(x, result.p);
        strcpy(result.p, x);
    }
    return result;
}

/** \brief so sanh 2 so BIGNUM khong am
 * \param x: so so sanh voi *this
 * \return 0: neu *this < x;
 * \return 1: neu *this > x;
 * \return 2: neu *this = x;
 */
int BIGNUM::soSanh(BIGNUM x){
    int len1 = strlen(this->p);
    int len2 = strlen(x.p);
    if(len1 > len2) return 1;
    else if(len1 < len2) return 0;
    else{
        int i = 0;
        while (i != len1){
            if(this->p[i] < x.p[i]) return 0;
            if (this->p[i] > x.p[i]) return 1;
            i++;
        }
    }
    return 2;
}

/** \brief ham de tinh gia tri tuyet doi cua hieu 2 so duong
 * \param x: so can tinh |*this - x|
 * \return result: gia tri tuyet doi cua hieu 2 so duong
 */
BIGNUM BIGNUM::tru2SoDuong(BIGNUM x){ //dung de tru 2 so, tra lai gia tri tuyet doi
    BIGNUM result;
    BIGNUM x1, x2; // x1 la so lon hon, x2 la so nho hon
    if(this->soSanh(x) == 1){
        x1.p = this->p;
        x2.p = x.p;
    }else{
        x1.p = x.p;
        x2.p = this->p;
    }
    int len = strlen(x1.p);
    x2.p = dichChuyen(x2.p, len);
    result.p = new char[len + 1];
    result.p[len] = '\0';
    for(int i = 0; i < len; i++){
		result.p[i] = '0'; // tao mang de luu dap an cong
	}
    while(len > 0){ // cong
        len--;
        result.p[len] += (x1.p[len] - x2.p[len] + 10) %10;
        if(x1.p[len] < x2.p[len]) result.p[len - 1] -= 1;
        if((result.p[len] < '0')){
            result.p[len] += 10;
            result.p[len - 1] -= 1;
        }
    }
	return result;
}


/** \brief xay dung toan tu = cho so BIGNUM
 * \param x: so BIGNUM de gan gia tri cho *this
 * \return *this
 */

BIGNUM& BIGNUM::operator= (const BIGNUM& x){
    int len = strlen(x.p);
    this->p = new char[len + 1];
    strcpy(this->p,x.p);
    return *this;
}


int main()
{
    BIGNUM a("-87264562875682743658259798572490546438750982374598");
    BIGNUM b("111111111146464646464689876495111111");
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    BIGNUM c = a + b + b;
    cout << c << endl;
}
