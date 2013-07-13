#include<iostream>
#include<string>
using namespace std;
    
int main() {
  int linecount;
  while (cin >> linecount && linecount != 0) {
    int *a = new int[linecount];
    int minimum = 25;
    int totalblank = 0;
    char dump;

    // dump the newline character left by 'cin >> linecount'
    cin.get(dump);

    for (int i = 0; i < linecount; i++)
      a[i] = 0;
    string line;
    for (int i = 0; i < linecount; i++) {
      getline(cin, line);
      //      cout << line << endl;
      for (int j = 0; j < 25; j++) {
	if (line[j] == ' ')
	  a[i]++;
      }
      if (a[i] < minimum)
	minimum = a[i];
    }
    for (int i = 0; i < linecount; i++) {
      totalblank += (a[i] -minimum);
    }
    cout << totalblank << endl;
  }
  return 0;
}
