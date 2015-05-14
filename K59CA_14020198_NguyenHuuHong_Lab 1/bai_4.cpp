#include <iostream>

float evaluate(float money, int m, int n);
using namespace std;
int main(){
	int n, m;
	float money;
	cout << " N thang = ";
	cin >> n;
	cout << " m ngay = ";
	cin >> m;
	cout << " Money = ";
	cin >> money;
	cout << "So tien ca von lan lai la = " << evaluate(money, n, m);
}

float evaluate(float money, int m, int n){
	n = n/30;
	m += n;
	for (int i = 0; i < m; i++){
		money = money + money * 0.07;
	}
	return money;
}
