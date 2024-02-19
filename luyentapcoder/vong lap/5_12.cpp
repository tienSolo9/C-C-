/*#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << "\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (n - j < i) cout << "0 ";
			else cout << "  ";
		}
		cout << "\n";	
	}
	// cach 1
	cout << "----------------------------\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{

			if (i == n || j == n) cout << "1 ";
			else if (n - j < i - 1)	cout << "0 ";
			else if (n - j < i) cout << "1 ";
			else cout << "  ";
		}
		cout << "\n";
	}

	// cach 2
	cout << "----------------------------\n";
	for (int i = n; i > 0; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j || i == 1 || j == n) cout << "1 ";
			else if (j > i) cout << "0 ";
			else cout << "  ";
		}
		cout << "\n";
	}
} */