#include "SoPhuc.cpp"
#include <iostream>
using namespace std;

/**
 * Hàm main thực hiện nhập 2 object SoPhuc và lần lượt sử dụng các toán tử đã được overload
 */
int main() {
    SoPhuc a, b;
    cout << "Nhap so phuc a (VD: 2 3): "; cin >> a;
    cout << "Nhap so phuc b (VD: 2 3): "; cin >> b;

    cout << "-----------------------------------------------------\n";
    cout << "So phuc a: " << a << endl;
    cout << "So phuc b: " << b << endl;
    cout << "-----------------------------------------------------\n";
    cout << "Tong a + b: " << a + b << endl;
    cout << "Hieu a - b: " << a - b << endl;
    cout << "Tich a * b: " << a * b << endl;
    cout << "Thuong a / b: " << a / b << endl;
    cout << "So phuc a == b: " << (a == b ? "true" : "false") << endl;
    cout << "So phuc a != b: " << (a != b ? "true" : "false") << endl;
    cout << "-----------------------------------------------------\n";
    cout << "Nhap so thuc f: "; float f; cin >> f;
    cout << "Tong a + f: " << a + f << endl;
    cout << "Hieu a - f: " << a - f << endl;
    cout << "Tich a * f: " << a * f << endl;
    cout << "Thuong a / f: " << a / f << endl;
    cout << "So phuc a == f: " << (a == f ? "true" : "false") << endl;
    cout << "So phuc a != f: " << (a != f ? "true" : "false") << endl;
    cout << "-----------------------------------------------------\n";

}