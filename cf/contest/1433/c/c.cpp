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
    int ans = 0;
    bool ok = false;
    loop(n) {
      cin >> a[i];
      if (a[i] > a[ans]) ans = i;
    }
    for (int i = 0;!ok and i < n;i++) {
      if (a[i] != a[ans]) continue;
      if (i and a[i] > a[i - 1]) ok = true, ans = i;
      if (i < n - 1 and a[i] > a[i + 1]) ok = true, ans = i;
    }
    cout << (ok ? ans + 1 : -1) << endl;
  }
  return 0;
}

