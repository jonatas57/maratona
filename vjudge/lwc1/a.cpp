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

	int c, r;
	string s, t;
	while (cin >> c >> r and c | r) {
		init(c);
		int x = 0;
		map<string, int> ns;
		loop(c) {
			cin >> s;
			ns[s] = x++;
		}
		loop(r) {
			cin >> s >> t;
			join(ns[s], ns[t]);
		}
		int ans = 0;
		loop(c) {
			ans = max(ans, sz[find(i)]);
		}
		cout << ans << endl;
	}
	return 0;
}

