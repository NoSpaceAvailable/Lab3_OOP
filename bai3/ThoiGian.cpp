#include <iostream>
#include "ThoiGian.h"

/**
 * Method kiểm tra giá trị của thời gian có hợp lệ không
 * @throw std::invalid_argument nếu giá trị không hợp lệ
 */
void ThoiGian::checkValid() {
    if (this->iGio < 0 || this->iPhut < 0 || this->iGiay < 0
     || this->iGio > 23 || this->iPhut > 59 || this->iGiay > 59)
        throw std::invalid_argument("Invalid time range!");
}

/**
 * Default constructor của class ThoiGian. Khởi tạo giờ, phút, giây bằng 0
 */
ThoiGian::ThoiGian() {
    this->iGio = 0;
    this->iPhut = 0;
    this->iGiay = 0;
}

/**
 * Constructor của class ThoiGian. Khởi tạo giờ, phút, giây bằng tham số truyền vào
 * @param h giờ
 * @param m phút
 * @param s giây
 * @throw std::invalid_argument nếu giá trị không hợp lệ
 */
ThoiGian::ThoiGian(int h, int m, int s) {
    this->iGio = h;
    this->iPhut = m;
    this->iGiay = s;
    this->checkValid();
}

/**
 * Constructor của class ThoiGian. Khởi tạo giờ, phút, giây bằng số giây truyền vào
 * @param s số giây
 */
ThoiGian::ThoiGian(int s) {
    this->TinhLaiGio(s);
}

/**
 * Method tính tổng số giây của ThoiGian
 * @return tổng số giây
 */
int ThoiGian::TinhGiay() const {
    return this->iGio * 3600 + this->iPhut * 60 + this->iGiay;
}

/**
 * Method tính lại giờ, phút, giây của object từ số giây truyền vào
 * @param s số giây
 * @throw std::invalid_argument nếu giá trị không hợp lệ
 */
void ThoiGian::TinhLaiGio(int s) {
    this->iGio = s / 3600;
    this->iPhut = s % 3600 / 60;
    this->iGiay = s % 60; 

    while (this->iGiay > 59) {
        this->iGiay -= 60;
        this->iPhut++;
    }

    while (this->iPhut > 59) {
        this->iPhut -= 60;
        this->iGio++;
    }

    while (this->iGio > 23) {
        this->iGio -= 24;
    }

    if (this->TinhGiay() < 0) {
        this->TinhLaiGio(this->TinhGiay() + 86400);
    }
}

/**
 * Overload toán tử +
 * @param tg1 ThoiGian 1
 * @param tg2 ThoiGian 2
 * @return ThoiGian sau khi cộng
 */
ThoiGian operator+(const ThoiGian& tg1, const ThoiGian& tg2) {
    int totalSeconds = tg1.TinhGiay() + tg2.TinhGiay();
    ThoiGian result(totalSeconds);
    return result;
}

/**
 * Overload toán tử -
 * @param tg1 ThoiGian 1
 * @param tg2 ThoiGian 2
 * @return ThoiGian sau khi trừ
 */
ThoiGian operator-(const ThoiGian& tg1, const ThoiGian& tg2) {
    int totalSeconds = tg1.TinhGiay() - tg2.TinhGiay();
    ThoiGian result(totalSeconds);
    return result;
}

/**
 * Overload toán tử ++ (tiền tố)
 * @return ThoiGian sau khi tăng 1 giây
 */
ThoiGian ThoiGian::operator++() {
    this->TinhLaiGio(this->TinhGiay() + 1);
    return *this;
}

/**
 * Overload toán tử -- (tiền tố)
 * @return ThoiGian sau khi giảm 1 giây
 */
ThoiGian ThoiGian::operator--() {
    this->TinhLaiGio(this->TinhGiay() - 1);
    return *this;
}

/**
 * Overload toán tử ==
 * @param tg1 ThoiGian 1
 * @param tg2 ThoiGian 2
 * @return true nếu bằng nhau (giờ, phút, giây đều bằng nhau), ngược lại false
 */
bool operator==(const ThoiGian& tg1, const ThoiGian& tg2) {
    return tg1.iGio == tg2.iGio && tg1.iPhut == tg2.iPhut && tg1.iGiay == tg2.iGiay;
}

/**
 * Overload toán tử !=
 * @param tg1 ThoiGian 1
 * @param tg2 ThoiGian 2
 * @return true nếu khác nhau, ngược lại false
 */
bool operator!=(const ThoiGian& tg1, const ThoiGian& tg2) {
    return !(tg1 == tg2);
}

/**
 * Overload toán tử >
 * @param tg1 ThoiGian 1
 * @param tg2 ThoiGian 2
 * @return true nếu tg1 > tg2, ngược lại false
 */
bool operator>(const ThoiGian& tg1, const ThoiGian& tg2) {
    if (tg1.iGio > tg2.iGio) return true;
    if (tg1.iGio == tg2.iGio) {
        if (tg1.iPhut > tg2.iPhut) return true;
        if (tg1.iPhut == tg2.iPhut) {
            if (tg1.iGiay > tg2.iGiay) return true;
        }
    }
    return false;
}

/**
 * Overload toán tử <
 * @param tg1 ThoiGian 1
 * @param tg2 ThoiGian 2
 * @return true nếu tg1 < tg2, ngược lại false
 */
bool operator<(const ThoiGian& tg1, const ThoiGian& tg2) {
    return !(tg1 >= tg2);
}

/**
 * Overload toán tử >=
 * @param tg1 ThoiGian 1
 * @param tg2 ThoiGian 2
 * @return true nếu tg1 >= tg2, ngược lại false
 */
bool operator>=(const ThoiGian& tg1, const ThoiGian& tg2) {
    if (tg1.iGio > tg2.iGio) return true;
    if (tg1.iGio == tg2.iGio) {
        if (tg1.iPhut > tg2.iPhut) return true;
        if (tg1.iPhut == tg2.iPhut) {
            if (tg1.iGiay >= tg2.iGiay) return true;
        }
    }
    return false;
}

/**
 * Overload toán tử <=
 * @param tg1 ThoiGian 1
 * @param tg2 ThoiGian 2
 * @return true nếu tg1 <= tg2, ngược lại false
 */
bool operator<=(const ThoiGian& tg1, const ThoiGian& tg2) {
    return !(tg1 > tg2);
}

/**
 * Overload toán tử >>, theo format hh:mm:ss
 * @param is stream đầu vào
 * @param tg ThoiGian
 * @return stream đầu vào
 * @throw std::invalid_argument nếu giá trị không hợp lệ
 */
std::istream& operator>>(std::istream& is, ThoiGian& tg) {
    char colon;
    is >> tg.iGio >> colon >> tg.iPhut >> colon >> tg.iGiay;
    if (colon != ':') throw std::invalid_argument("Invalid time format!");
    tg.checkValid();
    return is;
}

/**
 * Overload toán tử <<, theo format hh:mm:ss
 * @param os stream đầu ra
 * @param tg ThoiGian
 * @return stream đầu ra
 */
std::ostream& operator<<(std::ostream& os, const ThoiGian& tg) {
    if (tg.iGio < 10) os << "0";
    os << tg.iGio << ":";
    if (tg.iPhut < 10) os << "0";
    os << tg.iPhut << ":";
    if (tg.iGiay < 10) os << "0";
    os << tg.iGiay;
    return os;
}