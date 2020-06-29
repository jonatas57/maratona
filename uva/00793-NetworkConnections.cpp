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
	id.resize(x);
	sz.assign(x, 1);
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
	cin >> t;
	loop(t) {
		if (i) cout << endl;
		int n;
		cin >> n;
		init(n);
		stringstream ss;
		int ans1 = 0, ans2 = 0;
		string s;
		getline(cin, s);
		while (getline(cin, s) and s.length()) ss << s;
		char op;
		int a, b;
		while (ss >> op >> a >> b) {
			if (op == 'c') join(a - 1, b - 1);
			else if (find(a - 1) == find(b - 1)) ans1++;
			else ans2++;
		}
		cout << ans1 << "," << ans2 << endl;
	}
	return 0;
}

