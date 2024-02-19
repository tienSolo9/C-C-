/*#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, m, k;
	int count = 0, sum = 0;
	cout << "enter the number n:";		
	cin >> n;
	int p = n;


	cout << "result 1:";
	while (n > 0)
	{
		int i= n % 10;
		cout << i;
		sum += i;
		n /= 10;
		count++;
	}
	cout << "\nresult 2:the number n has " << count<< " number";
	cout << "\nresult 3:" << sum;

	cout << "\nenter location want to get : ";
	cin >> m;
	if (m<=0 || m > count)
	{
		cout << "this location doesnt exist";
	}
	else
	{
		k =(int) (p / pow(10, count - m)) % 10;
		cout << "result 4 :" << k;
	}
}*/