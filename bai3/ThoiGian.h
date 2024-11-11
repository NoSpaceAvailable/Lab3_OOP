#pragma once
#include <iostream>

class ThoiGian {
    private:
        int iGio, iPhut, iGiay;
    public:
        ThoiGian();
        ThoiGian(int, int, int);
        ThoiGian(int);

        void checkValid();
        int TinhGiay() const;
        void TinhLaiGio(int);

        ThoiGian operator++();
        ThoiGian operator--();
        friend ThoiGian operator+(const ThoiGian&, const ThoiGian&);
        friend ThoiGian operator-(const ThoiGian&, const ThoiGian&);
        friend bool operator==(const ThoiGian&, const ThoiGian&);
        friend bool operator!=(const ThoiGian&, const ThoiGian&);
        friend bool operator>(const ThoiGian&, const ThoiGian&);
        friend bool operator<(const ThoiGian&, const ThoiGian&);
        friend bool operator>=(const ThoiGian&, const ThoiGian&);
        friend bool operator<=(const ThoiGian&, const ThoiGian&);

        friend std::istream& operator>>(std::istream&, ThoiGian&);
        friend std::ostream& operator<<(std::ostream&, const ThoiGian&);
};