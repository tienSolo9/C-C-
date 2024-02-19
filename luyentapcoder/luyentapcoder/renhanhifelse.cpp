/*#include<iostream>
using namespace std;
int main()
{
	float x, y, z;
	cin >> x;
	cin >> y;
	cin >> z;
	float max = (x > y) ? x : y;
	max = (max > z) ? max : z;
	
	float min = (x < y) ? x : y;
	min = (min < z) ? min : z;

	cout << "max la " << max;
	cout << "\nmin la " << min;

	if (x > 0 && y > 0 && z > 0)
	{
		cout << "\n3 so cung dau";
		cout << "\nkhong co cap trai dau nao.";
	}
	else
	{
		cout << "\n3 so khac dau";
		cout << "\ncac cap trai dau la:";
		if (x * y < 0)
		{
			cout << "(" << x << "," << y << ") ";
		}
		if (x * z < 0)
		{
			cout << "(" << x << "," << z << ") ";
		}
		if (y * z < 0)
		{
			cout << "(" << y << "," << z << ")";
		}
	}

}
*/