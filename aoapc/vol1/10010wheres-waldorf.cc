#include <iostream>
#include <string>
#include <cctype>	      
#include <vector>
#include <ctime>
using namespace std;

enum Direction{N, NE, E, SE, S, SW, W, NW};
string str2lower(const string &tmp) {
    string res(tmp);
    for (size_t l = 0; l != tmp.size(); l++)
	if (isupper(tmp[l]))
	    res[l] = tolower(tmp[l]);
    return res;
}
bool searchWaldorf(const vector<string>& a,
                   const string& word, string prefix,
                   int k, int l, int d, Direction direction) {
    int row, col;
    row = a.size();
    col = a[0].size();
    if (k < 0 || l < 0 || k >= row || l >= col) return false;
    if (d >= word.size()) return false;
    if (word[d] != a[k][l]) return false;
    /* cout << prefix << " ";  */
    if (d == word.size() - 1) return word[d] == a[k][l];
    prefix = prefix + a[k][l];
    if (direction == N) l--;
    if (direction == NE) {l--; k++;}
    if (direction == E) k++;
    if (direction == SE) {l++; k++;}
    if (direction == S) l++;
    if (direction == SW) {l++; k--;}
    if (direction == W) k--;
    if (direction == NW) {k--; l--;}
    return searchWaldorf(a, word, prefix, k, l, d+1, direction);
}

int main() {
    /* clock_t t; */
    /* t = clock(); */
    unsigned int cc;
    cin >> cc;

    for (unsigned int i = 0; i < cc; i++) {
	int row, col, wc, maxlen;
	string dump, tmp;
	vector<string> a;
        vector<string> words;
	
	cin >> row >> col;
	getline(cin, dump);
	for (int j = 0; j < row; j++) {
	    getline(cin, tmp);
	    tmp = str2lower(tmp);
	    a.push_back(tmp);
	}
        /* for (vector<string>::const_iterator it = a.begin();  */
	/*      it != a.end(); it++) { */
	/*     cout << *it << endl; */
	/* } */
        cin >> wc;
        maxlen = 0;
        getline(cin, dump);
        for (int j = 0; j < wc; j++) {
            getline(cin, tmp);
            tmp = str2lower(tmp);
            words.push_back(tmp);
            if (tmp.size() > maxlen)
                maxlen = tmp.size();
        }
        /* for (vector<string>::iterator it = words.begin(); it != words.end(); it++) */
        /*     cout << *it << endl; */
        for (vector<string>::iterator it = words.begin(); it != words.end(); it++) {
            for (int k = 0; k < row; k++) {
                bool flag = false;
                for (int l = 0; l < col; l++) {
                    string tmp("");
                    flag |= searchWaldorf(a, *it, tmp, k, l, 0, N);
                    flag |= searchWaldorf(a, *it, tmp, k, l, 0, NE);
                    flag |= searchWaldorf(a, *it, tmp, k, l, 0, E);
                    flag |= searchWaldorf(a, *it, tmp, k, l, 0, SE);
                    flag |= searchWaldorf(a, *it, tmp, k, l, 0, S);
                    flag |= searchWaldorf(a, *it, tmp, k, l, 0, SW);
                    flag |= searchWaldorf(a, *it, tmp, k, l, 0, W);
                    flag |= searchWaldorf(a, *it, tmp, k, l, 0, NW);
                    if (flag) {
                        cout << k+1 << " " << l+1 << endl;
                        break;
                    }
                }
                if (flag) break;
            }
        }
        if (i != cc -1)
            cout << endl;
    }
    /* t = clock() - t; */
    /* cout << "time:clocks  " << (double)t/CLOCKS_PER_SEC; */
    /* cout << ":"  << (int)clock() << endl; */
    return 0;
}
