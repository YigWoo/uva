#include <iostream>
#include <cstring>
#include <algorithm>
#include "BigInt.h"

std::ostream& operator<< (std::ostream &out, const BigInt &bi) {
    out << "BigInt: ";
    if (bi.sign == BigInt::NEGATIVE) out << "-";
    for (int i = bi.len-1; i >= 0; i--) {
        out << bi.magnitude[i];
    }
    return out;
}

unsigned int BigInt::countDigit(int i) {
    if (i < 0) i = -i;
    unsigned int res = 0;
    if (i == 0) res = 1;
    else {
        while (i != 0) {
            i /= 10;
            res++;
        }
    }
    return res;
}

BigInt::SIGN BigInt::verifySign(int i) {
    if (i == 0) return ZERO;
    else if (i > 0) return POSITIVE;
    else return NEGATIVE;
}

BigInt::BigInt()
    :magnitude(new int[1]),len(1),sign(ZERO) {
    magnitude[0] = 0;
}

BigInt::BigInt(int i)
    :magnitude(new int[countDigit(i)])
    ,len(countDigit(i)),sign(verifySign(i)) {
    if (i < 0) i = -i;
    int digits = countDigit(i);
    for (int j = 0; j < digits; j++) {
        magnitude[j] = i % 10;
        i = i/10;
    }
}

BigInt::BigInt(int ia[]) {
    std::size_t size = sizeof(ia) / sizeof(int);
    for (std::size_t i = 0; i < size; i++) {
        magnitude[i] = ia[i];
    }
    len = size;
    sign = POSITIVE; // fake init..
}

BigInt::BigInt(const char *cs) {
    unsigned int digit = (unsigned) strlen(cs);
    if (digit == 0) {
        *this = BigInt();
    } else {
        int signFlag = 0;
        if (cs[0] == '-' || cs[0] == '+') {
            signFlag = 1;
        }
        len = digit - signFlag;
        magnitude = new int[len];
        for (int i = 0; digit > signFlag; digit--, i++) {
            magnitude[i] = cs[digit-1] - '0';
        }
        if (signFlag && cs[0] == '-') sign = NEGATIVE;
        else sign = POSITIVE;
    }
}

BigInt::BigInt(std::string str) {
    char *cstr = new char[str.length() + 1];
    std::strcpy(cstr, str.c_str());
    *this = BigInt(cstr); // write you own assignment operator
}

BigInt::BigInt(const BigInt &bi) {
    magnitude = new int[bi.len];
    for (int i = 0; i < bi.len; i++) {
        magnitude[i] = bi.magnitude[i];
    }
    len = bi.len;
    sign = bi.sign;
}

BigInt& BigInt::operator= (BigInt bi) {
    /* using copy and swap idiom */
    swap(*this, bi);
    return *this;
}

void swap(BigInt &first, BigInt &second) {
    using std::swap;
    swap(first.sign, second.sign);
    swap(first.magnitude, second.magnitude);
    swap(first.len, second.len);
}

BigInt::~BigInt() { delete[] magnitude;}

BigInt BigInt::operator+ (const BigInt &rhs) {
    BigInt sum;
    if (this->sign == ZERO || rhs.sign == ZERO) {
        if (this->sign == ZERO) sum = rhs;
        else sum = *this;
    } else {
        if (this->sign == rhs.sign) {
            sum = addition(this->magnitude, rhs.magnitude);
            sum.sign = this->sign;
        } else {
            int cmp = compareMagnitude(this->magnitude, rhs.magnitude);
            if (cmp == 0) sum = BigInt(0);
            else if (cmp > 0) {
                sum = subtraction(this->magnitude, rhs.magnitude);
                sum.sign = this->sign;
            } else {
                sum = subtraction(rhs.magnitude, this->magnitude);
                sum.sign = rhs.sign;
            }
        }
    }
    return sum;
}

BigInt addition(int *lMagnitude, int *rMagnitude) {
}

BigInt subtraction(int *lMagnitude, int *rMagnitude) {
}

int compareMagnitude(int *lMagnitude, int *rMagnitude) {
}

