/*#include<iostream>
#include<string>

using namespace std;

struct nhan_vien {
	string name; int age; float point;
	float salary() {
		float luong = point * 3;
		return luong;
	}
};

int main()
{
	int n;
	float salary = 0;
	cout << "Enter n: "; cin >> n;
	cin.ignore();
	nhan_vien s[100];
	for (int i = 0; i < n; i++) {
		cout << "Enter name " << i+1 << ": ";
		getline(cin, s[i].name);
		cout << "Enter age: "; cin >> s[i].age;
		
		cout << "Enter point: ";cin >> s[i].point;
		
		cin.ignore();
		
		salary += s[i].salary();
	}
	cout << "salary average: " << salary/n << " trieu VND";
	

	
	



}*/
		