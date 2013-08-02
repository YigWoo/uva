#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie {
  public:
    Trie();
    ~Trie();
    size_t size();
    bool isEmpty();
    bool contains(const string& key) const;
    void insert(const string& key);
    void remove(const string& key);
    string longestPrefixOf(string query) const;
    vector<string> keys() const;
    vector<string> keysWithPrefix(const string& key) const;
  public:
    class Node {
    public:
      Node();
      ~Node();
      bool isKey;
      vector<Node*> children;
    };
  private:
    const static int R = 26; //26 lowercase english chars
    Node *root;
  private:
    size_t size(const Node* x);
    Trie::Node* put(Node* x, const string& key, size_t d);
    const Trie::Node* get(Node* x, const string& key, size_t d) const;
    Trie::Node* remove(Node* x, const string& key, size_t d);
    void collect(const Node* x, const string& key, vector<string>& q) const;
    void destory(Node* x); 
};

Trie::Node::Node():isKey(false) {
    for (int i = 0; i < R; i++)
	children.push_back(NULL);
}
Trie::Node::~Node() {}
Trie::Trie() { root = new Node();}
Trie::~Trie() {
    destory(root);
}
void Trie::destory(Node* x) {
    for (int i = 0; i < R; i++)
	if (x->children[i] != NULL)
	    destory(x->children[i]);
    delete x;
}
size_t Trie::size() {return size(root);}
size_t Trie::size(const Node* x) {
    if (x == NULL) return 0;
    size_t cnt = 0;
    if (x->isKey == true) cnt++;
    for (int i = 0; i < R; i++)
	cnt += size(x->children[i]);
    return cnt;
}
bool Trie::isEmpty() {return size(root) == 0;}
void Trie::insert(const string& key) {
    root = put(root, key, 0);
}
Trie::Node* Trie::put(Node* x, const string& key, size_t d) {
    if (x == NULL) x = new Node();
    if (d == key.length()) {
	x->isKey = true;
	return x;
    }
    char c = key[d];
    x->children[c-'a'] = put(x->children[c-'a'], key, d+1);
    return x;
}
bool Trie::contains(const string& key) const{
    /* const pointer as return type */
    const Node* x = get(root, key, 0);
    if (x == NULL) return false;
    return x->isKey;
}
const Trie::Node* Trie::get(Node* x, const string& key, size_t d) const {
    if (x == NULL) return NULL;
    if (d == key.size()) return x;
    char c = key[d];
    /* the next line is a little bit of hard coding */
    /* some other lines in the code are similar */
    return get(x->children[c-'a'], key, d+1);
}
void Trie::remove(const string& key) {
    root = remove(root, key, 0);
}
Trie::Node* Trie::remove(Node* x, const string& key, size_t d) {
    if (x == NULL) return NULL;
    if (d == key.size()) x->isKey = false;
    else {
	char c = key[d];
	x->children[c-'a'] = remove(x->children[c-'a'], key, d+1);
    }
    /*   The following line is a tricky line,
     * it ensures that if the node corresponds
     * to the last character of a key, recursive
     * deletion stops here, otherwise,  program
     * check whether the node has non-NULL nodes,
     * if not, it will remove current node.
     */
    if (x->isKey != false) return x;
    for (int c = 0; c < R; c++)
	if (x->children[c] != NULL)
	    return x;
    delete x;
    return NULL;
}
string Trie::longestPrefixOf(string query) const {
}
vector<string> Trie::keys() const {
    return keysWithPrefix("");
}
vector<string> Trie::keysWithPrefix(const string& prefix) const {
    vector<string> q;
    collect(get(root, prefix, 0), prefix, q);
    return q;
}
void Trie::collect(const Node* x, const string& key, vector<string>& q) const {
    if (x == NULL) return;
    if (x->isKey == true) q.push_back(key);
    for (int i = 0; i < R; i++) {
	char c = (char) (i + 'a');
	collect(x->children[i], key+c, q);
    }
}

string str2lower(const string &tmp) {
    string res(tmp);
    for (size_t l = 0; l != tmp.size(); l++)
	if (isupper(tmp[l]))
	    res[l] = tolower(tmp[l]);
    return res;
}

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
    Trie t;
    int j = 0;
    while (!cin.eof()) {
	string word;
	word = nextword(cin);
	word = str2lower(word);
	if (word != "")
	    t.insert(word);
    }
    vector<string> keys = t.keys();
    int i = 0;
    for (vector<string>::iterator it = keys.begin();
	 it != keys.end();
	 it++, i++) {
	cout << *it << endl;
    }
    return 0;
}
