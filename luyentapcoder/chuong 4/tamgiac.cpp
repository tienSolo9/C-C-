/*#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float a, b, c;
	cout << "nhap a: ";
	cin >> a;
	cout << "nhap b: ";
	cin >> b;
	cout << "nhap c: ";
	cin >> c;
	float tong1 = a * a + b * b;
	float tong2 = a * a + c * c;
	float tong3 = b * b + c * c;

	if ((a + b) < c || (a + c)< b || (b + c) < a)
	{
		cout << "khong ton tai tam giac";
	}
	else
	{
		if (a == b && a == c)
		{
			cout << "tam giac deu";
		}
		
		else if (abs(tong1 - c * c) < 1 || abs(tong2 - b * b) < 1 || abs(tong3 - a * a) < 1)
		{
			if (a == b || a == c || b == c)
			{
				cout << "tam giac vuong can";
			}
			else
			{
				cout << "tam giac vuong";
			}
		}
		else if (a == b || a == c || b == c)
		{
			cout << "tam giac can ";
		}
		else
		{
			cout << "tam giac thuong ";
		}
	}

}*/