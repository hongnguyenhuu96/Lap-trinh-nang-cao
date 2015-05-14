#include<iostream>


using namespace std;

int main(){
	int *a, i, j, n, count = 0;
	cout << "Nhap so gia tri muon kiem tra" << endl;	
	cin >> n;

	a = new int[n];
	for (i = 0; i < n; i++){
		do{
			cin >> a[i];
			if (a[i] == 0) cout << "Ban da nhap sai, hay nhap lai gia tri nay:" << endl;
		}while(a[i] == 0);
	}
	
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++){
			if (a[j] % a[i] == 0 || a[i] % a[j] == 0){
				count ++;
			}
		}
	cout << count;
	return 0;
}
