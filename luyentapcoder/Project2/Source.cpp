/*#include<iostream>

using namespace std;

struct number
{
	int value;
	number* next;
};
int main()
{
	// init data

	number* n1 = new number;
	n1->value = 1;

	number* n2 = new number;
	n2->value = 3;

	number* n3 = new number;
	n3->value = 6;

	number n4;
	n4.value = 9;

	number* n5 = new number;
	n5->value = 11;


	n1->next = n2;
	n2->next = n3;
	n3->next = &n4;
	n4.next = n5;
	n5->next = NULL;

	number* head = n1;
	number* p = head;
	while (p != NULL) {
		cout << p->value << " ";
		p = p->next;
	}

}*/