/*#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;

	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if (i > j) cout << "  ";
			else if (i + j <= 2 * n) cout << "0 ";
		}
		cout << "\n";
	}
	cout << "--------------------------------\n";

	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if (i > j || i + j > 2 * n) cout << "  ";
			else if (i == j || i == 1 || i + j == 2 * n) cout << "1 ";
			else cout << "0 ";
		}
		cout << "\n";
	}
	cout << "--------------------------------\n";

	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if (i > j || i + j > 2 * n) cout << "  ";
			else if (i == j || i + j == 2 * n) cout << "1 ";
			else if (i % 2 == 0 && j % 2 == 0 || i % 2 == 1 && j % 2 == 1) cout << "1 ";
			else cout << "0 ";
		}
		cout << "\n";
	}
	cout << "--------------------------------\n"; 
	int u = 0;
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if (i > j || i + j > 2*n) cout << "  ";	
			else if (i + j <= 20) cout << u << " ";
			
		}
		cout << "\n";
		u++;
	}
	cout << "--------------------------------\n";
	
	for (int i = n; i >= 1; i--)
	{
		int k = 0;
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if (i > j || j+i > 2*n) cout << "  ";
			else if (j < n)
			{
				cout << k << " ";
				k++;
			}
			else
			{
				cout << k << " ";
				k--;
			}
			
		}
		cout << endl;
		
	}
}*/
