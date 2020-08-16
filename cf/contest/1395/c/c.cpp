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

	int n, m;
	cin >> n >> m;
	vi a(n), b(m);
	loop(n) {
		cin >> a[i];
	}
	vector<vi> one(10);
	sort(iter(b));
	loop(m) {
		cin >> b[i];
		vloop(j, 10) {
			if (b[i] & (1 << j)) one[j].push_back(i);
		}
	}
	sort(riter(a));
	int ans = 0;
	each(x, a) {
		vb pos(m, true);
		int qtd = m;
		for (int e = 9, mask = 1 << 9;mask;mask >>= 1, e--) {
			vb pos2 = pos;
			int qtd2 = qtd;
			if (x & mask) {
				if (!(mask & ans)) {
					each(y, one[e]) {
						if (pos2[y]) qtd2--;
						pos2[y] = false;
					}
				}
			}
			if (!qtd2) {
				ans |= mask;
			}
			else if (qtd2 != qtd) {
				pos.swap(pos2);
				qtd = qtd2;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

