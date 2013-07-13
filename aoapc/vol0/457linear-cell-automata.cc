#include <iostream>
#include <string>
using namespace std;

int main() {
  char den[5] = " .xW";
  int count;
  cin >> count;

  for (int i = 0; i < count; i++) {
    int dna[10];
    int bact[40] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    for (int j = 0; j < 10; j++)
      cin >> dna[j];
    cout << "                   .                    " << endl;
    int prev, temp, next;
    for (int j = 0; j < 49; j++) {
      for (int k = 0; k < 40; k++) {
	temp = bact[k];
	if (k == 0)
	  prev = 0;

	if (k == 39)
	  next = 0;
	else
	  next = bact[k+1];

	bact[k] = dna[bact[k] + prev + next];
	prev = temp;
	cout << den[bact[k]];
      }
      cout << endl;
    }
    if (i != count - 1)
      cout << endl;
  }
  return 0;
}
