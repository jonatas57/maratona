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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vi a(n);
    loop(n) cin >> a[i];
    sort(riter(a));
    ll g = a[0];
    for (int i = 1;i < n;i++) {
      int x = 0, pos = -1;
      for (int j = i;j < n;j++) {
        if (gcd(g, a[j]) > x) {
          x = gcd(g, a[j]);
          pos = j;
        }
      }
      if (pos != -1) {
        swap(a[i], a[pos]);
        g = x;
      }
    }
    each(x, a) cout << x << " ";
    cout << endl;
  }
  return 0;
}

