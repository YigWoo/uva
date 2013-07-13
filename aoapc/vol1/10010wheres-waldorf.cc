#include <iostream>
#include <string>
#include <cctype>	      
#include <bitset>
#include <vector>
#include <ctime>
using namespace std;

void str2lower(string &tmp) {
  for (size_t l = 0; l != tmp.size(); l++)
    if (isupper(tmp[l]))
      tmp[l] = tolower(tmp[l]);
}

int main() {
  clock_t t;
  t = clock();
  int cc;
  cin >> cc;

  for (int i = 0; i < cc; i++) {
    int row, col, wc, maxsize;
    string dump, tmp;
    vector<int> posofwords;
    vector<string> words;
    vector<string> a;
    bitset<20> bitvec;

    cin >> row >> col;
    getline(cin, dump);
    for (int k = 0; k < row; k++) {
      getline(cin, tmp);
      str2lower(tmp);
      a.push_back(tmp);
    }
    // for (vector<string>::const_iterator it = a.begin();
    // 	 it != a.end(); it++) {
    //   cout << *it << endl;
    // }
    cin >> wc;
    getline(cin, dump);
    maxsize = 0;
    for (int k = 0; k < wc; k++) {
      cin >> tmp;
      str2lower(tmp);
      words.push_back(tmp);
      bitvec.set(k);
      if (tmp.size() > maxsize)
	maxsize = tmp.size();
    }
    // cout << maxsize << ":" << bitvec << endl;
    // for (vector<string>::const_iterator it = words.begin();
    //  	 it != words.end(); it++) {
    //   cout << *it << endl;
    //  }

    // for (int k = 0; k < row; k++) {
    //   for (int l = 0; l < col; l++) {
    // 	int tmpi = k;
    // 	int tmpj = l;
    // 	if (isupper(a[k][l]))
    // 	  a[k][l] = tolower(a[k][l]);
    // 	// go east
    // 	for (int m = 0; m < maxsize; m++) {
    // 	  if (tmpj < col) {
    // 	    for (int n = 0; n < wc; n++) {
    // 	      if (m < words[n].size()) {
    // 		if (
    // 	      }
    // 	    }
    // 	  }
    // 	}
    //   }
    // }
  }


  t = clock() - t;
  cout << "time:clocks  " << (double)t/CLOCKS_PER_SEC;
  cout << ":"  << (int)clock() << endl;
  return 0;
}
