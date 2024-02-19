/*#include<iostream>

int sizeof_array(int length) {
    int size = sizeof(int) * length;
    return size;
}
void table(int a[], int length) {
    std::cout << "\tDia chi" << "                 Gia tri\n";
    for (int i = 0; i < length; i++) {
        std::cout << "\t" << &a[i] << "\t" << a[i] << "\n";
    }
}

int main()
{
    const int length = 5;
    int a[length] = {};
    for (int i = 0; i < length; i++) {
       std::cout << "a[" << i << "] = ";
       std::cin >> a[i];
    }
    std::cout << "Ket qua 1: " << sizeof_array(length) << " bytes\n";
    std::cout << "Ket qua 2:\n"; table(a, length);
}*/