/*#include<iostream>
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
	// xoa ki tu dac biet
	for (int i = s.length() - 1; i >= 0; i--) {
		if ((s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') || s[i] == ' ') {
			continue;
		}
		else {
			for (int j = i; j < s.length(); j++) {
				s[j] = s[j + 1];
			}
		}
	}
	// xoa khoang trong va tao ra 1 mang luu tung ten
	string a[199];
	string s1;
	int i = s.find(" ");
	int last_index = 0;
	while (i != string::npos) {
		if (i == 0) s = s.substr(1);
		else {
			a[last_index] = s.substr(0, i);
			s = s.substr(i + 1);
			last_index++;
		}
		i = s.find(" ");
	}
	a[last_index] = s;
	last_index++;
	// in hoa va ghep lai
	for (int q = 0; q < last_index; q++) {
		string test = a[q];
		for (int j = 0; j < test.length(); j++) {
			if (test[0] >= 'a' && test[0] <= 'z') test[0] -= 32;
			if (test[j] >= 'A' && test[j] <= 'Z') test[j] += 32;
		}
		s1 += test + " ";
	}
	
	return s1;
	
	//xoa ki tu va in hoa 

}

string program_3(string s) {
	string s1 = program_2(s);
	int last_index = s1.length() - 1;
	s1 = s1.substr(0, last_index);
	string email;
	int i = s1.find(" ");
	while (i != string::npos) {
		if (s1[0] >= 'A' && s1[0] <= 'Z')  s1[0] += 32;
		email += s1[0];
		s1 = s1.substr(i + 1);
		i = s1.find(" ");
	}
	for (int j = 0; j < s1.length(); j++) {
		if (s1[j] >= 'A' && s1[j] <= 'Z')  s1[0] += 32;
	}
	s1 =  s1 + email + "@gmail.com";
	return s1;
}
int main()
{
	string name;
	cout << "nhap vao ho va ten cua ban : ";
	getline(cin, name);

	cout << "ket qua 1 : " << program_1(name) << "\n";

	cout << "ket qua 2 : " << program_2(name) << "\n";

	cout << "ket qua 3 : " << program_3(name) << "\n";


}*/