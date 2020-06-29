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

vi id, sz;
void init(int x) {
	sz.assign(x, 1);
	id.resize(x);
	loop(x) id[i] = i;
}
int find(int x) { return x == id[x] ? x : id[x] = find(id[x]); }
void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	id[a] = b;
	sz[b] += sz[a];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	string s;
	cin >> t;
	getline(cin, s);
	getline(cin, s);
	loop(t) {
		getline(cin, s);
		int n = s[0] - 'A' + 1;
		init(n);
		while (getline(cin, s) and s.length()) {
			join(s[0] - 'A', s[1] - 'A');
		}
		set<int> gs;
		loop(n) {
			gs.insert(find(i));
		}
		if (i) cout << endl;
		cout << gs.size() << endl;
	}
	return 0;
}

