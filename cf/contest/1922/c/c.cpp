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
    vi a(n);
    loop(n) cin >> a[i];
    vb near(n);
    near[n - 1] = true;
    for (int i = 1;i < n - 1;i++) {
      if (a[i] - a[i - 1] < a[i + 1] - a[i]) near[i] = true;
    }
    vi l(1), r(1);
    for (int i = 1;i < n;i++) {
      l.push_back(l.back() + (near[i] ? 1 : a[i] - a[i - 1]));
      r.push_back(r.back() + (near[i - 1] ? a[i] - a[i - 1] : 1));
    }
    int m;
    cin >> m;
    loop(m) {
      int a, b;
      cin >> a >> b;
      cout << (a < b ? r[b - 1] - r[a - 1] : l[a - 1] - l[b - 1]) << endl;
    }
  }
  return 0;
}

