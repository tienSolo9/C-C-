/*#include<iostream>
using namespace std;

int const length = 5;
int main()
{
	int a[length] = { 3,4,2,1,5 };
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			if (a[i] > a[j]) {
				int temp;
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	for (int x : a) cout << x << endl;
}*/