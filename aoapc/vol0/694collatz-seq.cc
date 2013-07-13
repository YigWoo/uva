#include <iostream>
#include <string>
using namespace std;

int main() {
  long long a, l;
  int count = 0;
  while ((cin >> a >> l) && a > 0 && l > 0) {
    cout << "Case " << count+1 << ": A = " << a;
    count++;
    int terms = 1;

    while (a != 1 && a <= l) {
      if (a % 2 == 0){
	a = a / 2;
      }
      else {
	a = 3 * a + 1;
      }
      if (a <= l)
	terms++;
    }
    cout << ", limit = " << l << ", number of terms = " << terms << endl;
  }
  return 0;
}
