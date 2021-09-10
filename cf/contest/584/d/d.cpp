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

bool isprime(ll x) {
  for (ll i = 2;i * i <= x;i++) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  vi ans;
  if (isprime(n)) ans = {n};
  else if (isprime(n - 2)) ans = {2, n - 2};
  else {
    ans = {3};
    n -= 3;
    for (ll i = 3;i + i <= n;i += 2) {
      if (isprime(i) and isprime(n - i)) {
        ans.push_back(i);
        ans.push_back(n - i);
        break;
      }
    }
  }
  cout << ans.size() << endl;
  each(x, ans) cout << x << " ";
  cout << endl;
  return 0;
}

