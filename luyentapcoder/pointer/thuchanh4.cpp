/*#include <iostream>
using namespace std;
int main()
{
    int m;
    int n;
    cout << "nhap m : ";
    cin >> m;
    cout << "nhap n : ";
    cin >> n;

    int a[20][20] = {};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
        cout << "\n";
    }
    int sum = 0;
    int max = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > max) max = a[i][j];
            sum += a[i][j];
        }
    }
    cout << "result 1 : " << sum << "\n";
    cout << "result 2 : " << max << "\n";
    cout << "result 3 : " ;
    int asum[20] = {};
    for (int i = 0; i < m; i++) {
        int k = 0;
        for (int j = 0; j < n; j++) {
            k += a[i][j];
        }
        asum[i] = {k};
    }
    int summax = asum[0];
    int index = 0;
    for (int i = 0; i < m; i++) {
        if (asum[i] > summax) {
            summax = asum[i];
            index = i;
        }
    }
    for (int j = 0; j < n; j++) {
        cout << a[index][j] << " ";
    }
    int count = 0;
    bool stop = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            count = 0;
            for (int k = 1; k <= max; k++) {
                if (a[i][j] % k == 0) count++;
            }
            if (count == 2) {
                cout  << "result 4 : "<<  a[i][j] ;
                stop = true;
                break;
            }
        }  
        if (stop == true) break;
    }
    if (stop == false) cout << "\nresult 4 : khong ton tai so nguyen to trong mang";
}*/