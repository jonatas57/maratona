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
    int n, m, x;
    cin >> n >> m >> x;
    int s = 0;
    vi a(n);
    loop(n) {
      cin >> a[i];
      s += a[i];
    }
    priority_queue<ii> q;
    loop(m) q.emplace(0, i);
    vi ans(n);
    loop(n) {
      auto [h, p] = q.top();
      q.pop();
      ans[i] = p + 1;
      q.emplace(h - a[i], p);
    }
    cout << "YES" << endl;
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

