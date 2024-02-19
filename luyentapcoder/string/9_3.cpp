/*#include<iostream>
#include<string>

using namespace std;

int program_1(string fullname,char x) {
	int i = fullname.find(x);
	int count = 0;
	while (i != string::npos) {
		count++;
		fullname = fullname.substr(i + 1);
		i = fullname.find(x);
	}
	return count;
}

int program_2(string fullname) {
	int i = fullname.find(" ");
	int count = 0;
	while (i != string::npos) {
		count++;
		fullname = fullname.substr(i + 1);
		i = fullname.find(" ");
	}
	count++;
	return count;
}

bool program_3(string s, string s1) {
	int i = s.find(s1);
	if (i == 0) return true;
	return false;
}

string program_4(string fullname) {
	int i = fullname.find(" ");
	fullname = fullname.substr(0, i);
	return fullname;
}

string program_5(string fullname) {
	int i = fullname.find(" ");
	while (i != string::npos) {
		fullname = fullname.substr(i + 1);
		i = fullname.find(" ");
	}
	return fullname;
}
int main()
{
	string fullname;
	cout << "nhap vao ten cua ban: ";
	getline(cin, fullname);

	cout << "ket qua 1 : " << program_1(fullname,'a') << "\n";
	cout << "ket qua 2 : " << program_2(fullname) << "\n";
	cout << "ket qua 3 : " << (program_3(fullname, "Pham") ? "True" : "False") << "\n";
	cout << "ket qua 4 : " << program_4(fullname) << "\n";
	cout << "ket qua 5 : " << program_5(fullname) << "\n";
}*/