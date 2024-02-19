/*#include<iostream>
using namespace std;
int main()
{

	int x1, x2, x3, x4;
	cout << "nhap so tuong ung : ";
	cin >> x1 >> x2 >> x3 >> x4;

	cout << "ket qua 1 : ";
	int* p = NULL;
	int product = 1;
	for (p = &x1; p <= &x4;p += 8) {
		cout << *p << " ";
		product *= *p;
	}
	cout << "\nket qua 2 : " <<(float) product/4;


	
}*/