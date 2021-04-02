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
    vector<ii> a(n);
    loop(n) {
      cin >> a[i].first >> a[i].second;
    }
    sort(iter(a));
    int ans = 0, prev = 0;
    priority_queue<int> q;
    loop(n) {
      auto& [l, r] = a[i];
      while (!q.empty() and -q.top() < l) prev--, q.pop();
      int x = lower_bound(iter(a), ii(r, INF)) - a.begin();
      ans = max(ans, prev + x - i);
      prev++;
      q.push(-r);
    }
    cout << n - ans << endl;
  }
  return 0;
}

