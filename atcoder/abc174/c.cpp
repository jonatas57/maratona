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

	ll k;
	cin >> k;
	vi aux(10, INF);
	int r = k % 10;
	for (int i = 1;i < 10;i++) {
		int x = r * i % 10;
		aux[x] = min(aux[x], i);
	}
	ll ans = 0, sum = 0;
	do {
		int x = 7 - sum % 10;
		if (x < 0) x += 10;
		if (aux[x] == INF) {
			ans = -1;
			break;
		}
		else {
			sum += k * aux[x];
		}
		while (sum % 10 == 7) sum /= 10, ans++;
	} while (sum);
	cout << ans << endl;
	return 0;
}

