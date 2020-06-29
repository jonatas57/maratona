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

	int n, m, k;
	while (cin >> n >> k >> m and n | m | k) {
		vb q(n, true);
		int x = n;
		vector<ii> ans;
		int i = -1, j = n;
		while (x) {
			for (int p = 0;p < k;) {
				i++;
				if (i == n) i = 0;
				p += q[i];
			}
			for (int p = 0;p < m;) {
				j--;
				if (j == -1) j = n - 1;
				p += q[j];
			}
			ans.emplace_back(i + 1, j + 1);
			q[i] = false, x--;
			if (q[j]) q[j] = false, x--;
		}
		bool fir = true;
		each(p, ans) {
			if (!fir) cout << ",";
			cout << setw(3) << p.first;
			if (p.first != p.second) cout << setw(3) << p.second;
			fir = false;
		}
		cout << endl;
	}
	return 0;
}

