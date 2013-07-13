#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  long long hashNum, eNum;
  while (cin >> hashNum >> eNum) {
    cout << abs(eNum - hashNum) << endl;
  }
  return 0;
}
