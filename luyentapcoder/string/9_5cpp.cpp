/*#include<iostream>
#include<string>

using namespace std;

int program_1(string s1, string s2) {
	if (s1.length() > s2.length()) return 1;
	else if (s1.length() < s2.length()) return -1;
	return 0;
}

string program_2(string s1, string s2) {
	string c,result;
	int last_index = 0;
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {
			if (s1[i] == s2[j] && s1[i] != ' ') {
				c += s1[i];
				last_index++;
				break;
			}
		}
	}
	for (int i = last_index - 1; i >= 0;i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (c[j] == c[i]) {
				for (int q = i; q < last_index; q++) {
					c[q] = c[q + 1];
				}
				last_index--;
			}
		}
	}
	for (int i = 0; i < last_index; i++) {
		if (i == last_index - 1) result += c[i];
		else {
			result += c[i];
			result += ", ";
		}
	}
	return result;
}

string program_3(string s1, string s2) {
	int i = s1.find(" ");
	int j = s2.find(" ");
	while (i != string::npos) {
		s1 = s1.substr(i + 1);
		i = s1.find(" ");
	}
	while (j != string::npos) {
		s2 = s2.substr(j + 1);
		j = s2.find(" ");
	}
	string s =s1 + " love " + s2;
	return s;
}

int  program_4(string s1, string s2) {
	int i = s1.find(" ");
	int j = s2.find(" ");
	int index = 0;
	while (i != string::npos) {
		s1 = s1.substr(i + 1);
		i = s1.find(" ");
	}
	while (j != string::npos) {
		s2 = s2.substr(j + 1);
		j = s2.find(" ");
	}

	while (index < s1.length() && index < s2.length() && s1[index] == s2[index]) {
		index++;
	}
	if (s1[index] > s2[index]) return 1;
	else if (s1[index] < s2[index]) return -1;
	return 0;

}
int main()
{
	string s1, s2;
	cout << "enter the user 1 : ";
	getline(cin, s1);
	cout << "enter the user 2 : ";
	getline(cin, s2);

	cout << "result 1 : " << program_1(s1, s2) << "\n";
	cout << "result 2 : " << program_2(s1, s2) << "\n";
	cout << "result 3 : " << program_3(s1, s2) << "\n";
	cout << "result 4 : " << program_4(s1, s2) << "\n";
}*/