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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

struct aluf {
	vi id, sz, sts;
	vector<ll> sum;

	aluf(int n) {
		n++;
		id.resize(n);
		sts.resize(n);
		sum.resize(n);
		sz.resize(n, 1);
		loop(n) {
			id[i] = i;
			sum[i] = i;
			sts[i] = i;
		}
	}

	void join(int p, int q) {
		p = find(p);
		q = find(q);
		if (p == q) return;
		if (sz[p] > sz[q]) swap(p, q);
		sts[p] = sts[q];
		sz[q] += sz[p];
		sum[q] += sum[p];
	}

	void move(int p, int q) {
		int x = find(p);
		int y = find(q);
		if (x == y) return;
		sz[x]--, sz[y]++;
		sum[x] -= p, sum[y] += p;
		id[p] = id[q];
	}

	int find(int p, bool first = true) {
		if (first) p = id[p];
		return p == sts[p] ? p : sts[p] = find(sts[p], false);
	}

	pair<int, ll> answer(int p) {
		p = find(p);
		return make_pair(sz[p], sum[p]);
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	while (cin >> n >> m) {
		aluf uf(n);
		int op, p, q;
		loop(m) {
			cin >> op >> p;
			switch (op) {
				case 1:
				cin >> q;
				uf.join(p, q);
				break;
				case 2:
				cin >> q;
				uf.move(p, q);
				break;
				case 3:
				tie(p, q) = uf.answer(p);
				cout << p << " " << q << endl;
				break;
			}
		}
	}
	return 0;
}

