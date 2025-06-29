#include <iostream>
using namespace std;

int main() {
    int capacity = 2;                 // Dung lượng ban đầu của mảng là 2
    int* data = new int[capacity];   // Cấp phát mảng động ban đầu
    int length = 0;                  // Số lượng phần tử thực tế

    int n, x;
    cout << "Nhap so phan tu muon them: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> x;

        if (length == capacity) // Nếu mảng đầy, cần tăng gấp đôi dung lượng
        {
            int* newData = new int[capacity * 2]; // Tạo mảng mới lớn hơn
            for (int j = 0; j < length; j++)
                newData[j] = data[j];             // Sao chép dữ liệu cũ sang
            delete[] data;                        // Giải phóng mảng cũ
            data = newData;
            capacity *= 2;
        }

        data[length++] = x;   // Thêm phần tử vào cuối và tăng số lượng
    }

    cout << "Mang sau khi them: ["; // In ra mảng sau khi thêm
    for (int i = 0; i < length; i++) 
    {
        cout << data[i];
        if (i < length - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "So luong phan tu: " << length << endl;

    delete[] data;  // Giải phóng bộ nhớ khi kết thúc
    return 0;
}