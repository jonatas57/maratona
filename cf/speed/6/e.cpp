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

struct voucher {
	int l, r, c, dur;
	voucher(int l, int r, int c) : l(l), r(r), c(c), dur(r - l + 1) {}
	bool operator<(voucher& v) {
		return (dur == v.dur ? c < v.c : dur < v.dur);
	}
	bool operator<(int v) {
		return dur < v;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, x;
	cin >> n >> x;
	vector<voucher> vs;
	int l, r, c;
	loop(n) {
		cin >> l >> r >> c;
		vs.emplace_back(l, r, c);
	}
	sort(iter(vs));
	int ans = INT_MAX;
	for (int i = 0;i < n and vs[i].dur <= x / 2;i++) {
		auto beg = lower_bound(iter(vs), x - vs[i].dur), en = upper_bound(iter(vs), vs[i].dur);
		for (auto it = beg;it != en;it++) {
			if (vs[i].l > it->r or vs[i].r < it->l) {
				ans = min(vs[i]
	return 0;
}

