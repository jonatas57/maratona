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
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, k;
    cin >> n >> k;
    vi a(n);
    vb used(n + 1, false);
    bool ok = true;
    for (int i = 0, j = n;i < k;i++) {
      if (2 * i + 1 >= n - 1) {
        ok = false;
        break;
      }
      used[j] = true;
      a[2 * i + 1] = j--;
    }
    for (int i = 0, j = 1;i < n;i += 2) {
      if (i and a[i - 1] == 0) break;
      used[j] = true;
      a[i] = j++;
    }
    for (int i = 0, j = 1;i < n;i++) {
      if (a[i] == 0) {
        while (j <= n and used[j]) j++;
        a[i] = j;
        used[j] = true;
      }
    }
    if (ok) {
      each(x, a) cout << x << " ";
      cout << endl;
    }
    else cout << -1 << endl;
  }
  return 0;
}

