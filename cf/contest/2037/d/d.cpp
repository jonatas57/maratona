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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  loop(t) {
    int n, m, l;
    cin >> n >> m >> l;
    vector<ii> hs(n);
    for (auto& [a, b] : hs) cin >> a >> b;
    vector<ii> ps(m);
    for (auto& [a, b] : ps) cin >> a >> b;
    int x = 0;
    int pow = 1;
    int pi = 0;
    int ans = 0;
    priority_queue<int> q;
    for (auto& [l, r] : hs) {
      while (pi < m and ps[pi].first < l) q.push(ps[pi++].second);
      int minp = r - l + 2;
      while (!q.empty() and minp > pow) {
        pow += q.top();
        q.pop();
        ans++;
      }
      if (minp > pow) {
        ans = -1;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

