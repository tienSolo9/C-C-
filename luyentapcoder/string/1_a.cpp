/*#include<iostream>

int program_1(char x) {
	if ( x >= 65 && x <= 90) return 1;
	else if ( x >= 97 && x <= 122) return -1;
	else return 0;
}
int program_2(char x) {
	if (x >= 65 && x <= 90 || x >= 97 && x <= 122) return 1;
	else if ( x >= 48 && x <= 57) return -1;
	else return 0;
}
char  program_3(char x) {
	if (x >= 65 && x <= 90 || x >= 97 && x <= 122) return x+1;
	else if (x >= 48 && x <= 57) return x+1;
	else return x;
}

int main()
{
	char x;
	std::cout << "Nhap ki tu don: "; std::cin >> x;
	std::cout << "Ket qua 1: " << program_1(x) << "\n";
	std::cout << "Ket qua 2: " << program_2(x) << "\n";
	std::cout << "Ket qua 3: " << program_3(x) << "\n";
}*/