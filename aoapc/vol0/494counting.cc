#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
  string line, word;
  while(getline(cin, line)) {
    int flag = 0;
    int count = 0;
    char c;
    istringstream stream(line);
    while (stream.get(c)) {
      if (flag == 0) {
	if (isalpha(c)) {
	   count++;
	   flag = 1;
	}
      }
      else if (flag == 1) {
	if (!isalpha(c))
          flag = 0;
      }
    }
    if(count != 0)
      cout << count << endl;
  }
  return 0;
}
