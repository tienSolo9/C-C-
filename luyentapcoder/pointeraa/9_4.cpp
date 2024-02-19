#include<iostream>
#include<string>

using namespace std;

bool program_1(string s) {
	bool check = true;
	int i = s.find(" ");
	
	while (i != string::npos) {
		if (i == 0) return check = false;
		for (int j = 1; j < i; j++) {
			if (s[0] >= 'A' && s[0] <= 'Z' && s[j] >= 'a' && s[j] <= 'z') continue;
			else return check = false;
		}
		s = s.substr(i + 1);
		i = s.find(" ");
	}
	for (int j = 1; j < s.length(); j++) {
		if (s[0] >= 'A' && s[0] <= 'Z' && s[j] >= 'a' && s[j] <= 'z') continue;
		else return check = false;
	}
	return check;
}

string program_2(string s) {
	int length = s.length();
	for (int i = length - 1; i >= 0; i--) {
		if ((s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') || s[i] == ' ') {
			continue;
		}
		else {
			for (int j = i; j < length; j++) {
				s[j] = s[j + 1];
			}
			length--;
		}
	}
	
	string s1;
	for (int i = 0; i < length; i++) {
		 s1 += s[i];
	}
	//xoa ki tu va in hoa 
	
}


int main()
{
	string name;
	cout << "nhap vao ho va ten cua ban : ";
	getline(cin, name);

	cout << "ket qua 1 : " << program_1(name) << "\n";
	
	cout << "ket qua 2 : " << program_2(name) << "\n";
	

	
	
}