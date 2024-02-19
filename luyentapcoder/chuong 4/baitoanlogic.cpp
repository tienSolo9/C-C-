#include<iostream>
using namespace std;
int main()
{
	int h1, h2, h3, h4, h5, h6;
	cout << "nhap vao ma hang can mua:";
	cin >> h1 >> h2 >> h3 >> h4 >> h5 >> h6;
	
	float t1 = 100, t2 = 150, t3 = 120, t4 = 90, t5 = 130, t6 = 140;
	float T = 0;
	


	if (h1 + h2 + h3 + h4 + h5 + h6 >= 4)
	{
		T = h1 * t1 + h2 * t2 + h3 * t3 + h4 * t4 + h5 * t5 + h6 * t6 -20;
	}


	
	cout << "so tien phai tra:" << T;
}