#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	
	for (int i = n; i >= 1; i--)
	{
		int k = n;
		for (int j = 1; j <= 2*n-1; j++)
		{
			if (i > j || i + j >2*n) cout << "  ";
			else if(j<n)
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
		cout << endl;
	}
	for (int i = 1; i <= n - 1 ; i++)
	{
		int q = n;
		for (int j = 1; j <= 2 * n-1 ; j++)
		{
			if (j <= i || i + j > 2 * n-1) cout << "  ";
			else if (j < n)
			{
				cout << q << " ";
				q--;
			}
			else if(j==n)
			{
				--q;
				cout << q << " ";
			}

			
			else
			{
				cout << q << " ";
				q++;
			}
		}
		cout << endl;
	}
}