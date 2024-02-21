#include <iostream>
using namespace std;
class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}
    void display() const {
        cout << numerator << "/" << denominator;
    }

    Fraction operator+(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    Fraction operator-(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    Fraction operator*(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    Fraction operator/(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        return result;
    }
};

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    void display() const {
       cout << real << " + " << imag << "i";
    }
    Complex operator+(const Complex& other) const {
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }
    Complex operator-(const Complex& other) const {
        Complex result;
        result.real = real - other.real;
        result.imag = imag - other.imag;
        return result;
    }

    Complex operator*(const Complex& other) const {
        Complex result;
        result.real = real * other.real - imag * other.imag;
        result.imag = real * other.imag + imag * other.real;
        return result;
    }

    Complex operator/(const Complex& other) const {
        Complex result;
        double divisor = other.real * other.real + other.imag * other.imag;
        result.real = (real * other.real + imag * other.imag) / divisor;
        result.imag = (imag * other.real - real * other.imag) / divisor;
        return result;
    }
};

int main() {
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction sum = a + b;
    Fraction diff = a - b;
    Fraction prod = a * b;
    Fraction quot = a / b;

    cout << "Fractions:\n";
    cout << "Sum: ";
    sum.display();
    cout << endl;
    cout << "Difference: ";
    diff.display();
    cout << endl;
    cout << "Product: ";
    prod.display();
    cout << endl;
    cout << "Quotient: ";
    quot.display();
    cout << endl;

    Complex c1(1.0, 2.0);
    Complex c2(2.0, 3.0);

    Complex sum_c = c1 + c2;
    Complex diff_c = c1 - c2;
    Complex prod_c = c1 * c2;
    Complex quot_c = c1 / c2;

    cout << "\nComplex Numbers:\n";
    cout << "Sum: ";
    sum_c.display();
    cout << endl;

    cout << "Difference: ";
    diff_c.display();
    cout << endl;

    cout << "Product: ";
    prod_c.display();
    cout << endl;

    cout << "Quotient: ";
    quot_c.display();
    cout << endl;

    return 0;
}
