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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int q;
	cin >> q;
	loop(q) {
		ll n, m;
		cin >> n >> m;
		ll mult = n / m;
		vb used(10, false);
		ll x = m % 10, y = x, cnt = 0, sum = 0;
		vector<ll> sums(1, 0);
		while (!used[y]) {
			used[y] = true;
			sum += y;
			sums.push_back(sum);
			y += x;
			y %= 10;
			cnt++;
		}
		ll times = mult / cnt;
		sum *= times;
		sum += sums[mult % cnt];
		cout << sum << endl;
	}
	return 0;
}
