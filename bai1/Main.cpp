#include "PhanSo.cpp"
#include <iostream>
using namespace std;

/**
 * Hàm main thực hiện nhập 2 phân số và lần lượt sử dụng các toán tử đã được overload
 */
int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so 1 (VD: 1/2): "; cin >> ps1;
    cout << "Nhap phan so 2 (VD: 1/2): "; cin >> ps2;

    cout << "-------------------------------------------------\n";

    cout << "Phan so 1: " << ps1 << endl;
    cout << "Phan so 2: " << ps2 << endl;

    cout << "--> Tong cua 2 phan so: " << ps1 + ps2 << endl;
    cout << "--> Hieu cua 2 phan so: " << ps1 - ps2 << endl;
    cout << "--> Tich cua 2 phan so: " << ps1 * ps2 << endl;
    cout << "--> Thuong cua 2 phan so: " << ps1 / ps2 << endl;

    cout << "--> Ket qua ps1 == ps2: " << (ps1 == ps2 ? "true" : "false") << endl;
    cout << "--> Ket qua ps1 != ps2: " << (ps1 != ps2 ? "true" : "false") << endl;
    cout << "--> Ket qua ps1 > ps2: " << (ps1 > ps2 ? "true" : "false") << endl;
    cout << "--> Ket qua ps1 < ps2: " << (ps1 < ps2 ? "true" : "false") << endl;
    cout << "--> Ket qua ps1 >= ps2: " << (ps1 >= ps2 ? "true" : "false") << endl;
    cout << "--> Ket qua ps1 <= ps2: " << (ps1 <= ps2 ? "true" : "false") << endl;

    cout << "-------------------------------------------------\n";

    cout << "Nhap so thuc f: "; float f; cin >> f;
    cout << "--> Ket qua ps1 + f: " << ps1 + f << endl;
    cout << "--> Ket qua ps1 - f: " << ps1 - f << endl;
    cout << "--> Ket qua ps1 * f: " << ps1 * f << endl;
    cout << "--> Ket qua ps1 / f: " << ps1 / f << endl;

    cout << "--> Ket qua ps1 == f: " << (ps1 == f ? "true" : "false") << endl;
    cout << "--> Ket qua ps1 != f: " << (ps1 != f ? "true" : "false") << endl;
    cout << "--> Ket qua ps1 > f: " << (ps1 > f ? "true" : "false") << endl;
    cout << "--> Ket qua ps1 < f: " << (ps1 < f ? "true" : "false") << endl;
    cout << "--> Ket qua ps1 >= f: " << (ps1 >= f ? "true" : "false") << endl;
    cout << "--> Ket qua ps1 <= f: " << (ps1 <= f ? "true" : "false") << endl;

}