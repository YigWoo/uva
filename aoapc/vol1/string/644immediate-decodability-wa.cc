#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int kase = 0;
    /* codes that causes wrong answer begins here */
    /* it should be the get input process that cause the WA. */
    while (!cin.eof()) {
	string line;
	vector<string> lines;
	while (getline(cin, line) && line[0] != '9') {
	    lines.push_back(line);
	}
        /* codes that cause wrong answer ends here */
	bool flag = true;
	for (int i = 0; i < lines.size(); i++)
	    for (int j = 0; j < lines.size(); j++)
		if (i != j && (lines[i].find(lines[j]) == 0)) flag = false;
	cout << "Set " << ++kase << " is ";
	if (!flag) cout << "not ";
	cout << "immediately decodable" << endl;
	
    }
    return 0;
}
