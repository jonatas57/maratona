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
    vector<ll> a(n);
    loop(n) cin >> a[i];
    bool ok = n & 1;
    if (!ok) {
      ll b = 0;
      for (int i = 0;i < n - 1;i += 2) {
        b += a[i + 1] - a[i];
      }
      if (b >= 0) ok = true;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}

