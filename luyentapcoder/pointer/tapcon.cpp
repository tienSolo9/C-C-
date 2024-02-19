/*#include<iostream>
using namespace std;
#include<algorithm>

bool is_subarray(int a[], int length_a, int b[], int length_b) {
	if (length_a < length_b) return false;

	for (int i = 0; i < length_a; i++) {
		if (a[i] == b[0])
		{
			if (i + length_b > length_a) return false;
			bool check = true;
			for (int j = 0; j < length_b; j++)
			{
				if (b[j] != a[i + j])
				{
					check = false;
					break;
				}
			}
			if (check) return true;
		}
	}
	return false;
}
using namespace std;
int main()
{
	
	int const length_a = 8;
	int const length_b = 3;
	int a[length_a] = {1, 2, 3, 4, 9,3,4};
	int b[length_b] = { 3,4,5 };
	
	
	bool result = is_subarray(a, length_a, b, length_b);

	cout << (result ? "True" : "False");








	//function an san 
	int const length_a = 5;
	int const length_b = 5;
	int a[length_a] = { 1,2,3,7,5 };
	int b[length_b] = { 1,2,3,4,5 };
	int check = equal(a, a + length_a, b, b + length_b);

	cout << (check ? " giong nhau" : " khac nhau");
}
*/