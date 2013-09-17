#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

int main() {
    /* Written according to the thought of Seven World of Steve Halim */
    string line;
    while (getline(cin, line)) {
        long double a, b, c;
        string op;
        cout << line << endl;
        stringstream ss(line);
        ss >> a >> op >> b;
        if (op[0] == '+') c = a + b;
        else c = a * b;
        if (a > 2147483647.00) cout << "first number too big" << endl;
        if (b > 2147483647.00) cout << "second number too big" << endl;
        if (c > 2147483647.00) cout << "result too big" << endl;
    }
    return 0;
}
