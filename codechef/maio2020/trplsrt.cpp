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
const int N = 2e5;
vi a(N), pos(N);
vb ok(N);

void triplesort(int i, int j, int k) {
	int tmp = a[i];
	a[i] = a[k];
	pos[a[k]] = i;
	a[k] = a[j];
	pos[a[j]] = k;
	a[j] = tmp;
	pos[tmp] = j;
	ok[a[i]] = pos[a[i]] == a[i];
	ok[a[j]] = pos[a[j]] == a[j];
	ok[a[k]] = pos[a[k]] == a[k];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, k;
		cin >> n >> k;
		loop(n) {
			cin >> a[i];
			a[i]--;
			pos[a[i]] = i;
			ok[i] = a[i] == i;
		}
		bool imp = false;
		vector<tuple<int, int, int>> ans;
		loop(n) {
			if (a[i] != i) {
				int x = i;
				int y = a[i];
				int z = pos[i];
				if (y == z) {
					for (y = x + 1;y < n and (ok[y] or y == z);y++);
					if (y == n) {
						imp = true;
						break;
					}
				}
				triplesort(x, y, z);
				ans.emplace_back(x + 1, y + 1, z + 1);
			}
		}
		int m = ans.size();
		if (imp or m > k) cout << -1 << endl;
		else {
			cout << m << endl;
			int i, j, l;
			each(t, ans) {
				tie(i, j, l) = t;
				cout << i << " " << j << " " << l << endl;
			}
		}
	}
	return 0;
}

