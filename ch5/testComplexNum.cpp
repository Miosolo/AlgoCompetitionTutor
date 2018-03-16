#include <iostream>
#include <algorithm>
using namespace std;

class Complex {
    public:
        Complex(double a = 0, double b = 0) : real(a), imag(b){}
        Complex operator+(Complex &c2)
        {
            Complex c;
            c.real = this->real + c2.real;
            c.imag = this->imag + c2.imag;

            return c;
        }

        double real;
        double imag;
};

int main(void)
{
    Complex c1(1, 1), c2(-1, 5);

    cout << (c1 + c2).real << " + " << (c1 + c2).imag <<"i" << endl;

    return 0;
}