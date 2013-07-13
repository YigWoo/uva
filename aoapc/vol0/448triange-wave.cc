#include <iostream>
#include <string>
using namespace std;

int main() {
  int count;
  int height, freq;
  
  cin >> count;
  for (int i = 0; i < count; i++) {
    cin >> height >> freq;
    for (int j = 0; j < freq; j++) {
      for (int k = 0; k < height; k++) {
	for (int l = 1; l <= k+1; l++) {
	  cout << k+1;
	}
	cout << endl;
      }
      for (int k = height-1; k > 0; k--) {
	for (int l = 0; l < k; l++) {
	  cout << k;
	}
	cout << endl;
      }
      if (i != (count-1) || j != (freq-1))
	cout << endl;
    }
  }
  return 0;
}
