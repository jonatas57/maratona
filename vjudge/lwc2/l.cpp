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

struct node {
	char c;
	bool end;
	vector<node*> next;
	node(char c) : c(c), end(false), next(26, nullptr) {}
	void insert(string& s, int i = 0) {
		if (s[i]) {
			int x = s[i] - 'a';
			if (!next[x]) next[x] = new node(s[i]);
			next[x]->insert(s, i + 1);
		}
		else {
			end = true;
		}
	}
	void free() {
		loop(26) {
			if (next[i]) {
				next[i]->free();
				delete next[i];
			}
		}
	}
};

int ans;
void solve(node* n, int qtd = 0, bool first = true) {
	int cnt = n->end;
	loop(26) if (n->next[i]) cnt++;
	if (n->end) {
		ans += qtd;
	}
	loop(26) {
		if (n->next[i]) {
			solve(n->next[i], qtd + (cnt != 1 or first), false);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	while (cin >> n) {
		string s;
		node* trie = new node(' ');
		loop(n) {
			cin >> s;
			trie->insert(s);
		}
		ans = 0;
		solve(trie);
		int x = (double)ans / n * 1000;
		if (x % 10 >= 5) x += 10;
		x /= 10;
		cout << fixed << setprecision(2) << x / 100.0 << endl;
		trie->free();
		delete trie;
	}
	return 0;
}

