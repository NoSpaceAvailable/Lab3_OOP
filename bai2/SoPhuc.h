#pragma once
#include <iostream>

class SoPhuc {
    private:
        float dThuc, dAo;
    public:
    SoPhuc();
    SoPhuc(float, float);
    SoPhuc(float);

    friend SoPhuc operator+(const SoPhuc&, const SoPhuc&);
    friend SoPhuc operator-(const SoPhuc&, const SoPhuc&);
    friend SoPhuc operator*(const SoPhuc&, const SoPhuc&);
    friend SoPhuc operator/(const SoPhuc&, const SoPhuc&);

    friend bool operator==(const SoPhuc&, const SoPhuc&);
    friend bool operator!=(const SoPhuc&, const SoPhuc&);

    friend std::istream& operator>>(std::istream&, SoPhuc&);
    friend std::ostream& operator<<(std::ostream&, const SoPhuc&);
};