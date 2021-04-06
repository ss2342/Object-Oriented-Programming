///*
//	testRational.cpp
//	CS2124
//	Implement the class Rational, so that the following program works.
// */
//
#include <iostream>
#include <string>
#include <vector>

// If time allows use separate compilation, otherwise just define the
// class below
//#include "Rational.h"

using namespace std;

class Rational {
public:

    friend ostream& operator<<(ostream& os, const Rational& rhs);

    friend istream& operator>>(istream& is, Rational& rhs) {
        char character;
        is >> rhs.numerator >> character >> rhs.denominator;
        rhs.normalize();
        return is;
    }

    Rational(int numerator = 0, int denominator = 1);

    Rational operator+=(const Rational& rhs) {
        numerator *= rhs.denominator;
        numerator += (rhs.numerator * denominator);
        denominator *= rhs.denominator;
        normalize();
        return *this;
    }

    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend bool operator<(const Rational& lhs, const Rational& rhs);

    Rational operator ++() {
        numerator += denominator;
        return *this;
    }

    Rational operator++(int post) {
        Rational original(*this);
        numerator += denominator;
        return original;
    }

    operator bool() const;
//    Rational operator bool() const {
//
//    }





private:
    int numerator;
    int gcd(int x, int y);
    int denominator;

    bool wholeNumber;

    void normalize();

};

ostream& operator<<(ostream& os, const Rational& rhs) {

    if (rhs.wholeNumber) {
        os << rhs.numerator;
    }
    else {
        os << rhs.numerator << '/' << rhs.denominator << endl;
    }
    return os;

}

void Rational::normalize() {
    int greatestCommonDivisor = gcd(numerator, denominator);
    numerator /= greatestCommonDivisor;
    denominator /= greatestCommonDivisor;
    if (denominator == 1) {
        wholeNumber = true;
    }
    else {
        wholeNumber = false;
    }
    if (numerator < 0 && denominator < 0) {
        numerator = abs(numerator);
        denominator = abs(denominator);
    }

}

int Rational::gcd(int x, int y) {
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

Rational::Rational(int numer, int denom) {
    numerator = numer;
    denominator = denom;
    normalize();


}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational totalSum = lhs;
    totalSum += rhs;
    return totalSum;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return (lhs.numerator * rhs.denominator) < (rhs.numerator * lhs.denominator);
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
    return (lhs < rhs || lhs == rhs);
}

bool operator>(const Rational& lhs, const Rational& rhs) {
    return !(lhs <= rhs);
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
    return (lhs > rhs || lhs == rhs);
}

Rational& operator--(Rational& rhs) {
    rhs += -1;
    return rhs;
}

Rational operator--(Rational& rhs, int dummy) {
    Rational original(rhs);
    rhs += -1;
    return original;

}

Rational::operator bool() const {
    return numerator != 0;
}
//
//}
//
//
//
//}


// If time allows after implementing separate compilation, then wrap
// the class in a namespace.
//using namespace CS2124;

int main() {
    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    const Rational one = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;	// Implement as member
    cout << "a = " << a << endl;
////
////    // Implement as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;
//
//    // How does this manage to work?
//    // It does NOT require writing another == operator.
//    cout << "1 == one: " << boolalpha << (1 == one) << endl;
//
//    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;
//
    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;
//
    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;
//
//    // Even though the above example, (a++ ++), compiled, the
//    // following shouldn't.
//    // But some compiler vendors might let it...  Is your compiler
//    // doing the right thing?
//    cout << "a-- -- = " << (a-- --) << endl;
    cout << "a = " << a << endl;
//
//
//    // Should report that 1 is true
    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    }

    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    }

    cout << "Comparisons\n";
    Rational twoFifths(2, 5);
    Rational threeHalves(3, 2);
    Rational minusFive(-5);
    cout << twoFifths << " < " << threeHalves << " : "
         << (twoFifths < threeHalves) << endl;
    //cout << twoFifths << " <= " << 1 << " : " << (twoFifths <= 1) << endl;
    cout << threeHalves << " < " << twoFifths << " : "
         << (threeHalves < twoFifths) << endl;
    cout << threeHalves << " > " << threeHalves << " : "
         << (threeHalves > threeHalves) << endl;
    cout << threeHalves << " >= " << threeHalves << " : "
         << (threeHalves >= threeHalves) << endl;
    cout << minusFive << " >= " << threeHalves << " : "
         << (minusFive >= threeHalves) << endl;
}
