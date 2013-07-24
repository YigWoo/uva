/* It's the version I try to get an AC */
/* But it's way too complicated for a simple question */
/* And it's ugly in both approach and style */
/* Get a WA, but hard to find where's wrong */
/* Hard to debug */
/* But it's a try */
/* Leave it as it is */
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
using namespace std;

void getConceptAndAmount(string line, char& concept, double& amount) {
    concept = line[line.size()-1];
    cin >> amount;
}
void getPrefixAndUnit(string line, char& prefix, char& unit) {
    if (line[0] == 'm' || line[0] == 'k' || line[0] == 'M') {
	prefix = line[0];
	unit = line[1];
    }
    else {
	prefix = 0;
	unit = line[0];
    }
}

double decidePrefix(char c) {
    double prefix = 1;
    if (c == 'm') prefix = 0.001;
    if (c == 'k') prefix = 1000;
    if (c == 'M') prefix = 1000000;
    return prefix;
}

void parseDataFiled(char concept, double amount, char prefix, map<char, double>& piu, bool& multiFlag) {
    double pre;
    if (concept == 'P') multiFlag = false;
    pre = decidePrefix(prefix);
    amount *= pre;
    piu[concept] = amount;
}


int main() {
    int cc;
    string dump;
    cin >> cc;
    getline(cin, dump);
    for (int i = 0; i < cc; i++) {
	bool multiFlag = true;
	map<char, double> piu;
	map<char, char> piutable;
	piutable['P'] = 'W';
	piutable['U'] = 'V';
	piutable['I'] = 'A';
	char concept, prefix, unit;
	double amount;
	size_t pos;
	string line;
	getline(cin, line, '=');
	getConceptAndAmount(line, concept, amount);
	getline(cin, line, '=');
	getPrefixAndUnit(line, prefix, unit);
	/* cout << concept << amount << prefix << unit << "  "; */
	parseDataFiled(concept, amount, prefix, piu, multiFlag);
	getConceptAndAmount(line, concept, amount);
	getline(cin, line);
	getPrefixAndUnit(line, prefix, unit);
	parseDataFiled(concept, amount, prefix, piu, multiFlag);
	/* cout << concept << amount << prefix << unit << endl; */
        /* for (map<char, double>::iterator it = piu.begin(); it != piu.end(); it++) { */
        /*     cout << it->second << endl; */
        /* } */
	for (map<char, char>::iterator tableit = piutable.begin();
	     tableit != piutable.end(); tableit++) {
	    if (piu.find(tableit->first) == piu.end()) {
		double d = 1;
                char u;
                if (multiFlag) {
                    for (map<char, double>::iterator it = piu.begin();
                         it != piu.end();
                         it++) {
                        d *= it->second;
                    }
                    u = 'W';
                }
                else {
                    map<char, double>::iterator it = piu.find('P');
                    d = it->second;
                    if (piu.find('U') != piu.end()) {
                        d = d / piu.find('U')->second;
                        u = 'A';
                    }
                    else if (piu.find('I') != piu.end()) {
                        d = d / piu.find('I')->second;
                        u = 'V';
                    }
                }
		cout << "Proble #" << i+1 << endl;
		cout << tableit->first << '=' << fixed << setprecision(2) << d << u << endl;
                cout << endl;
	    }
	}
    }
    return 0;
}
