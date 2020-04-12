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
	ll op, x;
	ll b1 = 0, b2 = 1;
	loop(q) {
		cin >> op;
		if (op == 1) {
			cin >> x;
			if (x > 0) x -= n;
			ll y = x - (x % 2 != 0);
			b1 -= y;
			b2 -= y;
			if (x & 1) {
				swap(b1, b2);
				b1 += n - 2;
			}
		}
		else {
			swap(b1, b2);
		}
	}
	b1 %= n;
	b2 %= n;
	b1++;
	b2++;
	for (int i = 0;i < n;i++) {
		if (i & 1) {
			cout << b2 << " ";
			b2 += 2;
			if (b2 > n) b2 -= n;
		}
		else {
			cout << b1 << " ";
			b1 += 2;
			if (b1 > n) b1 -= n;
		}
	}
	cout << endl;
	return 0;
}

