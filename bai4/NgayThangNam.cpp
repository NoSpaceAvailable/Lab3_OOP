#include "NgayThangNam.h"
#include <iostream>
#include <vector>

// Định nghĩa các ngày trong tháng
const std::vector<int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/**
 * Default constructor của class NgayThangNam. Khởi tạo ngày 1/1/1970
 */
NgayThangNam::NgayThangNam() : ngay(1), thang(1), nam(1970) {}

/**
 * Constructor của class NgayThangNam. Khởi tạo ngày/tháng/năm từ 3 tham số ngày, tháng, năm, 
 * sau đó kiểm tra xem ngày/tháng/năm có hợp lệ không
 * @param ngay ngày
 * @param thang tháng
 * @param nam năm
 */
NgayThangNam::NgayThangNam(int ngay, int thang, int nam) : ngay(ngay), thang(thang), nam(nam) {
    checkValid();
}

/**
 * Constructor của class NgayThangNam. Khởi tạo ngày/tháng/năm từ số ngày được truyền vào,
 * sau đó kiểm tra xem ngày/tháng/năm có hợp lệ không
 * @param n số ngày
 */
NgayThangNam::NgayThangNam(int n) {
    if (n < 0) {
        throw std::invalid_argument("Cannot convert negative days to date. Maybe you should check your operands when using operator -");
    }

    this->nam = n / 365;
    int days = n % 365;
    int month = 0;
    
    for (int i = 1; i <= 12; ++i) {
        if (days < months[i - 1]) {
            month = i;
            break;
        }
        days -= months[i - 1];
    }

    this->thang = month;
    this->ngay = days;
    this->checkValid();
}

/**
 * Kiểm tra xem ngày/tháng/năm có hợp lệ không
 * Nếu ngày không hợp lệ (ngày < 1 hoặc ngày > số ngày trong tháng) hoặc tháng không hợp lệ (tháng < 1 hoặc tháng > 12)
 * @throw std::invalid_argument nếu ngày/tháng/năm không hợp lệ
 */
void NgayThangNam::checkValid() {
    if (this->thang < 1 || this->thang > 12 || this->ngay < 1 || this->ngay > months[this->thang - 1]) {
        throw std::invalid_argument("Invalid date");
    }
}

/**
 * Tính số ngày từ ngày 1/1 của năm đó đến ngày hiện tại
 * @return số ngày
 */
int NgayThangNam::TinhNgay() const {
    int res = 0;
    for (int i = 0; i < this->thang - 1; ++i) {
        res += months[i];
    }
    res += this->ngay;
    return res;
}

/**
 * Overload operator + để cộng 2 ngày
 * @param n ngày thứ nhất
 * @param m ngày thứ hai
 * @return ngày sau khi cộng
 */
NgayThangNam operator+(const NgayThangNam& n, const NgayThangNam& m) {
    int totalDays = n.TinhNgay() + m.TinhNgay() + (n.nam + m.nam) * 365;
    return NgayThangNam(totalDays);
}

/**
 * Overload operator - để trừ 2 ngày
 * @param n ngày bị trừ
 * @param m ngày trừ đi
 * @return ngày sau khi trừ
 */
NgayThangNam operator-(const NgayThangNam& n, const NgayThangNam& m) {
    int totalDays = n.TinhNgay() - m.TinhNgay() + (n.nam - m.nam) * 365;
    return NgayThangNam(totalDays);
}

/**
 * Overload operator ++ để tăng ngày lên 1
 * @return ngày sau khi tăng
 */
NgayThangNam NgayThangNam::operator++() {
    *this = NgayThangNam(this->nam * 365 + this->TinhNgay() + 1);
    return *this;
}

/**
 * Overload operator -- để giảm ngày đi 1
 * @return ngày sau khi giảm
 */
NgayThangNam NgayThangNam::operator--() {
    *this = NgayThangNam(this->nam * 365 + this->TinhNgay() - 1);
    return *this;
}

/**
 * Overload operator == để so sánh 2 ngày có bằng nhau không
 * @param n ngày thứ nhất
 * @param m ngày thứ hai
 * @return true nếu bằng nhau, ngược lại false
 */
bool operator==(const NgayThangNam& n, const NgayThangNam& m) {
    return n.ngay == m.ngay && n.thang == m.thang && n.nam == m.nam;
}

/**
 * Overload operator != để so sánh 2 ngày có khác nhau không
 * @param n ngày thứ nhất
 * @param m ngày thứ hai
 * @return true nếu khác nhau, ngược lại false
 */
bool operator!=(const NgayThangNam& n, const NgayThangNam& m) {
    return !(n == m);
}

/**
 * Overload operator > để so sánh 2 ngày nào lớn hơn
 * @param n ngày thứ nhất
 * @param m ngày thứ hai
 * @return true nếu n lớn hơn m, ngược lại false
 */
bool operator>(const NgayThangNam& n, const NgayThangNam& m) {
    if (n.nam != m.nam) return n.nam > m.nam;
    if (n.thang != m.thang) return n.thang > m.thang;
    return n.ngay > m.ngay;
}

/**
 * Overload operator >= để so sánh 2 ngày nào lớn hơn hoặc bằng nhau
 * @param n ngày thứ nhất
 * @param m ngày thứ hai
 * @return true nếu n lớn hơn hoặc bằng m, ngược lại false
 */
bool operator>=(const NgayThangNam& n, const NgayThangNam& m) {
    return n > m || n == m;
}

/**
 * Overload operator < để so sánh 2 ngày nào nhỏ hơn
 * @param n ngày thứ nhất
 * @param m ngày thứ hai
 * @return true nếu n nhỏ hơn m, ngược lại false
 */
bool operator<(const NgayThangNam& n, const NgayThangNam& m) {
    return !(n >= m);
}

/**
 * Overload operator <= để so sánh 2 ngày nào nhỏ hơn hoặc bằng nhau
 * @param n ngày thứ nhất
 * @param m ngày thứ hai
 * @return true nếu n nhỏ hơn hoặc bằng m, ngược lại false
 */
bool operator<=(const NgayThangNam& n, const NgayThangNam& m) {
    return !(n > m);
}

/**
 * Overload operator >> để nhập ngày/tháng/năm từ bàn phím theo định dạng dd/mm/yyyy
 * @param is stream đầu vào
 * @param n ngày/tháng/năm cần nhập
 * @return stream đầu vào
 */
std::istream& operator>>(std::istream& is, NgayThangNam& n) {
    char slash;
    is >> n.ngay >> slash >> n.thang >> slash >> n.nam;
    if (slash != '/') {
        throw std::invalid_argument("Invalid date format");
    }
    n.checkValid();
    return is;
}

/**
 * Overload operator << để in ngày/tháng/năm theo định dạng dd/mm/yyyy
 * @param os stream đầu ra
 * @param n ngày/tháng/năm cần in
 * @return stream đầu ra
 */
std::ostream& operator<<(std::ostream& os, const NgayThangNam& n) {
    if (n.ngay < 10) os << "0";
    os << n.ngay << "/";
    if (n.thang < 10) os << "0";
    os << n.thang << "/" << n.nam;
    return os;
}