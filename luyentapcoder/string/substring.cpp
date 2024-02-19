/*#include<iostream>
#include<string>
using namespace std;

void sub_str(string name,string a[],int& last_index) {
	int i = name.find(" ");
	while (i != string::npos) {
		a[last_index] = name.substr(0, i);
		last_index++;
		name = name.substr(i + 1);
		i = name.find(" ");
	}
	a[last_index] = name;
	last_index++;
}
	
int main()
{
	string name = "Tien Dep Trai Hoc Gioi";
	string a[100];
	int last_index = 0;
	sub_str(name, a, last_index);

	for (int i = 0; i < last_index; i++) {
		cout << a[i] << "\n";
	}


	//cout << name.substr(5); // neu khong chi dinh so luong ki tu cat thi se tu hieu la cat het

}*/