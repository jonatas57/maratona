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
    vi a(n), b(n);
    map<int, vi> ap, bp;
    set<int> aps, bps;
    bool ok = true;
    loop(n) {
      cin >> a[i];
      ap[a[i]].push_back(i);
      aps.insert(i);
    }
    loop(n) {
      cin >> b[i];
      bp[b[i]].push_back(i);
      if (b[i] < a[i]) ok = false;
    }
    aps.insert(-1), bps.insert(-1);
    aps.insert(n), bps.insert(n);
    auto it = ap.begin();
    for (auto [k, v] : bp) {
      if (!ok) break;
      while (it != ap.end() and it->first <= k) {
        each(x, it->second) aps.erase(x);
        it++;
      }
      each(x, v) {
        int l = max(*(prev(aps.lower_bound(x))) + 1, *(prev(bps.lower_bound(x))) + 1);
        int r = min(*aps.upper_bound(x) - 1, *bps.upper_bound(x) - 1);
        int cnt = ap.count(k) ? upper_bound(iter(ap[k]), r) - lower_bound(iter(ap[k]), l) : 0;
        if (!cnt) ok = false;
      }
      each(x, v) bps.insert(x);
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}

