/*#include <iostream>
using namespace std;

int const length = 10;
int last_index = 0;
void add(int a[], int x) {
	if (last_index > length) {
		cout << "array is full !";
		return;
	}
	a[last_index] = x;
	last_index++;
}
void remove(int a[], int index) {
	if (index > last_index || index < 0) {
		cout << " out of arange ";
		return;
	}
	for (int i = index; i <= last_index; i++)
	{
		a[i] = a[i + 1];
	}
	last_index--;
}


int main()
{
	int a[length];
	add(a, 1);
	add(a, 2);
	add(a, 5);
	add(a, 3);
	add(a, 4);

	
	for (int i = 0; i < last_index; i++) {
		if (a[i] % 2 == 0)
		{
			remove(a, i);
		}
		cout << a[i] << endl;
	}
}*/