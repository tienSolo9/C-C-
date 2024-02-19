/*#include<iostream>
#include<string>
using namespace std;

struct book {
	string id; string title;
};

void print(book book[], int length) {
	for (int i = 0; i < length; i++) {
		cout << "	" << book[i].id << "	- " << book[i].title << "\n";
	}
}

void change(book& book1, book& book2) {
	book temp = book1;
	book1 = book2;
	book2 = temp;
}

string findmax(book book[], int length) {
	int max = book[0].title.length();
	int index = 0;
	for (int i = 0; i < length; i++) {
		if (max < book[i].title.length()) {
			max = book[i].title.length();
			index = i;
		}   
	}
	
	return book[index].title;
}

float average_length(book book[], int length) {
	float sum = 0;
	for (int i = 0; i < length; i++) {
		sum += book[i].title.length();
	}
	return sum / length;
}

void sort_title(book book[], int length) {
	for (int i = 0; i < length; i++) {
		for (int j = i+1; j < length; j++) {
			if (book[i].title[0] > book[j].title[0]) change(book[i], book[j]);
		}
	}
}



int main()
{
	book list[100];
	int length = 0;
	string data;
	cout << "nhap vao ten sach: ";
	getline(cin, data);

	// phan tich du lieu
	string test[20];
	int l = data.find("|");

	while (l != string::npos) {
		test[length] = data.substr(0, l);
		data = data.substr(l + 1);
		l = data.find("|");
		length++;
	}
	test[length] = data; length++;
	for (int i = 0; i < length; i++) {
		int idx = test[i].find(";");
		list[i].id = test[i].substr(0, idx);
		list[i].title = test[i].substr(idx + 1);
	}

	
	cout << "ket qua 1 : \n";
	change(list[0], list[1]);
	print(list, length);
	cout << "ket qua 2 : " << findmax(list, length) << "\n";
	cout << "ket qua 3 : " << average_length(list, length) << "\n";
	cout << "ket qua 4 : " << "\n";
	sort_title(list, length);
	print(list, length);


}*/