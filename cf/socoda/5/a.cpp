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

struct square {
	int a, b, c, d;
	int state = 0;
	square(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {
		if ((a == b) and (c == d)) state |= 2;
		if ((a == c) and (b == d)) state |= 1;
	}
	int color(int x) {
		return x == 1 ? a : d;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	vector<vi> gs = {{0, 1, 2, 5, 0}, {0, 3, 2, 4, 0}, {3, 1, 4, 5, 3}};
	vector<vi> bs = {{1, 1, 1, 1, 1}, {2, 1, 2, 1, 2}, {2, 2, 2, 2, 2}};
	vector<square> ss;
	int a, b, c, d;
	loop(6) {
		cin >> a >> b >> c >> d;
		if (i < 4 and i != 2) ss.emplace_back(a, b, c, d);
		else if (i == 2) ss.emplace_back(c, d, a, b);
		else ss.emplace_back(b, a, d, c);
	}
	bool ans = false;
	loop(3) {
		vb vis(6, false);
		bool pos1 = true, pos2 = true;
		vloop(j, 4) {
			vis[gs[i][j]] = true;
			if (ss[gs[i][j]].state == bs[i][j]) {
				pos1 &= ss[gs[i][j]].color(1) == ss[gs[i][j + 1]].color(2);
				pos2 &= ss[gs[i][j]].color(2) == ss[gs[i][j + 1]].color(1);
			}
			else pos1 = pos2 = false;
		}
		loop(6) {
			if (!vis[i] and ss[i].state != 3) pos1 = pos2 = false;
		}
		ans |= pos1 or pos2;
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
