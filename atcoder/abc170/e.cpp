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

const int N = 2e5 + 5;
const int T = 4 * N + 5;
#define l(id) id << 1
#define r(id) id << 1 | 1

vi st(T), kg(N);
vector<multiset<int>> kgs(N);

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = kgs[l].empty() ? INF : *kgs[l].rbegin();
	}
	else {
		int mid = avg(l, r);
		build(l(id), l, mid);
		build(r(id), mid + 1, r);
		st[id] = min(st[l(id)], st[r(id)]);
	}
}

void update(int id, int l, int r, int pos, int val) {
	if (r < pos or pos < l) return;
	if (l == r and r == pos) {
		if (val < 0) kgs[pos].erase(-val);
		else kgs[pos].insert(val);
		st[id] = kgs[pos].empty() ? INF : *kgs[l].rbegin();
	}
	else {
		int mid = avg(l, r);
		update(l(id), l, mid, pos, val);
		update(r(id), mid + 1, r, pos, val);
		st[id] = min(st[l(id)], st[r(id)]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	int a, b, c, d;
	vi rat(n + 1);
	loop(n) {
		cin >> a >> b;
		rat[i + 1] = a;
		kg[i + 1] = b;
		kgs[b].insert(a);
	}
	build(1, 1, N);
	loop(q) {
		cin >> c >> d;
		update(1, 1, N, kg[c], -rat[c]);
		kg[c] = d;
		update(1, 1, N, d, rat[c]);
		cout << st[1] << endl;
	}
	return 0;
}

