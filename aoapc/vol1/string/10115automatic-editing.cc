#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int rulesCnt;
    while (cin >> rulesCnt && rulesCnt != 0) {
	string dump;
	getline(cin, dump);
	vector<string> find;
	vector<string> replace;
	for (int i = 0; i < rulesCnt; i++) {
	    string rule;
	    getline(cin, rule);
	    find.push_back(rule);
	    getline(cin, rule);
	    replace.push_back(rule);
	}
	string lineToEdit;
	getline(cin, lineToEdit);
	for (int i = 0; i < rulesCnt; i++) {
	    size_t pos;
	    while ((pos = lineToEdit.find(find[i])) != string::npos) {
		size_t len = find[i].size();
		lineToEdit.replace(pos, len, replace[i]);
	    }
	}
	cout << lineToEdit << endl;
	
    }
    return 0;
}
