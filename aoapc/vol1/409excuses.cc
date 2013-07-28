#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

string nextword(istream& in) {
    bool flag = false;
    char c;
    string res;
    while ((c = in.get()) != EOF) {
	if (isalpha(c)) {
	    if (!flag) flag = true;
	    if (isupper(c)) c = tolower(c);
	    res += c;
	} else {
	    if (flag) break;
	}
    }
    return res;
}

int main() {
    int i = 0;
    while (!cin.eof()) {
	cout << "Excuse Set #" << ++i << endl;
	int K, E;
	cin >> K >> E;
	string dump;
	getline(cin, dump);
	vector<string> keywords;
	for (int i = 0; i < K; i++) {
	    string kw;
	    getline(cin, kw);
	    keywords.push_back(kw);
	}
	int max = 0;
	map<string,int> excusePtMap;
	for (int i = 0; i < E; i++) {
	    string excuse;
	    int point = 0;
	    getline(cin, excuse);
	    /* cout << excuse << endl; */
	    istringstream sstr(excuse);
	    while (!sstr.eof()) {
		string word = nextword(sstr);
		if ((find(keywords.begin(), keywords.end(), word)) != keywords.end()) point++;
	    }
	    excusePtMap[excuse] = point;
	    if (point > max) max = point;
	}
	
	for (map<string,int>::iterator it = excusePtMap.begin();
	     it != excusePtMap.end();
	     it++) {
	    if (it->second == max)
		cout << it->first << endl;
	}
	cout << endl;
    }
    return 0;
}
