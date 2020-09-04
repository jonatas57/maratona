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
const int N = 1e6;

typedef tuple<int, int, int> tup;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  vector<tup> ts;
  for (int m = 1;m * m <= N;m++) {
    for (int n = 1;n < m;n++) {
      if (__gcd(m, n) == 1 and (m & 1) ^ (n & 1)) {
        int x = m * m;
        int y = n * n;
        if (y > N) break;
        ts.emplace_back(x - y, 2 * m * n, x + y);
      }
    }
  }
  sort(iter(ts), [](tup a, tup b) {
    return get<2>(a) < get<2>(b);
  });
  int n;
  while (cin >> n) {
    int pri = 0, all = n;
    int a, b, c;
    vb used(n + 1, false);
    each(t, ts) {
      tie(a, b, c) = t;
      if (c > n) break;
      pri++;
      for (int i = a, j = b, k = c;k <= n;i += a, j += b, k += c) {
        all -= !used[i] + !used[j] + !used[k];
        used[i] = used[j] = used[k] = true;
      }
    }
    cout << pri << " " << all << endl;
  }
	return 0;
}

