/*#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int  n, a = 0, b = 0;
	long long s7 = 0, s8 = 0;
	float s1 = 0, s2 = 1, s3 = 0, s4 = 0, s5 = 0, s6 = 0;
	cin >> n;
	if (n < 1)
	{
		s2 = 0;
	}
	else
	{
		for (int i = 1; i <= n; i++)	
		{
			s1 += i;
			s2 *= i;

			if (i % 2 == 1)
			{
				s3 += i;
			}
			s4 += i * i * i;
			s5 += (float)i / pow(i, i);
			s6 += i * (i + 1);

			a = a * 10 + 1;
			s7 += a;

			b = b + i;
			s8 += b;

		}
	}
		cout << "P = " << s1 << "\n";
		cout << "Q = " << s2 << "\n";
		cout << "R = " << s3 << "\n";
		cout << "S = " << s4 << "\n";
		cout << "T = " << s5 << "\n";
		cout << "U = " << s6 << "\n";
		cout << "v = " << s7 << "\n";
		cout << "X = " << s8 << "\n";
}*/