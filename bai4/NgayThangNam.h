#pragma once
#include <iostream>

class NgayThangNam {
    private:
        int ngay, thang, nam;
    public:
        NgayThangNam();
        NgayThangNam(int, int, int);
        NgayThangNam(int);

        void checkValid();
        int TinhNgay() const;

        friend NgayThangNam operator+(const NgayThangNam&, const NgayThangNam&);
        friend NgayThangNam operator-(const NgayThangNam&, const NgayThangNam&);
        NgayThangNam operator++();
        NgayThangNam operator--();

        friend bool operator==(const NgayThangNam&, const NgayThangNam&);
        friend bool operator!=(const NgayThangNam&, const NgayThangNam&);
        friend bool operator>(const NgayThangNam&, const NgayThangNam&);
        friend bool operator>=(const NgayThangNam&, const NgayThangNam&);
        friend bool operator<(const NgayThangNam&, const NgayThangNam&);
        friend bool operator<=(const NgayThangNam&, const NgayThangNam&);

        friend std::istream& operator>>(std::istream&, NgayThangNam&);
        friend std::ostream& operator<<(std::ostream&, const NgayThangNam&);
};