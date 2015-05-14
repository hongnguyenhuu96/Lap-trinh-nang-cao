#include<iostream>

using namespace std;

long long khongdequy(int k);
long long dequy(long long *a, int k);

int main(){
	int k;
	cout << "k = ";
	cin >> k;
	long long *a = new long long[k+1];
	for (int i = 0; i <= k; i++){
		a[i] = 0;
	}
	cout << "So thu " << k << " khong de quy = " << khongdequy(k) << endl;
	cout << "So thu " << k << " de quy = " << dequy(a, k) << endl;
	return 0;
}

long long dequy(long long *a, int k){
	a[0] = 0;
	a[1] = 1;
	if (k < 2) return a[k];
	if (a[k] > 0) return a[k];
	a[k] = dequy(a, k - 1) + dequy(a, k - 2);
	return a[k];
}

long long khongdequy(int k){
	if (k == 0) return 0;
    long long a = 1, b = 1;
    for (int i = 1; i < k; ++i) {
        b = a + b;
        a = b - a;
    }
    return a;
}
