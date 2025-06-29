#include <iostream>
#define MAX 100
using namespace std;

void Them(int a[], int &n, int vt, int x) // Thêm phần tử vào mảng
{
    if (vt >= 0 && vt <= n)
    {
        for (int i = n; i > vt ; i--)
        {
            a[i] = a[i - 1];
        }
        a[vt] = x;
        n++;
    }
}


void InMang(int a[], int n) // In bảng mảng
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


int main()
{

    int a[MAX] {1, 2, 3};            // Mảng tĩnh
    int n;                 // Số phần tử hiện có

    cout << "Nhap so luong phan tu ban dau: ";
    cin >> n;

    int x, vt;
    cout << "Nhap gia tri x can chen: ";
    cin >> x;
    cout << "Nhap vi tri muon chen x (tu 0 den " << n << "): ";
    cin >> vt;

    Them(a, n, vt, x);  // Chèn x vào mảng

    InMang(a, n);  // In mảng sau khi chèn

    return 0;
}