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

vector<string> ans;
int R, C;

void fill(int l, int r, int t, int b, int type = -1, char ch = '\0') {
	if (r - l == 1) {
		int x = l / 2, y = t / 2;
		char nextch = (x + y) & 1 ? 'C' : 'B';
		int corner = -1;
		for (int i = t;i <= b;i++) {
			for (int j = l;j <= r;j++) {
				corner++;
				if (type == corner or (R == i and C == j)) continue;
				ans[i][j] = ch ? ch : nextch;
			}
		}
	}
	else {
		int midh = avg(l, r), midv = avg(t, b);
		int tp = type == -1 ? ((int)(R > midv) << 1) + (C > midv) : type;
		vi a(4);
		loop(4) a[i] = 3 - i;
		a[tp] = -1;
		fill(l, midh, t, midv, a[0]);
		fill(midh + 1, r, t, midv, a[1]);
		fill(l, midh, midv + 1, b, a[2]);
		fill(midh + 1, r, midv + 1, b, a[3]);
		fill(midh, midh + 1, midv, midv + 1, tp, 'A');
	}
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, x;
	cin >> n >> R >> C;
	R--, C--;
	ans.resize(n, string(n, '.'));
	fill(0, n - 1, 0, n - 1);
	each(s, ans) cout << s << endl;
	return 0;
}

