#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>         vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  ll n, k;
  cin >> n >> k;
  int N = 200000;
  vector<ll> a(N + 1, 0);
  int m = INF;
  loop(n) {
    int x;
    cin >> x;
    m = min(m, x);
    a[0]++;
    a[x]--;
  }
  loop(N) a[i + 1] += a[i];
  loop(N) a[N - i - 1] += a[N - i];
  ll tot = a[m];
  int ans = 0;
  while (tot) {
    ans++;
    tot = *lower_bound(riter(a), tot - k);
  }
  cout << ans << endl;
  return 0;
}

