#include <iostream>
using namespace std;



class complex_number{
private:
    int real, imag;
public:

    complex_number();
    complex_number(int a, int b);

    complex_number operator+(const complex_number other) const;
    complex_number operator-(const complex_number other) const;
    complex_number operator*(const complex_number other) const;
    complex_number operator/(const complex_number other) const;


    int get_imag();
    int get_real();


    friend std::ostream& operator<<(std::ostream &out, const complex_number &a);
    friend std::istream& operator>>(std::istream &in, Set &set);
};

