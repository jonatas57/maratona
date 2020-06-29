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

int n;
bool operator<(vi& a, vi& b) {
	loop(n) {
		if (a[i] <= b[i]) return false;
	}
	return true;
}


vi lis(vector<pair<vi, int>>& a, int n) {
	vi d(n, 1);
	vi p(n, -1);
	loop(n) {
		vloop(j, i) {
			if (a[j].first < a[i].first and d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
				p[i] = j;
			}
		}
	}
	int sz = 0, id;
	loop(n) {
		if (sz < d[i]) {
			sz = d[i];
			id = i;
		}
	}
	vi ans;
	for (int i = id;i != -1;i = p[i]) ans.push_back(a[i].second);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int k;
	while (cin >> k >> n) {
		vector<pair<vi, int>> a(k);
		loop(k) {
			int x;
			a[i].second = i + 1;
			vloop(j, n) {
				cin >> x;
				a[i].first.push_back(x);
			}
			sort(iter(a[i].first));
		}
		sort(riter(a));
		vi ans = lis(a, k);
		cout << ans.size() << endl;
		each(x, ans) cout << x << " ";
		cout << endl;
	}
	return 0;
}

