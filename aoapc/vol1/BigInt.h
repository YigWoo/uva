/* BigInt class is used to represent big integer numbers in c++.
 * About implementing the class:
 *   1. data type used to hold the integer value.
 *      at first I tried to use string representation, but found it
 *      tedious
 *   2. choosing whether to use int vector or int array, it seems using
 *      vector is way slower than using array
 *   3. don't use `using namespace std;` directive
 *   4. using an int array, you got a problem of maximum size, don't use
 *      a size that is too big
 */

#include <iostream>
#include <string>
#include <cstddef>
#ifndef BIGINT_H
#define BIGINT_H

class BigInt {
  public: // for test use
    /* using string form representation is a tedious job */
    /* since pointer is used, you should write you own */
    /* copy ctor, assignment operator and dtor */
    int *magnitude;
    enum SIGN { NEGATIVE = -1, ZERO, POSITIVE };
    SIGN sign;
    std::size_t len;
  public:
    std::size_t length() const {return len;}
    BigInt();
    ~BigInt();
    BigInt(int i);
    BigInt(std::string str);
    BigInt(const char *cs);
    BigInt(const BigInt &bi);
    friend void swap(BigInt &first, BigInt &second);
    BigInt& operator= (const BigInt bi); // important if class has pointers.
    /* friend bool operator== (const BigInt& lhs, const BigInt& rhs); */
    /* friend bool operator< (const BigInt& lhs, const BigInt& rhs); */
    /* friend std::istream& operator>> (std::istream& in, BigInt& bi); */
    friend std::ostream& operator<< (std::ostream &out, const BigInt &bi);
    friend const BigInt operator+ (const BigInt &lhs, const BigInt &rhs);
    BigInt  operator+ (const BigInt& rhs);
    BigInt  operator++(int);
    BigInt& operator++();
    BigInt& operator+= (const BigInt& rhs);
    BigInt& add(const BigInt& rhs);
    /* Still thinking over whether the following two ctors should be */
    /* declared `explicit`. */
    /* Generally speaking, you shouldn't declare ctor of number-like */
    /* classes explicit, cause' you want to support operations like: */
    /* 2 + ClassObj; ClassObj - 2; */
    /* and you want to allow implicit class type conversion. */
    
    /* BigInt& operator--(); */
    /* BigInt  operator--(int); */
    /* BigInt& operator-= (const BigInt& rhs); */
    /* BigInt& operator*= (const BigInt& rhs); */
    /* BigInt& operator/= (const BigInt& rhs); */
    /* BigInt& operator%= (const BigInt& rhs); */

    /* bool less(const BigInt& rhs); */
    /* bool lessOrEqual(const BigInt& rhs); */
    /* bool great(const BigInt& rhs); */
    /* bool greatOrEqual(const BigInt& rhs); */
    /* bool equal(const BigInt& rhs); */
    
    /* BigInt& subtract(const BigInt& rhs); */
    /* BigInt& multiply(const BigInt& rhs); */
    /* BigInt& divide(const BigInt& rhs); */
    /* BigInt& mod(const BigInt& rhs); */
    

  private:
    unsigned int countDigit(int i);
    SIGN verifySign(int i);
    BigInt(int ia[]);
};
BigInt addition(int *lMagnitude, int *rMagnitude);
BigInt subtraction(int *lMagnitude, int *rMagnitude);
int compareMagnitude(int *lMagnitude, int *rMagnitude);

/* BigInt operator- (const BigInt& lhs, const BigInt& rhs); */
/* BigInt operator* (const BigInt& lhs, const BigInt& rhs); */
/* BigInt operator/ (const BigInt& lhs, const BigInt& rhs); */
/* BigInt operator% (const BigInt& lhs, const BigInt& rhs); */

/* bool operator<= (const BigInt& lhs, const BigInt& rhs); */
/* bool operator> (const BigInt& lhs, const BigInt& rhs); */
/* bool operator>= (const BigInt& lhs, const BigInt& rhs); */
/* bool operator!= (const BigInt& lhs, const BigInt& rhs); */
#endif
