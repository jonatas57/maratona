#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for(auto& x : s)
#define loop(x)     for(int i = 0;i < x;i++)
#define vloop(v, x) for(int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"
#define avg(l, r)   (l + r) / 2

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vector<ll> a(n), d(n), s(n), l(n), r(n);
    loop(n) {
      cin >> a[i];
      l[i] = i - 1;
      r[i] = i + 1;
      if (i) s[i - 1] += a[i];
      if (i < n - 1) s[i + 1] += a[i];
    }
    r[n - 1] = -1;
    queue<int> q;
    loop(n) {
      cin >> d[i];
      if (d[i] < s[i]) q.push(i);
    }
    vi ans(n);
    vb ok(n, true);
    loop(n) {
      ans[i] = q.size();
      set<int> u;
      while (!q.empty()) {
        int x = q.front();
        q.pop();
        ok[x] = false;
        if (l[x] != -1) {
          r[l[x]] = r[x];
          s[l[x]] += (r[x] == -1 ? 0 : a[r[x]]) - a[x];
          u.insert(l[x]);
        }
        if (r[x] != -1) {
          l[r[x]] = l[x];
          s[r[x]] += (l[x] == -1 ? 0 : a[l[x]]) - a[x];
          u.insert(r[x]);
        }
      }
      each(x, u) {
        if (!ok[x]) continue;
        if (d[x] < s[x]) q.push(x);
      }
    }
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

