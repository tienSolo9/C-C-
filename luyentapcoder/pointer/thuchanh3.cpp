/*#include<iostream>
using namespace std;
int const length = 1000;
int last_index = 0;
void add(int b[], int x) {
	if (last_index > 14) {
		cout << "array is fulll!"; 
		return;
	}
	b[last_index] = x;
	last_index++;
}
void remove(int b[], int index) {
	if (index < 0 || index > 14) {
		cout << "out of array!";
		return;
	}
	for (int i = index; i < 14; i++) {
		b[i] = b[i + 1];
	}
	last_index--;
}
int main() {
	int a1[7] = { 5,9,12,3,7,11,2 };
	int a2[7] = { 8,2,0,7,13,6,9 };
	int b[length] = {};

	cout << "result 1 : ";
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (a1[i] == a2[j]) cout << a1[i] << " ";
		}
	}
	/////////////
	for (int i = 0; i < 7; i++) {
		add(b, a1[i]);
	}
	for (int i = 0; i < 7; i++) {
		add(b, a2[i]);
	}
	for (int i = 0; i < last_index; i++) {
		for (int j = i + 1; j < last_index; j++) {
			if (b[i] == b[j]) remove(b, i);
		}
	}

	for (int i = 0; i < last_index; i++) {
		for (int j = i+1; j < last_index; j++) {
			if (b[i] > b[j]) {
				int temp;
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}

	// ket qua 
	cout << endl << "result 2 : ";
	for (int i = 0; i < last_index; i++) {
		cout << b[i] << " ";
	}
	
}*/