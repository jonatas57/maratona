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
  
  int n, k, q;
  cin >> n >> k >> q;
  vector<vi> a(k, vi(n));
  loop(n) vloop(j, k) {
    cin >> a[j][i];
    if (i) a[j][i] |= a[j][i - 1];
  }
  loop(q) {
    int m;
    cin >> m;
    int l = 0, r = n - 1;
    loop(m) {
      int R, c;
      char o;
      cin >> R >> o >> c;
      R--;
      if (o == '<') r = min(r, (int)(lower_bound(iter(a[R]), c) - a[R].begin() - 1));
      else l = max(l, (int)(upper_bound(iter(a[R]), c) - a[R].begin()));
    }
    cout << (l > r ? -1 : l + 1) << endl;
  }
  return 0;
}

