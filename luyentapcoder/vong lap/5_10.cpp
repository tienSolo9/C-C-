/*#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cout << " nhap n = ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << j << " ";
			}
		}
		else
		{
			for (int j = n; j > 0; j--)
			{
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	// hinh 2: 
	cout << "--------------------------\n";
	for (int i = 1; i <= n; i++)
	{
		
		for ( int j=1; j<=n;j++)
		{
			if (j == 1 || j == n) cout << "1 ";
			else if (i == 1 || i == n)  cout << "1 ";
			else cout << "0 ";
			
		}
		cout << "\n";
	}
	// hinh 3
	cout << "--------------------------\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) cout << "0 ";
			else cout << "1 ";
		}
		cout << "\n";
	}
	// hinh 4
	cout << "--------------------------\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j || i+j==(n+1)) cout << "0 ";
			else cout << "1 ";
		}
		cout << "\n";
	}
	// hinh 5
	cout << "--------------------------\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i % 2 == 1 && j % 2 == 1) cout << "0 ";
			else if (j % 2 == 0 && i %2  == 0) cout << "0 ";
			else cout << "1 ";
		}
		cout << "\n";
	}
	// hinh 6
	cout << "--------------------------\n";
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << abs(i - j) << " ";
		
		}
		cout << "\n";
	}
}*/