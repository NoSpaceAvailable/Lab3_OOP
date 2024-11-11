#include "NgayThangNam.cpp"
#include <iostream>
using namespace std;

/**
 * Hàm main thực hiện nhập 2 object NgayThangNam và lần lượt sử dụng các toán tử đã được overload
 */
int main() {
    NgayThangNam a, b;
    cout << "Nhap ngay thang nam a: "; cin >> a;
    cout << "Nhap ngay thang nam b: "; cin >> b;
    cout << "--------------------------------------------\n";
    cout << "Ngay thang nam a: " << a << endl;
    cout << "Ngay thang nam b: " << b << endl;
    cout << "--------------------------------------------\n";
    cout << "Tong a + b: " << a + b << endl;
    cout << "Hieu a - b: " << a - b << endl;
    cout << "--------------------------------------------\n";
    cout << "a++: " << ++a << endl;
    cout << "b--: " << --b << endl;
    cout << "--------------------------------------------\n";
    cout << "Ket qua a == b: " << (a == b ? "true" : "false") << endl;
    cout << "Ket qua a != b: " << (a != b ? "true" : "false") << endl;
    cout << "Ket qua a > b: " << (a > b ? "true" : "false") << endl;
    cout << "Ket qua a >= b: " << (a >= b ? "true" : "false") << endl;
    cout << "Ket qua a < b: " << (a < b ? "true" : "false") << endl;
    cout << "Ket qua a <= b: " << (a <= b ? "true" : "false") << endl;
    cout << "--------------------------------------------\n";
    cout << "Nhap so ngay d: "; int d; cin >> d;
    cout << "Ngay a + d: " << a + d << endl;
    cout << "Ngay b - d: " << b - d << endl;

}