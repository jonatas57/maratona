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
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(n);
    loop(n) cin >> a[i];
    loop(n) cin >> b[i];
    vi rs(n), cs(m);
    loop(n) vloop(j, m) {
      rs[i] += a[i][j] - b[i][j];
      cs[j] += a[i][j] - b[i][j];
    }
    bool ok = true;
    each(x, rs) if (x % 3) ok = false;
    each(x, cs) if (x % 3) ok = false;
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}

