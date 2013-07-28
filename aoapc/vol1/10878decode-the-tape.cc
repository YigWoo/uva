#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    string tapeline;
    while (getline(cin, tapeline)) {
	if (tapeline[0] == '_') continue;
	char c = 0;
        if (tapeline[2] == 'o') c += 64;
        if (tapeline[3] == 'o') c += 32;
        if (tapeline[4] == 'o') c += 16;
        if (tapeline[5] == 'o') c += 8;
        if (tapeline[7] == 'o') c += 4;
        if (tapeline[8] == 'o') c += 2;
        if (tapeline[9] == 'o') c += 1;
        cout << c << flush;
    }
    return 0;
}
