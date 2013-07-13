#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
  int digit = 0;
  char c;
  while (cin.get(c)) {
      if (isdigit(c)) {
	digit += c - '0';
      }
      else if (isupper(c) || c == '*' || c == 'b') {
	if (digit != 0) {
	  for (int i = 0; i < digit; i++) {
	    c == 'b' ? cout << ' ' : cout << c;
	  }
	  digit = 0;
	}
	else {
	  c == 'b' ? cout << ' ' : cout << c;
	}
      }
      else if (c == '!' || c == '\n') {
	cout << endl;
      }	
  }
  return 0;
}
