/*#include<iostream>
using namespace std;

const int length = 1000;
int last_index = 0;
void add(int a[], int x) {
	if (last_index > length) {
		cout << "array is full!";
		return;						// return ket thuc chuong trinh
	}
	a[last_index] = x;
	last_index++;
}
void insert(int a[], int index, int x) {
	if (last_index > length) {
		cout << "array is full!";
		return;
	}
	if (index<0 || index > last_index) {
		cout << "out of range!";	// ngoai pham vi
		return;
	}
	for (int i = last_index; i >= index; i--) {
		a[i + 1] = a[i];
	}
	a[index] = x;
	last_index++;
}
void remove(int a[], int index) {
	if (index<0 || index > last_index) {
		cout << "out of range!";	// ngoai pham vi
		return;
	}
	for (int i = index; i <= last_index; i++) {
		a[i] = a[i + 1];
	}
	last_index--;
}


int main()
{
	int a[length];
	
	add(a, 5);
	add(a, 10);
	add(a, 15);
	add(a, 20);
	insert(a, 1, 100);
	remove(a, 2);
	for (int i = 0; i < last_index; i++) cout << a[i] << endl;
}*/