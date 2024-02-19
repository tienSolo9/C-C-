#include<iostream>
using namespace std;
int main()
{
	int x = 29;
	int& r = x;

	r++;
	++r;

	cout << 1+r;
}