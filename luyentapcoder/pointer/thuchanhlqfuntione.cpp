/*#include<iostream>


void program_print(int a[], int& length) {
    for (int i = 0; i < length; i++) {
        std :: cout << a[i] << " ";
    }
    std :: cout << "\n";
}
void program_push_back(int a[], int& length, int x) {
    a[length] = x;
    length++;
}
void program_insert(int a[], int& length, int x, int position) {
    if (position > length || position < 0) {
        std :: cout << "Out of array";
        return;
    }
    for (int i = length; i >= position; i--) {
        a[i + 1] = a[i];
    }
    a[position] = x;
    length++;
}
void program_push_front(int a[], int& length, int x) {
    for (int i = length; i >= 0;i--) {
        a[i + 1] = a[i];
    }
    a[0] = x;
    length++;
}
void program_remove(int a[], int& length, int position) {
    if (position > length || position < 0) {
        std::cout << "Out of array";
        return;
    }
    for (int i = position; i < length; i++) {
        a[i] = a[i + 1];
    }
    length--;  
}

void program_remove_value(int a[], int& length, int x) {
    for (int i = length-1; i >= 0; i--) {
        if (a[i] == x) {
           for(int j=i;j< length;j++){
               a[j] = a[j + 1];
           }
            length--;

        }
    }
}





const int MAX = 100;
int main() {
    int a[MAX];
    int length = 0;
    std::cout << "1 - Test push back: ";
    program_push_back(a, length, 5);
    program_push_back(a, length, 10);
    program_push_back(a, length, 15);
    program_push_back(a, length, 20);
    program_print(a, length);

    std::cout << "2 - Test insert: ";
    program_insert(a, length, 13, 2);
    program_print(a, length);
   
    std::cout << "3 - Test push front: ";
    program_push_front(a, length, 2);
    program_push_front(a, length, 2);
    program_push_front(a, length, 2);
    program_print(a, length);

    std::cout << "4 - Test remove: ";
    program_remove(a, length, 4);
    program_print(a, length);
   
    std::cout << "5 - Test remove value: ";
    program_remove_value(a, length, 2);
    program_remove_value(a, length, 15);
    program_print(a, length);
}*/




