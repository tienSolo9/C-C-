/*#include<iostream>
using namespace std;
int main()
{
	int const length = 100;
	int sum = 0; 
	int tong_chan = 0; int tong_le = 0; int tich = 1;
	int n; cout << "enter n: "; cin >> n;
	int a[length] = {};

	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	cout << "result 1 : " ;
	for (int i = n - 1; i >= 0; i--) {
		cout <<  a[i] << " ";
	}
	cout << endl;
	if(n>1)
	{
		sum = a[0] + a[n - 1];
		cout << "result 2 : " << sum << endl;

	}
	else
	{
		sum = a[0];
		cout << "result 2 : " << sum << endl;
	}
	int x = n / 2, z = n / 2 - 1;
	if (n % 2 == 0) cout << "result 3 : " << a[z] << " " << a[x] << endl;
	else cout << "result 3 : " << a[x] << endl;

	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 1) tong_le += a[i];
		else tong_chan += a[i];
	}
	tich = tong_chan * tong_le;
	cout << "result 4 : " << tich << endl;
}*/