/*#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cout << "enter n : ";
	cin >> n;
	int a[100] = {};
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
	int tong_chan = 0;
	int tong_le = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)  tong_chan += a[i];
		else  tong_le += a[i];
	}	
	int max = a[0];
	int min = a[0];
	int count1 = 0;
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > max) max = a[i];
		if (a[i] < min) {
			min = a[i];
			index = i;
		}
		if ((float)sqrt(a[i]) == (int)sqrt(a[i])) count1++;
	}
	cout << "result 1 : " <<(float) tong_chan /3 << endl;
	cout << "result 2 : " << (float) tong_le /2 << endl;
	cout << "result 3 : " << max << endl;
	cout << "result 4 : " << index << endl;
	cout << "result 5 : " << count1 << endl;
	cout << "result 6 : ";
	for (int i = 0; i < n; i++) {
		int count2 = 0;
		for (int j = 1; j <= 10; j++) {
			if (a[i] % j == 0) count2++;
		}
		if (count2 == 2) cout << a[i] << " ";
	}

	
	for (int i = 0; i < n; i++) {
		
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout << endl << "result 6 : ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	

}*/