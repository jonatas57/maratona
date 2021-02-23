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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vector<ii> a;
    ll sum = 0;
    loop(n) {
      int x;
      cin >> x;
      sum += x;
      a.emplace_back(x, i + 1);
    }
    sort(iter(a));
    sum -= a.back().first;
    vi ans(1, a.back().second);
    for (int i = n - 2;i >= 0;i--) {
      if (sum >= a[i + 1].first) ans.push_back(a[i].second);
      else break;
      sum -= a[i].first;
    }
    sort(iter(ans));
    cout << ans.size() << endl;
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

