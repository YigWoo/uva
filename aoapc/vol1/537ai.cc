/* UVa 537 Artifical Intelligence? */
/* It's a mod version from Rujia Liu's code */
/* I like this code, it's elegant in approach and style */
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

bool getVal(string prefix, const string& s, double& val) {
    int pos = s.find(prefix);
    if (pos < 0) return false;
    pos += 2;
    string tmp(s, pos);
    stringstream ss(tmp);
    char unit;
    ss >> val;
    ss >> unit;
    if (unit == 'm') val *= 1e-3;
    else if (unit == 'k') val *= 1e3;
    else if (unit == 'M') val *= 1e6;
    return true;
}

int main() {
    int cc;
    stringstream ss;
    string s;
    getline(cin, s);
    ss.str(s);
    ss >> cc;
    ss.clear();
    for (int kase = 1; kase <= cc; kase++) {
        getline(cin, s);
        cout << "Problem #" << kase << endl;
        double p, i, u;
        bool bp = getVal("P=", s, p);
        bool bi = getVal("I=", s, i);
        bool bu = getVal("U=", s, u);
        cout << setprecision(2) << fixed;
        if (!bp) cout << "P=" << u*i << "W" << endl;
        else if (!bi) cout << "I=" << p/u << "A" << endl;
        else cout << "U=" << p/i << "V" << endl;
        cout << endl;
    }
    return 0;
}
