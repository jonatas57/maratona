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

const int N = 1e5;
vi primes;
void genPrimes() {
  vb isprime(N, true);
  isprime[0] = isprime[1] = false;
  for (int i = 2;i < N;i++) {
    if (isprime[i]) {
      primes.push_back(i);
      for (int j = i + i;j < N;j += i) isprime[j] = false;
    }
  }
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  genPrimes();
  ll l, u;
  while (cin >> l >> u) {
    ii ans1(-1, -1), ans2(-1, -1);
    int dist1 = INF, dist2 = 0;
    vb isprime(u - l + 1, true);
    each(p, primes) {
      if (p * p > u) continue;
      ll i = (l + p - 1) / p * p;
      for (ll j = i;j <= u;j += p) {
        if (j == p) continue;
        isprime[j - l] = false;
      }
    }
    int lastp = -1;
    for (int i = l;i <= u;i++) {
      if (isprime[i - l] and i >= 2) {
        if (lastp != -1) {
          if (i - lastp < dist1) dist1 = i - lastp, ans1 = {lastp, i};
          if (i - lastp > dist2) dist2 = i - lastp, ans2 = {lastp, i};
        }
        lastp = i;
      }
    }
    if (ans1.first == -1) cout << "There are no adjacent primes." << endl;
    else cout << ans1.first << "," << ans1.second << " are closest, " << ans2.first << "," << ans2.second << " are most distant." << endl;
  }
	return 0;
}

