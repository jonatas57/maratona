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

const ll N = 10000000;
vi lp(N + 1, 0);
vector<ll> primes(665000, 0);
int qtd = 0;

void sieve() {
	for (ll i = 2; i <= N;i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			primes[qtd++] = i;
		}
		for (ll j = 0; j < qtd && primes[j] <= lp[i] && i * primes[j] <= N;j++) {
			lp[i * primes[j]] = primes[j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	sieve();
	int n;
	cin >> n;
	int x;
	vector<ll> cnt(N, 0);
	loop(n) {
		cin >> x;
		int last = 1;
		while (x > 1) {
			if (last != lp[x]) {
				cnt[last = lp[x]]++;
			}
			x /= last;
		}
	}
	loop(N - 1) {
		cnt[i + 1] += cnt[i];
	}
	int m;
	ll l, r;
	cin >> m;
	loop(m) {
		cin >> l >> r;
		cout << cnt[min(N - 1, r)] - cnt[min(N - 1, l - 1)] << endl;
	}
	return 0;
}

