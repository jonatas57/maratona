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
    vi a(n), deg(n);
    loop(n) {
      cin >> a[i];
      a[i]--;
      deg[a[i]]++;
    }
    vector<ll> cost(n);
    loop(n) cin >> cost[i];
    queue<int> q;
    loop(n) if (!deg[i]) q.push(i);
    vi ans;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      ans.push_back(u + 1);
      deg[a[u]]--;
      if (!deg[a[u]]) q.push(a[u]);
    }
    loop(n) {
      if (!deg[i]) continue;
      int p = i;
      for (int at = i;;at = a[at]) {
        if (cost[at] < cost[p]) p = at;
        if (a[at] == i) {
          for (int at2 = a[p];at2 != p;at2 = a[at2]) {
            ans.push_back(at2 + 1);
            deg[at2] = 0;
          }
          ans.push_back(p + 1);
          deg[p] = 0;
          break;
        }
      }
    }
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

