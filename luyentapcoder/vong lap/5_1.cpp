#include<iostream>
#include<string>
int main()
{
	std::string name = "i love information technology 987";
	std::string test;
	;
	for (int i = 0; i < name.length(); i++) {
		if (name[i] > 'a' && name[i] < 'z') {
			test += name[i];
			
		}
	}
	
	std::cout << test;
	
}
