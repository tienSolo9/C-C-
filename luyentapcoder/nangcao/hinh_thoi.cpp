/*#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << endl << endl;

	for (int i = n + 1; i >= 1; i--)
	{
		int k = n;
		int x = n-i+1;
		for (int a = 1; a < i; a++)
		{
			cout << " " << " ";
		}
		for (int b = 1; b <= 2 * x + 1; b++)
		{
			if (b + i <= n + 1)
			{
				cout << k << " ";
				k--;
			}
			else
			{
				cout << k << " ";
				k++;
			}
		}
		for (int c = 1; c < i ; c++)
		{
			cout << "  " ;
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
	{
		int k = n;
		int x = n-i+1;
		for (int a = 1; a <= i; a++)
		{
			cout << " " << " ";
		}	
		for (int b = 1; b <= 2 * (x - 1) + 1; b++)
		{
			if (b + i <= n )
			{
				cout << k << " ";
				k--;
			}
			else
			{
				cout << k << " ";
				k++;
			}
		}
		for (int c = 1; c <= i; c++)
		{
			cout << "  " ;
		}
		cout << endl;
	}
}*/