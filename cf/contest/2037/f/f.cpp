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
    int n, m, k;
    cin >> n >> m >> k;
    vi hs(n), xs(n);
    loop(n) cin >> hs[i];
    loop(n) cin >> xs[i];
    int l = 1, r = 1000000001;
    bool pos = false;
    while (l < r) {
      int mid = (l + r) >> 1;
      map<int, ii> sl;
      loop(n) {
        int atk = (hs[i] + mid - 1) / mid;
        if (atk > m) continue;
        int dist = m - atk;
        sl[xs[i] - dist].first++;
        sl[xs[i] + dist].second++;
      }
      bool ok = false;
      int cnt = 0;
      for (auto [x, p] : sl) {
        cnt += p.first;
        if (cnt >= k) ok = true;
        cnt -= p.second;
      }
      if (ok) r = mid, pos = true;
      else l = mid + 1;
    }
    cout << (pos ? l : -1) << endl;
  }
  return 0;
}

