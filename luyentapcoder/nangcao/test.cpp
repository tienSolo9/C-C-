/*#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "enter n : ";
	cin >> n;

	for (int i = 1; i <= n+1; i++) {
		int k = n;
		int q = n - i + 1;
		for (int a = 1; a < i; a++) {
			cout << k << " ";
			k--;
		}
		for (int b = 1; b <= 2 * q + 1; b++) {
			cout << q << " ";
		}
		for (int c = 1; c < i; c++) {
			k++;
			cout << k << " ";
			
		}
		cout << "\n";
	}

	for (int i = n; i > 0; i--) {
		int k = n;
		int q = n - i + 1;
		for (int a = 1; a < i; a++) {
			cout << k << " ";
			k--;
		}
		for (int b = 1; b <= 2 * q + 1; b++) {
			cout << q << " ";
		}

		for (int c = 1; c < i; c++) {
			k++;
			cout << k << " ";
		}
		cout << "\n";
	}

}*/