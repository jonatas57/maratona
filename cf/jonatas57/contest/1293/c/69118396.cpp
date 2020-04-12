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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vector<vb> floor(2, vb(n + 1, false));
	int a, b, cnt = 0;
	loop(q) {
		cin >> a >> b;
		a--;
		int x = 0;
		for (int j = -1;j <= 1;j++) {
			if (b + j <= 0 or b + j > n) continue;
			x += floor[a ^ 1][b + j];
		}
		cnt += x * (floor[a][b] ? -1 : 1);
		floor[a][b] = !floor[a][b];
		cout << (cnt ? "No" : "Yes") << endl;
	}
	return 0;
}

