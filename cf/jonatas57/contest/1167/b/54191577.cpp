#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

int ask(int j) {
	cout << "? " << 1 << " " << j << endl;
	cout.flush();
	int x;
	cin >> x;
	return x;
}

int repeat(ii a, ii b, int& x, int& y) {
	mii cnt;
	cnt[a.first]++;
	cnt[a.second]++;
	cnt[b.first]++;
	cnt[b.second]++;
	int r = 0;
	each(p, cnt) if (p.second == 2) r = p.first;
	x = (a.first == r ? a.second : a.first);
	y = (b.first == r ? b.second : b.first);
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);

	map<int, ii> mult;
	vi base = {4, 8, 15, 16, 23, 42};
	vb used(6, false);
	loop(5) for (int j = i + 1;j < 6;j++) mult[base[i] * base[j]] = {base[i], base[j]};
	vi ans(6, 0);
	ii a, b;
	a = mult[ask(2)];
	b = mult[ask(3)];
	int x, y;
	ans[0] = repeat(a, b, x, y);
	ans[1] = x;
	ans[2] = y;
	ans[3] = ask(4) / ans[0];
	ans[4] = ask(5) / ans[0];
	loop(5) vloop(j, 6) if (ans[i] == base[j]) used[j] = true;
	loop(6) if (!used[i]) ans[5] = base[i];
	cout << "!";
	each(x, ans) cout << " " << x;
	cout << endl;
	cout.flush();
	return 0;
}

