#include <iostream>
#include <cstring>
using namespace std;

int main() {
  char a[110][110];
  int size[100] = {0};
  int i = 0;
  int lines = 0;
  int max = 0;
  while (cin.getline(a[i], 110)) {
    size[i] = strlen(a[i]);
    if (size[i] > max)
      max = size[i];
    lines++;
    i++;
  }

  for (int i = 0; i < max; i++) {
    for (int j = lines-1; j >= 0; j--) {
      if (i > size[j]-1)
	cout << " ";
      else
	cout << a[j][i];
    }
    cout << endl;
  }

  return 0;
}
