#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool read(vector<string>& lines) {
    lines.clear();
    string s;
    for (;;) {
        if (!(getline(cin, s))) return false;
        if (s[0] == '9') return true;
        lines.push_back(s);
    }
}

bool solve(vector<string>& lines) {
    size_t sz = lines.size();
    for (size_t i = 0; i < sz; i++)
        for (size_t j = 0; j < sz; j++)
            if (i != j && lines[i].find(lines[j]) == 0) return false;
    return true;
}

int main() {
    int kase = 0;
    vector<string> lines;
    while (read(lines)) {
        bool flag = solve(lines);
        cout << "Set " << ++kase << " is ";
        if (!flag) cout << "not ";
        cout << "immediately decodable" << endl;
    }
    return 0;
}
