#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

struct trie {
	char c;
	int qtd;
	vector<trie*> next;
	trie(char c) : c(c), qtd(0), next(2, nullptr) {}
};

trie* insert(trie* t, string& s, int pos = 0) {
	t->qtd++;
	if (s[pos]) {
		int x = s[pos] - '0';
		if (!t->next[x]) t->next[x] = new trie(s[pos]);
		t->next[x] = insert(t->next[x], s, pos + 1);
	}
	return t;
}

void erase(trie* t, string& s, int pos = 0) {
	t->qtd--;
	if (!s[pos]) return;
	erase(t->next[s[pos] - '0'], s, pos + 1);
}

int search(trie* t, string& s, string& r, int pos = 0) {
	if (!t or !s[pos]) return 0;
	int ans = 0;
	int x = s[pos] - '0';
	if (r[pos] == '1') {
		if (t->next[x]) ans += t->next[x]->qtd;
		x ^= 1;
	}
	ans += search(t->next[x], s, r, pos + 1);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int q;
	cin >> q;
	int op, p, l;
	trie* t = new trie(' ');
	loop(q) {
		cin >> op >> p;
		string s = bitset<30>(p).to_string();
		if (op == 1) {
			t = insert(t, s);
		}
		else if (op == 2) {
			erase(t, s);
		}
		else {
			cin >> l;
			string r = bitset<30>(l).to_string();
			cout << search(t, s, r) << endl;
		}
	}
	return 0;
}

