#include "SoPhuc.h"

/**
 * Default constructor của class SoPhuc
 * Khởi tạo số phức với phần thực và ảo bằng 0
 */
SoPhuc::SoPhuc() : dThuc(0), dAo(0) {}

/**
 * Constructor của class SoPhuc
 * Khởi tạo số phức với phần thực và ảo bằng giá trị truyền vào
 * @param real Phần thực
 * @param imag Phần ảo
 */
SoPhuc::SoPhuc(float real, float imag) : dThuc(real), dAo(imag) {}

/**
 * Constructor của class SoPhuc
 * Dùng để cast một số thực thành số phức
 * @param real Phần thực
 */
SoPhuc::SoPhuc(float real) : dThuc(real), dAo(0) {}

/**
 * Toán tử cộng 2 số phức
 * @param lhs Số phức thứ nhất
 * @param rhs Số phức thứ hai
 * @return Kết quả của phép cộng
 */
SoPhuc operator+(const SoPhuc& lhs, const SoPhuc& rhs) {
    return SoPhuc(lhs.dThuc + rhs.dThuc, lhs.dAo + rhs.dAo);
}

/**
 * Toán tử trừ 2 số phức
 * @param lhs Số phức bị trừ
 * @param rhs Số phức trừ đi
 * @return Kết quả của phép trừ
 */
SoPhuc operator-(const SoPhuc& lhs, const SoPhuc& rhs) {
    return SoPhuc(lhs.dThuc - rhs.dThuc, lhs.dAo - rhs.dAo);
}

/**
 * Toán tử nhân 2 số phức
 * @param lhs Số phức thứ nhất
 * @param rhs Số phức thứ hai
 * @return Kết quả của phép nhân
 */
SoPhuc operator*(const SoPhuc& lhs, const SoPhuc& rhs) {
    return SoPhuc(lhs.dThuc * rhs.dThuc - lhs.dAo * rhs.dAo, lhs.dThuc * rhs.dAo + lhs.dAo * rhs.dThuc);
}

/**
 * Toán tử chia 2 số phức
 * @param lhs Số phức bị chia
 * @param rhs Số phức chia
 * @return Kết quả của phép chia
 */
SoPhuc operator/(const SoPhuc& lhs, const SoPhuc& rhs) {
    float denominator = rhs.dThuc * rhs.dThuc + rhs.dAo * rhs.dAo;
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero!");
    }
    return SoPhuc((lhs.dThuc * rhs.dThuc + lhs.dAo * rhs.dAo) / denominator, (lhs.dAo * rhs.dThuc - lhs.dThuc * rhs.dAo) / denominator);
}

/**
 * Toán tử so sánh bằng 2 số phức
 * @param lhs Số phức thứ nhất
 * @param rhs Số phức thứ hai
 * @return true nếu 2 số phức bằng nhau, ngược lại trả về false
 */
bool operator==(const SoPhuc& lhs, const SoPhuc& rhs) {
    return lhs.dThuc == rhs.dThuc && lhs.dAo == rhs.dAo;
}

/**
 * Toán tử so sánh khác 2 số phức
 * @param lhs Số phức thứ nhất
 * @param rhs Số phức thứ hai
 * @return true nếu 2 số phức khác nhau, ngược lại trả về false
 */
bool operator!=(const SoPhuc& lhs, const SoPhuc& rhs) {
    return !(lhs == rhs);
}

/**
 * Toán tử nhập số phức từ bàn phím
 * @param is Tham chiếu đến stream nhập
 * @param sp Tham chiếu đến số phức cần nhập
 * @return Tham chiếu đến stream nhập
 */
std::istream& operator>>(std::istream& is, SoPhuc& sp) {
    is >> sp.dThuc >> sp.dAo;
    return is;
}

/**
 * Overload toán tử xuất
 * @param os Tham chiếu đến stream xuất
 * @param sp Tham chiếu đến số phức cần xuất
 * @return Tham chiếu đến stream xuất
 */
std::ostream& operator<<(std::ostream& os, const SoPhuc& sp) {
    if (sp.dThuc != 0) {
        os << sp.dThuc;
    }

    if (sp.dAo != 0) {
        if (sp.dAo > 0 && sp.dThuc != 0) {
            os << " + ";
        } else if (sp.dAo < 0) {
            os << " - ";
        }
        os << std::abs(sp.dAo) << "i";
    }

    if (sp.dThuc == 0 && sp.dAo == 0) {
        os << 0;
    }

    return os;
}