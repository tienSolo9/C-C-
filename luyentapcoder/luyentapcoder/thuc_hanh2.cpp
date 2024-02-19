/*#include<iostream>
using namespace std;
bool chan_le(int x) {
	if (x % 2 == 0) return true;
	else return false;
}
bool positive_negative(int x) {
	if (x >= 0) return true;
	else return false;
}
bool prime_number(int x) {
	int count = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) count++;
	}
	if (count == 2) return true;
	else return false;
}

int main()
{
	int x;
	std::cout << "Nhap x: ";
	std::cin >> x;
	std::cout << "Ket qua 1: " << (chan_le(x) ? "So chan" : "So le") << "\n";
	std::cout << "Ket qua 2: " << (positive_negative(x) ? "So duong" : "So am") << "\n";
	std::cout << "Ket qua 3: "
		<< (prime_number(x) ? "So nguyen to" : "Ko phai so nguyen to") << "\n";

}*/