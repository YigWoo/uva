#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string dump;
    size_t lc;
    cin >> lc;
    getline(cin, dump);
    for (size_t i = 0; i < lc; i++) {
        string s1, s2, s3, s4, s5;
        string line1, line2, tmp;
        getline(cin, s1, '<');
        getline(cin, s2, '>');
        getline(cin, s3, '<');
        getline(cin, s4, '>');
        getline(cin, s5);
        getline(cin, line2, '.');
        getline(cin, dump);
        tmp = s4 + s3 + s2 + s5;
        line1 = s1 + s2 + s3 + s4 + s5;
        line2 += tmp;
        cout << line1 << endl;
        cout << line2 << endl;
    }
    return 0;
}
