#include <iostream>
#include <string>
using namespace std;

int main() {
  string instr;
  while (cin >> instr) {
    string outstr;
    int size;
    size = instr.size();
    for (int i=0; i<size; i++) {
      outstr += (instr[i] - 7);
    }
    cout << outstr << endl;
  }
}
