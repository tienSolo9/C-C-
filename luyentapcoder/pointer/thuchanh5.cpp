/*#include<iostream>
using namespace std;
int const M = 2;
int const N = 3;
int const P = 2;
int last_index = M * N * P;
void remove(int array[], int index) {
	if (index < 0 || index > last_index) {
		cout << "out of array!";
		return;
	}
	for (int i = index; i < last_index; i++) {
			array[i] = array[i+1];
	}
	last_index--;
}

int main()
{
	int a[M][N][P] = {};
	int array[M * N * P] = {};

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < P; k++)
			{
				cout << " a[" << i << "][" << j << "][" << k << "] = ";
				cin >> a[i][j][k];
			}
		}
	}
	cout << "ket qua 1 : ";
	int l = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < P; k++)
			{
				array[l] = a[i][j][k];
				l++;
			}
		}
	}
	int temp ;
	for (int i = 0; i < last_index; i++) {
		for (int j = i + 1; j < last_index; j++) {
			if (array[i] == array[j]) remove(array, j);
			if (array[i] < array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	for (int i = 0; i < last_index; i++) {
		cout << array[i] << " ";
	}

	cout << "\nket qua 2 : \n";
	for (int i = 0; i < last_index; i++) {
		for (int j = i+1; j < last_index; j++) {
			if (array[i] % array[j] == 0) {
				cout << "(" << array[i] << "," << array[j] << ")\n";
			}
		}
	}
	cout << "\nket qua 3 : \n";
	for (int i = 0; i < last_index; i++) {
		for (int j = i + 1; j < last_index; j++) {
			for (int k = 0; k < last_index; k++) {
				if (array[i] + array[j] == array[k]) {
					cout << array[k] << " = " << array[i] << " + " << array[j] <<   "\n";
				}
			}
		}
	}
}*/