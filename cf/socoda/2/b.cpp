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

int check(vector<vi>& a, int n, int m) {
	if (n & 1) return n;
	int x = n / 2;
	bool mir = true;
	for (int i = 0;i < x and mir;i++) {
		for (int j = 0;j < m and mir;j++) {
			if (a[i][j] != a[n - 1 - i][j]) mir = false;
		}
	}
	return mir ? check(a, x, m) : n;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vi> a(n, vi(m));
	loop(n) vloop(j, m) cin >> a[i][j];
	cout << check(a, n, m) << endl;
	return 0;
}

