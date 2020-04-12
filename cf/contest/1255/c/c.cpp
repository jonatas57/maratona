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

map<int, map<int, vi>> ok;
vb used;

int search (int a, int b) {
	if (a > b) swap(a, b);
	int c;
	while (!ok[a][b].empty()) {
		c = ok[a][b].back();
		if (used[c]) ok[a][b].pop_back();
		else return c;
	}
	return -1;
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	used.resize(n + 1, false);
	vi cnt(n + 1, 0);
	int a, b, c;
	loop(n - 2) {
		cin >> a >> b >> c;
		int sum = a + b + c;
		int x, y, z;
		x = min({a, b, c});
		z = max({a, b, c});
		y = sum - x - z;
		ok[x][y].push_back(z);
		ok[x][z].push_back(y);
		ok[y][z].push_back(x);
		cnt[x]++, cnt[y]++, cnt[z]++;
	}
	int one, t1 = -1, t2 = -1;
	loop(n) {
		if (cnt[i] == 1) one = i;
		else if (cnt[i] == 2) {
			if (t1 == -1) t2 = i;
			else t1 = i;
		}
	}

	vi ans(n, 0);
	ans[0] = one;
	used[one] = true;
	c = search(one, t1);
	ans[1] = t1;
	if (c == -1) c = search(one, t2), ans[1] = t2;
	used[ans[1]] = true;
	t1 = ans[0], t2 = ans[1];
	for (int i = 2;i < n;i++) {
		c = search(t1, t2);
		ans[i] = c;
		used[c] = true;
		t1 = t2;
		t2 = c;
	}
	each(x, ans) cout << x << " ";
	cout << endl;
	return 0;
}

