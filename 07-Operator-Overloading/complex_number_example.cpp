#include <iostream>

namespace test {

    class Complex {
        private:
            double re;
            double im;
        
        public:
            Complex() : Complex(0.0, 0.0) {}
            Complex(double re, double im) : re {re}, im {im} {}
            Complex(const Complex& source) {
                std::cout << "Copy constructor called.\n";
                this->re = source.re;
                this->im = source.im;
            }

            ~Complex() {}

            inline double getRe() const { return this->re; }
            inline double getIm() const { return this->im; }

            // Overloading assignment operator:
            inline const Complex &operator=(const Complex &src) {
                std::cout << "Assignment operator called.\n";
                this->re = src.re;
                this->im = src.im;
                
                return *this;
            }
    };

    // Addition operator overloading: (adding two complex numbers)
    inline const Complex operator+(const Complex &src1, const Complex &src2) {
        return Complex { src1.getRe() + src2.getRe(), 
                         src1.getIm() + src2.getIm() };
    }

    // Addition operator overloading: (adding a real number to a complex number)
    inline const Complex operator+(const Complex &src, double num) {
        return Complex { src.getRe() + num, src.getIm() };
    }

    // Addition operator overloading: (adding a real number to a complex number)
    inline const Complex operator+(double num, const Complex &src) {
        return Complex { src.getRe() + num, src.getIm() };
    }

    // Overloading equals sign operator:
    inline bool operator==(const Complex &src1, const Complex &src2) {
        return src1.getRe() == src2.getRe() && src1.getIm() == src2.getIm();
    }

    // Overloading not equals sign operator:
    inline bool operator!=(const Complex &src1, const Complex &src2) {
        return src1.getRe() != src2.getRe() || src1.getIm() != src2.getIm();
    }

    // Overloading dereferencing operator:
    inline Complex operator*(const Complex &src) {
        return {src.getRe(), -src.getIm()};
    }
    
    // Stream extraction operator overloading:
    std::ostream &operator<<(std::ostream &out, const Complex &obj) {
        out << "z = " << obj.getRe() 
                      << (obj.getIm() < 0 ? " - j" : " + j") 
                      << (obj.getIm() < 0 ? -obj.getIm() : obj.getIm()) << '\n';
        
        return out;
    }

} // namespace

int main() {
    std::cout << std::boolalpha;

    // Copy & assignment tests:
    test::Complex z1 {2, -5};
    test::Complex z2 = z1; // Copy constructor
    test::Complex z3;
    z3 = z1; // Assignment operator

    std::cout << z1;

    // Addition tests:
    test::Complex test1 {3, 4};
    test::Complex test2 {-2, -1};
    std::cout << test1 + test2;

    test::Complex test3 = test1 + 5;
    std::cout << test3;

    std::cout << 4.7 + z1;

    // Equality tests:
    // Paranthesis are needed because the compiler complains about the 
    // operator precedence (stating that << has higher priority than ==).
    std::cout << (z1 == z2) << '\n';
    std::cout << (test1 == test3) << '\n';
    std::cout << (test::Complex {2, -5} == z1) << '\n';

    // Complex conjugate tests:
    test::Complex z4 {2, 3};
    test::Complex z5 {-5, -5};
    
    std::cout << "z4 is " << z4;
    std::cout << "z4* is " << *z4;
    
    std::cout << "z5 is " << z5;
    std::cout << "z5* is " << *z5;
    
    return 0;
}
