#include <iostream>
#include <string>
using namespace std;
const string CHARS       = "AHIMOTUVWXY8ELJSZ235";
const string CHARSMIRROR = "AHIMOTUVWXY83JL25SEZ";

int isMirrorChars(char a, char b) {
  if (CHARS.find(a) == CHARSMIRROR.find(b) && CHARS.find(a) < CHARS.size())
    return 1;
  else
    return 0;
}

int main() {
  string str;

  while (cin >> str) {
    int palindrome = 1;
    int mirror = 1;
    int size = str.size();
    
    for (int i = 0; i <= size/2; i++) {
      if (str[i] != str[size-i-1]) {
	palindrome = 0;
	break;
      }
    }
    
    for (int i = 0; i <= size/2; i++) {
      if (!isMirrorChars(str[i], str[size-i-1])) {
	mirror = 0;
	break;
      }
    }

    cout << str;
    if (palindrome && mirror) {
      cout << " -- is a mirrored palindrome." << endl;
    } else if (palindrome) {
      cout << " -- is a regular palindrome." << endl;
    } else if (mirror) {
      cout << " -- is a mirrored string." << endl;
    } else {
      cout << " -- is not a palindrome." << endl;
    }
    cout << endl;
    
  }
  return 0;
}
