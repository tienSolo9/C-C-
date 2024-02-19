/*#include<iostream>
using namespace std;
int main()
{
	int m, n;
	cout << "nhap m: "; cin >> m;
	cout << "nhap n: "; cin >> n;
	cout << "---------------------------\n";
	//1
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << "* ";
		}
		cout << "\n";
	}
	//2
	cout << "---------------------------\n";
	for (int i=1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == 1 || i == m) cout << "* ";
			else if (j == 1 || j == n) cout << "* ";
			else cout << "  ";
		}
		cout << "\n";
	}
	//3
	cout << "---------------------------\n";
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i % 2 == 0 && j % 2 == 0) cout << "  ";
			else cout << "* ";
		}
		cout << "\n";
	}
}*/