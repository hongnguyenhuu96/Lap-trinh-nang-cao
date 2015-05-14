#include<iostream>
#include<iomanip>

using namespace std;

int main(){
	int a;
	long int b;
	short c;
	float d;
	double e;
	char f;
	cin >> a >> b >> c >> d >> e >> f;
	cout << a << b << c << d << e << f << endl;
	char *s;
	s = new char[100];
	// nhap 1 tu
	cin >> s;
	cout << s << endl;
	// nhap ca xau;
	fflush(stdin);
	cin.getline(s, 100);
	cout << s << endl;
	
	return 0;
}
