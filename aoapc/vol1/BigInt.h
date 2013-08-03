#include <iostream>

#ifndef BIGINT_H
#define BIGINT_H
using std::string;
class BigInt {
    friend bool operator== (const BigInt& bi1, const BigInt& bi2);
    friend std::ostream& operator<< (std::ostream& out, const BigInt& bi);
    friend std::istream& operator>> (std::istream& in, BigInt& bi);
  public:
    BigInt();
    BigInt(int i);
    BigInt(string s);
    ~BigInt();
    
    
  private:
    string::size_t length;
    string s;
}
#endif
