/*#include<iostream>
#include <string>
using namespace std;
int main()
{
	string s, chu, so,convert;
	cout << "nhap vao chuoi s: ";
	getline(cin, s);
	
	convert = s;
	int count = 0, demchuso = 0;
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 32) count++;
		else if (s[i] >= '0' && s[i] <= '9') {
			so += s[i];
			demchuso++;
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			chu += s[i];
			s[i] -= 32;
			demchuso++;
		}
		else if ( s[i] >= 'A' && s[i] <= 'Z') {
			chu += s[i];
			demchuso++;
		}
	}
	cout << "ket qua 1 : " << count << "\n";
	cout << "ket qua 2 : " << demchuso << "\n";
	cout << "ket qua 3 : " << s << "\n";
	cout << "ket qua 4 : " << chu << "   " << so << "\n";
	for (int i = 0; i < convert.length(); i++) {
		switch (convert[i]) {
		case '0': convert.replace(i, 1, "khong"); break;
		case '1': convert.replace(i, 1 ,"mot"); break;
		case '2': convert.replace(i, 1, "hai"); break;
		case '3': convert.replace(i, 1, "ba"); break;
		case '4': convert.replace(i, 1, "tu"); break;
		case '5': convert.replace(i, 1, "nam"); break;
		case '6': convert.replace(i, 1, "sau"); break;
		case '7': convert.replace(i, 1, "bay"); break;
		case '8': convert.replace(i, 1, "tam"); break;
		case '9': convert.replace(i, 1, "chin"); break;
		
		}
	}
	cout << "ket qua 5 : " << convert << "\n";
	cout << "ket qua 6 : ";
	int demphantu = 0;
	for (char i = 'A'; i < 'z'; i++) {
		int count = 0;
		for (int j = 0; j < chu.length(); j++) {
			if (chu[j] == i) {
				count++;
				demphantu++;
			}		
		}
		if (count != 0 && demphantu == chu.length()) cout << "(" << i << "-" << count << ").";
		else if(count != 0 ) cout << "(" << i << "-" << count << "),";
	}
}*/