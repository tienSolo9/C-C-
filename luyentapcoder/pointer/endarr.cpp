#include<iostream>
#include<cmath>

using namespace std;
bool check_pointer(int* a, int n, int* p)
{
    bool check = 0;
    for (int i = 0; i < n; i++) {
        if (p == (a + i)) check = 1;
    }
    return check;
}

bool check_same_pointers(int* a, int n, int* p1, int* p2)
{
    bool check = 0; 
    for (int i = 0; i < n; i++) {
        if (p1 == a + i && p2 == p1) check = 1;
    }
    return check;
}
int get_distance_in_byte(int* a, int n, int* p1, int* p2) {
    int count = 0;
    if ((p1 > a + n - 1) || (p2 > a + n - 1)) return -1;
    else {
        for (int i = 0; i < n; i++) {
            if ((p1 <= a + i && p2 > a + i) || (p2 <= a + i && p1 > a + i)) count++;
        }
        return count * 4;
    }
}
int move_by_bytes_and_get_value(int* a, int n,int* p, int bytes) {
    int i = bytes / sizeof(int);
    if (bytes % 4 == 0) {
        p += i;
        return *p;
    }
    else
        return -1;
    
}

int main()
{
    const int n = 7;
    int a[n] = { 3, 1, 2, 8, 6, 10, 15 };
    int* p1 = a + 1;
    int* p2 = a + 3;
    int* p3 = NULL;
    int* p4 = a + 8;
    int* p5 = p2 - 2;

    // Test cau 1
    {
        cout << "Test 1.1: " << (check_pointer(a, n, p1) == true ? "Pass" : "Failed") << "\n";
        cout << "Test 1.2: " << (check_pointer(a, n, p2) == true ? "Pass" : "Failed") << "\n";
        cout << "Test 1.3: " << (check_pointer(a, n, p3) == false ? "Pass" : "Failed") << "\n";
        cout << "Test 1.4: " << (check_pointer(a, n, p4) == false ? "Pass" : "Failed") << "\n";
        cout << "----\n";
    }

    // Test cau 2
    {
        cout << "Test 2.1: " << (check_same_pointers(a, n, p1, p2) == false ? "Pass" : "Failed") << "\n";
        cout << "Test 2.2: " << (check_same_pointers(a, n, p1, p2 - 2) == true ? "Pass" : "Failed") << "\n";
        cout << "----\n";
    }
    // Test cau 3
    {
        cout << "Test 3.1: " << (get_distance_in_byte(a, n, p1, p2) == 8 ? "Pass" : "Failed") << "\n";
        cout << "Test 3.2: " << (get_distance_in_byte(a, n, p1, a + 8) == -1 ? "Pass" : "Failed") << "\n";
        cout << "----\n";
    }
    // Test cau 4
    {
        cout << "Test 4.1: " << (move_by_bytes_and_get_value(a, n, p1, 4) == 2 ? "Pass" : "Failed") << "\n";
        cout << "Test 4.2: " << (move_by_bytes_and_get_value(a, n, p1, 12) == 6 ? "Pass" : "Failed") << "\n";
        cout << "Test 4.3: " << (move_by_bytes_and_get_value(a, n, p1, 3) == -1 ? "Pass" : "Failed") << "\n";
        cout << "Test 4.4: " << (move_by_bytes_and_get_value(a, n, p1, -1) == -1 ? "Pass" : "Failed") << "\n";
        cout << "----\n";
    }
}