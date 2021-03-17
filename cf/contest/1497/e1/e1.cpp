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
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

mii fat(ll x) {
  mii fs;
  for (ll i = 2;i * i <= x;i++) {
    while (x % i == 0) {
      fs[i]++;
      x /= i;
    }
  }
  if (x > 1) fs[x]++;
  return fs;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, k;
    cin >> n >> k;
    int ans = 1;
    set<int> p;
    loop(n) {
      int x;
      cin >> x;
      mii fats = fat(x);
      int y = 1;
      for (auto& [b, e] : fats) if (e & 1) y *= b;
      if (p.count(y)) ans++, p.clear();
      p.insert(y);
    }
    cout << ans << endl;
  }
  return 0;
}

