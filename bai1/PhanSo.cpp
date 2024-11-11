#include "PhanSo.h"
#include <iostream>
#include <numeric>

/**
 * Default constructor của lớp PhanSo
 * Khởi tạo phân số 0/1
 */
PhanSo::PhanSo() : iTu(0), iMau(1) {}

/**
 * Constructor của lớp PhanSo. Thực hiện kiểm tra mẫu số khác 0 và rút gọn phân số
 * @param tu tử số
 * @param mau mẫu số
 */
PhanSo::PhanSo(int tu, int mau) : iTu(tu), iMau(mau) {
    checkValid();
    RutGon();
}

/**
 * Constructor của lớp PhanSo. Chuyển đổi số thực sang class PhanSo. Thực hiện kiểm tra mẫu số khác 0 và rút gọn phân số
 * @param thuc số thực
 * @throw invalid_argument nếu mẫu số bằng 0
 */
PhanSo::PhanSo(float thuc) {
    int mau = 1;
    while (thuc - static_cast<int>(thuc) != 0) {
        thuc *= 10;
        mau *= 10;
    }
    iTu = static_cast<int>(thuc);
    iMau = mau;
    checkValid();
    RutGon();
}

/**
 * Method rút gọn phân số
 */
void PhanSo::RutGon() {
    int gcd = std::gcd(iTu, iMau);
    iTu /= gcd;
    iMau /= gcd;
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

/**
 * Method kiểm tra mẫu số khác 0
 * @throw invalid_argument nếu mẫu số bằng 0
 */
void PhanSo::checkValid() {
    if (iMau == 0) {
        throw std::invalid_argument("Zero division!");
    }
}

/**
 * Overload toán tử cộng
 * @param lhs phân số thứ nhất
 * @param rhs phân số thứ hai
 * @return tổng của 2 phân số
 */
PhanSo operator+(const PhanSo& lhs, const PhanSo& rhs) {
    return PhanSo(lhs.iTu * rhs.iMau + rhs.iTu * lhs.iMau, lhs.iMau * rhs.iMau);
}

/**
 * Overload toán tử trừ
 * @param lhs phân số thứ nhất
 * @param rhs phân số thứ hai
 * @return hiệu của 2 phân số
 */
PhanSo operator-(const PhanSo& lhs, const PhanSo& rhs) {
    return PhanSo(lhs.iTu * rhs.iMau - rhs.iTu * lhs.iMau, lhs.iMau * rhs.iMau);
}

/**
 * Overload toán tử nhân
 * @param lhs phân số thứ nhất
 * @param rhs phân số thứ hai
 * @return tích của 2 phân số
 */
PhanSo operator*(const PhanSo& lhs, const PhanSo& rhs) {
    return PhanSo(lhs.iTu * rhs.iTu, lhs.iMau * rhs.iMau);
}

/**
 * Overload toán tử chia
 * @param lhs phân số thứ nhất
 * @param rhs phân số thứ hai
 * @return thương của 2 phân số
 */
PhanSo operator/(const PhanSo& lhs, const PhanSo& rhs) {
    return PhanSo(lhs.iTu * rhs.iMau, lhs.iMau * rhs.iTu);
}

/**
 * Overload toán tử so sánh bằng
 * @param lhs phân số thứ nhất
 * @param rhs phân số thứ hai
 * @return true nếu 2 phân số bằng nhau, ngược lại false
 */
bool operator==(const PhanSo& lhs, const PhanSo& rhs) {
    return lhs.iTu * rhs.iMau == rhs.iTu * lhs.iMau;
}

/**
 * Overload toán tử so sánh khác
 * @param lhs phân số thứ nhất
 * @param rhs phân số thứ hai
 * @return true nếu 2 phân số khác nhau, ngược lại false
 */
bool operator!=(const PhanSo& lhs, const PhanSo& rhs) {
    return !(lhs == rhs);
}

/**
 * Overload toán tử so sánh lớn hơn
 * @param lhs phân số thứ nhất
 * @param rhs phân số thứ hai
 * @return true nếu phân số thứ nhất lớn hơn phân số thứ hai, ngược lại false
 */
bool operator>(const PhanSo& lhs, const PhanSo& rhs) {
    return lhs.iTu * rhs.iMau > rhs.iTu * lhs.iMau;
}

/**
 * Overload toán tử so sánh nhỏ hơn
 * @param lhs phân số thứ nhất
 * @param rhs phân số thứ hai
 * @return true nếu phân số thứ nhất nhỏ hơn phân số thứ hai, ngược lại false
 */
bool operator<(const PhanSo& lhs, const PhanSo& rhs) {
    return rhs > lhs;
}

/**
 * Overload toán tử so sánh lớn hơn hoặc bằng
 * @param lhs phân số thứ nhất
 * @param rhs phân số thứ hai
 * @return true nếu phân số thứ nhất lớn hơn hoặc bằng phân số thứ hai, ngược lại false
 */
bool operator>=(const PhanSo& lhs, const PhanSo& rhs) {
    return !(lhs < rhs);
}

/**
 * Overload toán tử so sánh nhỏ hơn hoặc bằng
 * @param lhs phân số thứ nhất
 * @param rhs phân số thứ hai
 * @return true nếu phân số thứ nhất nhỏ hơn hoặc bằng phân số thứ hai, ngược lại false
 */
bool operator<=(const PhanSo& lhs, const PhanSo& rhs) {
    return !(lhs > rhs);
}

/**
 * Overload toán tử nhập
 * @param is stream nhập
 * @param ps phân số cần nhập
 * @return stream nhập
 */
std::istream& operator>>(std::istream& is, PhanSo& ps) {
    char slash;
    is >> ps.iTu >> slash >> ps.iMau;
    if (slash != '/') {
        throw std::invalid_argument("Invalid format!");
    }
    ps.checkValid();
    ps.RutGon();
    return is;
}

/**
 * Overload toán tử xuất
 * @param os stream xuất
 * @param ps phân số cần xuất
 * @return stream xuất
 */
std::ostream& operator<<(std::ostream& os, const PhanSo& ps) {
    if (ps.iTu % ps.iMau == 0) {
        os << ps.iTu / ps.iMau;
        return os;
    }
    os << ps.iTu << "/" << ps.iMau;
    return os;
}