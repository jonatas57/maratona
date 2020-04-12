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

struct uf {
	int n;
	vi id, sz;
	uf(int n) : n(n), id(n * n), sz(n * n, 1) {
		loop(n * n) id[i] = i;
	}
	int find(int x) { return x == id[x] ? x : id[x] = find(id[x]); }
	int find(int a, int b) { return find(conv(a, b)); }
	void join(int a, int b, int c, int d) {
		int x = find(a, b);
		int y = find(c, d);
		if (x == y) return;
		if (x > y) swap(x, y);
		id[x] = y;
		sz[y] += sz[x];
	}
	int conv(int a, int b) {
		return a * n + b;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	for (int t = 1;cin >> n;t++) {
		vector<string> m(n);
		loop(n) cin >> m[i];
		uf g(n);
		loop(n) {
			vloop(j, n) {
				for (int x = -1;x <= 1;x++) for (int y = -1;y <= 1;y++) {
					int a = i + x, b = j + y;
					if (a >= 0 and a < n and b >= 0 and b < n and m[i][j] == m[a][b]) g.join(i, j, a, b);
				}
			}
		}
		set<int> cs;
		loop(n) vloop(j, n) {
			if (m[i][j] == '1') {
				cs.insert(g.find(i, j));
			}
		}
		cout << "Image number " << t << " contains " << cs.size() << " war eagles." << endl;
	}
	return 0;
}

