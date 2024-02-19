#include<iostream>
#include<string>

using namespace std;

int main()
{
	string data;
	cout << "nhap danh sach :";
	getline(cin, data);

	//question 1
	string a[100];
	int i = data.find(';');
	int last_index = 0;
	while (i != string::npos) {
		a[last_index] = data.substr(0, i);
		data = data.substr(i + 1);
		i = data.find(';');
		last_index++;
	}
	a[last_index] = data;
	last_index++;

	int max = a[0].length();
	int index = 0;
	for (int j = 0; j < last_index; j++) {
		if (max < a[j].length()) {
			max = a[j].length();
			index = j;
		}
	}
	//question 2:
	float arithmetic_mean = 0;
	for (int j = 0; j < last_index; j++) {
		arithmetic_mean += a[j].length();
	}
	//question 3:
	cout << "result 1 : " << a[index] << "\n";
	cout << "result 2 : " << arithmetic_mean / last_index << "\n";

	
	for (int I = 0; I < last_index; I++) {
		for (int j = a[I].length() - 1; j >= 0; j--) {
			if (a[I][j] >= 'A' && a[I][j] <= 'Z' || a[I][j] >= 'a' && a[I][j] <= 'z' || a[I][j] == ' ') {}
			else {
				for (int k = j; k < a[I].length(); k++) {
					a[I][k] = a[I][k + 1];
				}
			}
		}
	}
	string s[199];
	for (int I = 0; I < last_index; I++) {
		string test = a[I];
		for (int j = 0; j < test.length(); j++) {
			if (test[0] >= 'a' && test[0] <= 'z') test[0] -= 32;
			if (test[j+1] >= 'A' && test[j+1] <= 'Z') test[j+1] += 32;
		}
		s[I] += test + " ";
	}

	string result[10];
	for (int i = 0; i < last_index; i++) {
		int podelimiter = s[i].find(" ");
		while (podelimiter != string::npos) {
			string line = s[i].substr(0, podelimiter+1);
			if (line[0] >= 'a' && line[0] <= 'z') line[0] -= 32;

			result[i] += line;
			s[i] = s[i].substr(podelimiter + 1);
			podelimiter = s[i].find(" ");
		}

	}
	cout << "result 3 : ";
	for (int i = 0; i < last_index; i++) {
		if (i == last_index - 1) cout << result[i] << ".";
		else {
			result[i] = result[i].substr(0,result[i].size()-1);
			cout << result[i] << ", ";
		}
	}

	cout << "\nresult 4: ";
	for (int i = 0; i < last_index; i++) {
		int podelimiter = result[i].find(" ");
		string line = result[i];

		while (podelimiter != string::npos) {
			line = line.substr(0, podelimiter);
			podelimiter = line.find(" ");
		}
		for (int j = i + 1; j < last_index; j++) {
			string line2 = result[j];
			int podelimiter2 = result[j].find(" ");
			while (podelimiter2 != string::npos) {
				line2 = line2.substr(0, podelimiter2);
				podelimiter2 = line2.find(" ");
			}
			if (line > line2) {
				string temp = result[i];
				result[i] = result[j];
				result[j] = temp;
			}
		}
	}
	for (int i = 0; i < last_index; i++) {
		if (i == last_index - 1) cout << result[i] << ".";
		else {
			result[i] = result[i].substr(0, result[i].size() - 1);
			cout << result[i] << ", ";
		}
	}
}
