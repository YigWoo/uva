#include <iostream>
#include <string>
#include "BigInt.h"

using namespace std;

int main() {
    BigInt bi(-10000);
    for (int i = 0; i < 5; i++)
        cout << bi.magnitude[i];
    cout << bi.sign << endl;
    BigInt bbc("-10000000000000000");
    cout << bbc.len << endl;
    for (int i = 0; i < 17; i++)
        cout << bbc.magnitude[i];
    cout << bbc.sign << endl;
    
    string str("-100000");
    BigInt bs(str);
    for (int i = 0; i < 6; i++)
        cout << bs.magnitude[i];
    cout << endl;
    BigInt bc(bs);
    for (int i = 0; i < 6; i++)
        cout << bc.magnitude[i];
    cout << endl;

    cout << bbc << endl;
         /* << bbc << endl */
    cout << "This is bs: " << bs << endl;
    cout << "This is bbc: " << bbc << endl;
    cout << "After bs = bbc" << endl;
    bs = bbc;
    cout << "bs after assignment: " << bs << endl;

    BigInt zero(0);
    cout << zero << endl;
    return 0;
}
