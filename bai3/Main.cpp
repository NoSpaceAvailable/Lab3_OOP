#include "ThoiGian.cpp"
#include <iostream>
using namespace std;

/**
 * Hàm main thực hiện nhập 2 object ThoiGian và lần lượt sử dụng các toán tử đã được overload
 */
int main() {
    ThoiGian a, b;
    cout << "Nhap thoi gian a (VD: 23:59:59): "; cin >> a;
    cout << "Nhap thoi gian b (VD: 23:59:59): "; cin >> b;
    cout << "--------------------------------------------------\n";
    cout << "Thoi gian a: " << a << endl;
    cout << "Thoi gian b: " << b << endl;
    cout << "--------------------------------------------------\n";
    cout << "Tong thoi gian a + b: " << a + b << endl;
    cout << "Hieu thoi gian a - b: " << a - b << endl;
    cout << "Ket qua a == b: " << (a == b ? "true" : "false") << endl;
    cout << "Ket qua a != b: " << (a != b ? "true" : "false") << endl;
    cout << "Ket qua a > b: " << (a > b ? "true" : "false") << endl;
    cout << "Ket qua a < b: " << (a < b ? "true" : "false") << endl;
    cout << "Ket qua a >= b: " << (a >= b ? "true" : "false") << endl;
    cout << "Ket qua a <= b: " << (a <= b ? "true" : "false") << endl;
    cout << "--------------------------------------------------\n";
    cout << "a++: " << ++a << endl;
    cout << "a--: " << --a << endl;
    cout << "--------------------------------------------------\n";
    cout << "Nhap so giay s: "; int s; cin >> s;
    cout << "Thoi gian a + s giay: " << a + s << endl;
    cout << "Thoi gian a - s giay: " << a - s << endl;
    cout << "Ket qua a == s: " << (a == s ? "true" : "false") << endl;
    cout << "Ket qua a != s: " << (a != s ? "true" : "false") << endl;
    cout << "Ket qua a > s: " << (a > s ? "true" : "false") << endl;
    cout << "Ket qua a < s: " << (a < s ? "true" : "false") << endl;
    cout << "Ket qua a >= s: " << (a >= s ? "true" : "false") << endl;
    cout << "Ket qua a <= s: " << (a <= s ? "true" : "false") << endl;
    cout << "--------------------------------------------------\n";

}