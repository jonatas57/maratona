#include <bits/stdc++.h>

using namespace std;

typedef long long      ll;
typedef vector<int>    vi;
typedef vector<bool>   vb;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for (auto& x : s)
#define loop(x)     for (int i = 0;i < x;i++)
#define vloop(v, x) for (int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"

ll sqrtll(ll x) {
  if (x == 1) return 1;
  ll l = 1, r = x;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (mid <= x / mid) l = mid + 1;
    else r = mid;
  }
  return l - 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  loop(t) {
    ll k;
    cin >> k;
    ll l = k, r = k + 200000000010ll;
    while (l < r) {
      ll mid = (l + r) / 2;
      ll x = mid - sqrtll(mid);
      if (x < k) l = mid + 1;
      else r = mid;
    }
    cout << l << endl;
  }
  return 0;
}

