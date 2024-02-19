#include<iostream>
#include<string>
using namespace std;
int main() {
	string ten = "";
	int tuoi;
	float chieu_cao, can_nang;
	string que_quan;
	bool hon_nhan = false;
	char kq;

	cout << "nhap ten: ";
	getline(cin, ten);

	cout << "nhap tuoi: ";
	cin >> tuoi;

	cin.ignore();

	cout << "nhap Que Quan: ";
	getline(cin, que_quan);

	cout << "nhap can nang: ";
	cin >> can_nang;

	cout << "nhap chieu cao: ";
	cin >> chieu_cao;


	cout << "nhap ket qua thi thpt: ";
	cin >> kq;

	cout << "********************************************************************\n**************************SO YEU LI LICH****************************\n********************************************************************";
	cout << "\nnho ten: " << ten << "\nnam nay: " << tuoi << " tuoi.\nque quan " << que_quan;
	cout << "\nchieu cao: " << chieu_cao << "\n-can nang: " << can_nang << "\nket qua thi thpt loai: " << kq;


}