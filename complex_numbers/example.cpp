#include <bits/stdc++.h>
#include "operations.h"

int main(){
    complex_number a(1, 1), b(2, 1);
    complex_number c = a + b;
    complex_number d = a - b;
    complex_number e = a * b;
    complex_number f = a / b;

    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
}
