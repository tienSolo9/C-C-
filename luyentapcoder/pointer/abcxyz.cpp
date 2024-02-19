/*#include<iostream>
using namespace std;

void concat(int a[], int length_a, int b[], int length_b, int c[], int length_c) {
	for (int i = 0; i < length_a; i++) {
		c[i] = a[i];
	}
	int j = 0;
	for (int i = length_a; i < length_c; i++) {
		c[i] = b[j];
		j++;

	}
}

void split(int a[], int length_a, int b[], int length_b, int c[], int length_c,int index) {
	for(int i=0;i< index;i++){
		a[i] = c[i];
	}
	int j = 0;
	for (int i = index; i < length_c; i++) {
		b[j] = c[i];
		j++;
	}
}

int main()
{
	int const length_a = 3;
	int const length_b = 2;
	int const length_c = length_a + length_b;
	int a[length_a] = { };
	int b[length_b] = { };
	int c[length_c] = { 1,2,3,4,5};
	
	split(a, length_a, b, length_b, c, length_c,3);
	for(int x : b) cout << x << endl;
}*/