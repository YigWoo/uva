#include <iostream>

using namespace std;

int main() {
  int cases, farmers, premium;
  int a, b, c;

  cin >> cases;
  for (int i=0; i<cases; i++) {
    premium = 0;
    cin >> farmers;
    for (int j=0; j<farmers; j++) {
      cin >> a >> b >> c;
      premium += a * c;
    }
    cout << premium << endl;
  }
}

