#pragma once
#include <iostream>

class PhanSo {
    private:
        int iTu, iMau;
    public:
        void RutGon();
        void checkValid();
        PhanSo();
        PhanSo(int, int);
        PhanSo(float);

        friend PhanSo operator+(const PhanSo&, const PhanSo&);
        friend PhanSo operator-(const PhanSo&, const PhanSo&);
        friend PhanSo operator*(const PhanSo&, const PhanSo&);
        friend PhanSo operator/(const PhanSo&, const PhanSo&);

        friend bool operator==(const PhanSo&, const PhanSo&);
        friend bool operator!=(const PhanSo&, const PhanSo&);
        friend bool operator>(const PhanSo&, const PhanSo&);
        friend bool operator<(const PhanSo&, const PhanSo&);
        friend bool operator>=(const PhanSo&, const PhanSo&);
        friend bool operator<=(const PhanSo&, const PhanSo&);

        friend std::istream& operator>>(std::istream&, PhanSo&);
        friend std::ostream& operator<<(std::ostream&, const PhanSo&);
};