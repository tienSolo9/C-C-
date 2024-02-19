/*#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d, e, f;
	cout << "nhap vao ma mua: ";
	cin >> a >> b >> c >> d >> e >> f;
	

	float tien = 100 * a + 150 * b + 120 * c + 90 * d + 130 * e + 140 * f;
	bool t1 = a + b + c + d >= 4;
	bool t2 = f >= 2;
	bool t3 = tien > 500;

	if (t1 == 1 && t2 == 1 && t3 == 1)
	{
		tien = 0.8 * tien;
	}
	else if (t1 == 1 && t2 == 1)
	{
		tien = tien - 40;
	}
	else if ((t1 == 1 && t3 == 1) || (t2 == 1 && t3 == 1))
	{
		tien = 0.85 * tien;
	}
	else if (t3==1)
	{
		tien = 0.9 * tien;
	}
	else if (t2 == 1)
	{
		tien = tien - 30;
	}
	else if (t1 == 1)
	{
		tien = tien - 20;
	}
	cout << "so tien phai tra la " << tien;

}*/