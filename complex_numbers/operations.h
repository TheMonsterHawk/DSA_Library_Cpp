#include <iostream>

#ifndef complex_number
#include "complex_number.h"
#endif // complex_number

complex_number::complex_number(){
    this->real = 0;
    this->imag = 0;
}

complex_number::complex_number(int a, int b){
    this->real = a;
    this->imag = b;
}

complex_number complex_number::operator+(const complex_number other) const {
    complex_number result;
    int a = other.imag + this->imag;
    int b = other.real + this->real;
    result.imag = a;
    result.real = b;
    return result;
}

complex_number complex_number::operator-(const complex_number other) const {
    complex_number result;
    int a = this->real - other.real;
    int b = this->imag - other.imag;
    result.real = a;
    result.imag = b;
    return result;
}

complex_number complex_number::operator*(const complex_number other) const {
    complex_number result;
    int a = (this->real*other.real) - (this->imag*other.imag);
    int b = (this->real*other.imag) + (this->imag*other.real);
    result.real = a;
    result.imag = b;
    return result;
}

complex_number complex_number::operator/(const complex_number other) const {
    complex_number result;
    if(other.real == other.imag){
        result.real = 0;
        result.imag = 0;
    } else {
        result = *this * complex_number(other.real, -other.imag);
        result.real /= (other.real*other.real - other.imag*other.imag);
        result.real /= (other.real*other.real - other.imag*other.imag);
    }

    return result;
}

int complex_number::get_imag(){
    return this->imag;
}

int complex_number::get_real(){
    return this->real;
}


std::ostream& operator<<(std::ostream &out, const complex_number &a){
    std::cout << a.real << "+" << a.imag << "i";
    return out;
}






